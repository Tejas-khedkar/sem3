#include <iostream>
using namespace std;

class Matrix {
private:
    int Mat[10][10];
    int rows, cols;

public:
    Matrix() {
        rows = 0;
        cols = 0;
    }

    void inputMatrix(const string& name = "Matrix") {
        cout << "\n--- Input " << name << " ---" << endl;
        cout << "Enter number of rows (max 10): ";
        cin >> rows;
        cout << "Enter number of columns (max 10): ";
        cin >> cols;

        if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10) {
            cout << "Invalid dimensions! Dimensions must be between 1 and 10." << endl;
            rows = 0;
            cols = 0;
            return;
        }

        cout << "Enter elements row by row (" << rows * cols << " total elements):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> Mat[i][j];
            }
        }
    }

    void display() {
        if (rows == 0 || cols == 0) {
            cout << "Matrix is empty!" << endl;
            return;
        }
        cout << "\nMatrix (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << Mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void add(Matrix m2) {
        if (rows == 0 || m2.rows == 0) {
            cout << "Error: One or both matrices are empty!" << endl;
            return;
        }
        if (rows != m2.rows || cols != m2.cols) {
            cout << "Error: Addition requires both matrices to have the exact same dimensions!" << endl;
            return;
        }

        cout << "\nResult of Matrix Addition:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << Mat[i][j] + m2.Mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void subtract(Matrix m2) {
        if (rows == 0 || m2.rows == 0) {
            cout << "Error: One or both matrices are empty!" << endl;
            return;
        }
        if (rows != m2.rows || cols != m2.cols) {
            cout << "Error: Subtraction requires both matrices to have the exact same dimensions!" << endl;
            return;
        }

        cout << "\nResult of Matrix Subtraction (Matrix 1 - Matrix 2):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << Mat[i][j] - m2.Mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void multiply(Matrix m2) {
        if (rows == 0 || m2.rows == 0) {
            cout << "Error: One or both matrices are empty!" << endl;
            return;
        }
        if (cols != m2.rows) {
            cout << "Error: For multiplication, columns of Matrix 1 (" << cols 
                 << ") must equal rows of Matrix 2 (" << m2.rows << ")!" << endl;
            return;
        }

        int result[10][10];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                result[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result[i][j] += Mat[i][k] * m2.Mat[k][j];
                }
            }
        }

        cout << "\nResult of Matrix Multiplication (" << rows << "x" << m2.cols << "):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                cout << result[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void transpose() {
        if (rows == 0 || cols == 0) {
            cout << "Matrix is empty!" << endl;
            return;
        }

        cout << "\nTranspose of Matrix (" << cols << "x" << rows << "):" << endl;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                cout << Mat[j][i] << "\t";
            }
            cout << endl;
        }
    }

    void displayUpperTriangular() {
        if (rows == 0 || cols == 0) {
            cout << "Matrix is empty!" << endl;
            return;
        }
        if (rows != cols) {
            cout << "Error: Upper triangular matrix can only be displayed for square matrices!" << endl;
            return;
        }

        cout << "\nUpper Triangular Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i <= j) {
                    cout << Mat[i][j] << "\t";
                } else {
                    cout << "0\t";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m1, m2;
    int choice;

    do {
        
        cout << "MATRIX OPERATIONS MENU     " << endl;
        
        cout << "1. Input First Matrix" << endl;
        cout << "2. Input Second Matrix" << endl;
        cout << "3. Display Matrices" << endl;
        cout << "4. Matrix Addition" << endl;
        cout << "5. Matrix Subtraction" << endl;
        cout << "6. Matrix Multiplication" << endl;
        cout << "7. Transpose of Matrix 1" << endl;
        cout << "8. Upper Triangular Matrix of Matrix 1" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                m1.inputMatrix("Matrix 1");
                break;
            case 2:
                m2.inputMatrix("Matrix 2");
                break;
            case 3:
                cout << "\n--- Matrix 1 ---";
                m1.display();
                cout << "\n--- Matrix 2 ---";
                m2.display();
                break;
            case 4:
                m1.add(m2);
                break;
            case 5:
                m1.subtract(m2);
                break;
            case 6:
                m1.multiply(m2);
                break;
            case 7:
                m1.transpose();
                break;
            case 8:
                m1.displayUpperTriangular();
                break;
            case 9:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please select a valid option." << endl;
        }
    } while (choice != 9);

    return 0;
}
