#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int ISBN;
    string Name;
    string Auth;
    string Publisher;
    float Price;

public:
    
    int getISBN() const { return ISBN; }
    string getName() const { return Name; }
    string getAuth() const { return Auth; }
    string getPublisher() const { return Publisher; }
    float getPrice() const { return Price; }

    void display() const {
        cout << ISBN << "\t" << Name << "\t" << Auth << "\t" << Price << "\t" << Publisher << endl;
    }
    
    void input() {
        cout << "\nEnter book name: ";
        cin >> Name;
        cout << "Enter ISBN: ";
        cin >> ISBN;
        cout << "Enter Author name: ";
        cin >> Auth;
        cout << "Enter publisher name: ";
        cin >> Publisher;
        cout << "Enter price: ";
        cin >> Price; 
    }
};


void swapBooks(Book &a, Book &b) {
    Book temp = a;
    a = b;
    b = temp;
}


void sortByISBN(Book b[], int totalBooks) {
    for (int i = 0; i < totalBooks - 1; i++) {
        for (int j = 0; j < totalBooks - i - 1; j++) {
            if (b[j].getISBN() > b[j + 1].getISBN()) {
                swapBooks(b[j], b[j + 1]);
            }
        }
    }
}

// Bubble sort by Price
void sortByPrice(Book b[], int totalBooks) {
    for (int i = 0; i < totalBooks - 1; i++) {
        for (int j = 0; j < totalBooks - i - 1; j++) {
            if (b[j].getPrice() > b[j + 1].getPrice()) {
                swapBooks(b[j], b[j + 1]);
            }
        }
    }
}


void ISBNsearch(Book b[], int totalBooks) {
    if (totalBooks == 0) {
        cout << "No books available to search.\n";
        return;
    }
    
    sortByISBN(b, totalBooks);

    int target;
    cout << "Enter ISBN to search: ";
    cin >> target;

    int low = 0, high = totalBooks - 1;
    bool found = false;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (b[mid].getISBN() == target) {
            cout << "\nBook Found:\n";
            cout << "ISBN\tName\tAuthor\tPrice\tPublisher\n";
            b[mid].display();
            found = true;
            break;
        } else if (b[mid].getISBN() < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Book with ISBN " << target << " not found.\n";
    }
}


void nameSearch(Book b[], int totalBooks) {
    if (totalBooks == 0) {
        cout << "No books available to search.\n";
        return;
    }

    string target;
    cout << "Enter Book Name to search: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < totalBooks; i++) {
        if (b[i].getName() == target) {
            if (!found) {
                cout << "\nBook(s) Found:\n";
                cout << "ISBN\tName\tAuthor\tPrice\tPublisher\n";
            }
            b[i].display();
            found = true;
        }
    }

    if (!found) {
        cout << "No book found with name \"" << target << "\".\n";
    }
}


void authorSearch(Book b[], int totalBooks) {
    if (totalBooks == 0) {
        cout << "No books available to search.\n";
        return;
    }

    string target;
    cout << "Enter Author Name to search: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < totalBooks; i++) {
        if (b[i].getAuth() == target) {
            if (!found) {
                cout << "\nBook(s) Found:\n";
                cout << "ISBN\tName\tAuthor\tPrice\tPublisher\n";
            }
            b[i].display();
            found = true;
        }
    }

    if (!found) {
        cout << "No books found by author \"" << target << "\".\n";
    }
}


void publisherSearch(Book b[], int totalBooks) {
    if (totalBooks == 0) {
        cout << "No books available to search.\n";
        return;
    }

    string target;
    cout << "Enter Publisher Name to search: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < totalBooks; i++) {
        if (b[i].getPublisher() == target) {
            if (!found) {
                cout << "\nBook(s) Found:\n";
                cout << "ISBN\tName\tAuthor\tPrice\tPublisher\n";
            }
            b[i].display();
            found = true;
        }
    }

    if (!found) {
        cout << "No books found from publisher \"" << target << "\".\n";
    }
}


void priceSearch(Book b[], int totalBooks) {
    if (totalBooks == 0) {
        cout << "No books available to search.\n";
        return;
    }

    sortByPrice(b, totalBooks);

    float target;
    cout << "Enter Price to search: ";
    cin >> target;

    int low = 0, high = totalBooks - 1;
    bool found = false;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (b[mid].getPrice() == target) {
            cout << "\nBook Found:\n";
            cout << "ISBN\tName\tAuthor\tPrice\tPublisher\n";
            b[mid].display();
            found = true;
            break;
        } else if (b[mid].getPrice() < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "No book found with price " << target << ".\n";
    }
}


void searchMenu(Book b[], int totalBooks) {
    int action;
    cout << "\n1. Search by ISBN";
    cout << "\n2. Search by book name";
    cout << "\n3. Search by author name";
    cout << "\n4. Search by publisher name";
    cout << "\n5. Search by price\n";
    cout << "Enter your choice: ";
    cin >> action;

    switch (action) {
        case 1:
            ISBNsearch(b, totalBooks);
            break;
        case 2:
            nameSearch(b, totalBooks);
            break;
        case 3:
            authorSearch(b, totalBooks);
            break;
        case 4:
            publisherSearch(b, totalBooks);
            break;
        case 5:
            priceSearch(b, totalBooks);
            break;
        default:
            cout << "Invalid search choice.\n";
    }
}

int main() {
    Book b[50];
    int action;
    int totalBooks = 0;

    do {
        cout << "\n1. Add book";
        cout << "\n2. Search book";
        cout << "\n3. Display all books";
        cout << "\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> action;

        switch (action) {
            case 1:
                if (totalBooks < 50) {
                    b[totalBooks].input();
                    totalBooks++;
                } else {
                    cout << "Library capacity reached! or invalid input\n";
                }
                break;
            case 2:
                searchMenu(b, totalBooks);
                break;
            case 3:
                if (totalBooks == 0) {
                    cout << "\nNo books available.\n";
                } else {
                    cout << "\nSr No. \tISBN \tName \tAuthor \tPrice \tPublisher\n";
                    for (int i = 0; i < totalBooks; i++) {
                        cout << i + 1 << "\t";
                        b[i].display();
                    }
                }
                break;
            case 4:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "\nInvalid input\n";
        }
    } while (action != 4);

    return 0;
}
