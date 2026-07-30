import java.util.Scanner;

class Book {
    int id;
    String name;
    String author;
    int quantity;
}

class Library {
    Scanner sc;
    Book[] b = new Book[100];
    int totalBooks = 0;

    // Pass the scanner instance from main
    Library(Scanner sc) {
        this.sc = sc;
    }

    void addBook() {
        System.out.print("Enter number of books to add: ");
        int n = sc.nextInt();
        sc.nextLine(); // Clear buffer

        if (totalBooks + n > b.length) {
            System.out.println("Cannot add " + n + " books. Array capacity exceeded (Max 100 books).");
            return;
        }

        for (int i = 0; i < n; i++) {
            b[totalBooks] = new Book();

            System.out.println("\n--- Book " + (i + 1) + " ---");
            System.out.print("Enter book ID: ");
            b[totalBooks].id = sc.nextInt();
            sc.nextLine();

            System.out.print("Enter book name: ");
            b[totalBooks].name = sc.nextLine();

            System.out.print("Enter author name: ");
            b[totalBooks].author = sc.nextLine();

            System.out.print("Enter quantity: ");
            b[totalBooks].quantity = sc.nextInt();
            sc.nextLine();

            totalBooks++;
        }
        System.out.println("Books added successfully!");
    }

    void deleteBook() {
        System.out.print("Enter book ID to delete: ");
        int id = sc.nextInt();
        sc.nextLine();

        int found = 0;

        for (int i = 0; i < totalBooks; i++) {
            if (b[i].id == id) {
                // FIXED: Outer bound prevents ArrayIndexOutOfBoundsException
                for (int j = i; j < totalBooks - 1; j++) {
                    b[j] = b[j + 1];
                }
                b[totalBooks - 1] = null; // Clear dangling reference
                totalBooks--;

                found = 1;
                System.out.println("Book deleted successfully!");
                break;
            }
        }
        if (found == 0) {
            System.out.println("Book not found!");
        }
    }

    void updateBook() {
        System.out.print("Enter book ID to update: ");
        int id = sc.nextInt();
        sc.nextLine();

        int found = 0;

        for (int i = 0; i < totalBooks; i++) {
            if (b[i].id == id) {
                System.out.print("Enter new book name: ");
                b[i].name = sc.nextLine();

                System.out.print("Enter new author name: ");
                b[i].author = sc.nextLine();

                found = 1;
                System.out.println("Book updated successfully!");
                break;
            }
        }
        if (found == 0) {
            System.out.println("Book not found!");
        }
    }

    void searchBook() {
        System.out.print("Enter book ID: ");
        int id = sc.nextInt();
        sc.nextLine(); // Clear buffer

        int found = 0;

        for (int i = 0; i < totalBooks; i++) {
            if (b[i].id == id) {
                System.out.println("\nBook Found!");
                System.out.println("ID: " + b[i].id);
                System.out.println("Name: " + b[i].name);
                System.out.println("Author: " + b[i].author);
                System.out.println("Quantity: " + b[i].quantity);

                found = 1;
                break;
            }
        }
        if (found == 0) {
            System.out.println("Book not found!");
        }
    }

    void returnBook() {
        System.out.print("Enter book ID: ");
        int id = sc.nextInt();
        sc.nextLine(); // Clear buffer

        int found = 0;

        for (int i = 0; i < totalBooks; i++) {
            if (b[i].id == id) {
                b[i].quantity++;
                System.out.println("Book returned successfully!");
                System.out.println("Available quantity: " + b[i].quantity);

                found = 1;
                break;
            }
        }
        if (found == 0) {
            System.out.println("Book not found!");
        }
    }

    void displayBook() {
        if (totalBooks == 0) {
            System.out.println("No books available in the library.");
            return;
        }
        System.out.println("\nID\tName\tAuthor\tQuantity");
        System.out.println("------------------------------------");
        for (int i = 0; i < totalBooks; i++) {
            System.out.println(b[i].id + "\t" + b[i].name + "\t" + b[i].author + "\t" + b[i].quantity);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Library lb = new Library(sc); // Shared scanner
        int ch;

        do {
            System.out.println("\n----- LIBRARY MANAGEMENT SYSTEM -----");
            System.out.println("1. Add Book");
            System.out.println("2. Delete Book");
            System.out.println("3. Update Book");
            System.out.println("4. Search Book");
            System.out.println("5. Return Book");
            System.out.println("6. Display All Books");
            System.out.println("7. Exit Program");
            System.out.print("Enter your choice: ");

            ch = sc.nextInt();
            sc.nextLine(); // Clear buffer

            switch (ch) {
                case 1:
                    lb.addBook();
                    break;
                case 2:
                    lb.deleteBook();
                    break;
                case 3:
                    lb.updateBook();
                    break;
                case 4:
                    lb.searchBook();
                    break;
                case 5:
                    lb.returnBook();
                    break;
                case 6:
                    lb.displayBook();
                    break;
                case 7:
                    System.out.println("Exiting program... Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (ch != 7);

        sc.close();
    }
}
