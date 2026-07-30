import java.util.Scanner;
class Book{
int id;
String name;
String author;
int quantity;
}
class lib {
Scanner sc = new Scanner(System.in);

Book b[] = new Book[100];
int totalBooks = 0;

void addBook() {
System.out.print("Enter number of books to add: ");
int n = sc.nextInt();
sc.nextLine();

for (int i = 0; i < n; i++) {
b[totalBooks] = new Book();

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
System.out.print("Books added successfully!");
}

void deleteBook() {
System.out.print("Enter book ID to delete: ");
int id = sc.nextInt();
sc.nextLine();

int found = 0;

for (int i = 0; i < totalBooks; i++) {
if (b[i].id == id) {
for (int j = i; j < totalBooks; j++) {
b[j] = b[j + 1];
}
totalBooks--;

found = 1;
System.out.println("Book deleted successfully!");
break;
}
}
if (found == 0) {
System.out.println("Book not found");
}
}

void updateBook() {
System.out.print("Enter book ID: ");
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
System.out.print("Book updated successfully!");
break;
}
}
if (found == 0) {
System.out.print("Book not found");
}
}

void displayBook() {
if (totalBooks == 0) {
System.out.print("No books available");
return;
}
System.out.println("ID\tName\tAuthor\tQuantity");
for (int i = 0; i < totalBooks; i++) {
System.out.println(b[i].id + "\t" + b[i].name + "\t" + b[i].author + "\t" + b[i].quantity);
}
}

void searchBook() {
System.out.println("Enter book ID: ");
int id = sc.nextInt();

int found = 0;

for (int i = 0; i < totalBooks; i++) {
if (b[i].id == id) {
System.out.println("Book found!");
System.out.println("Book name: " + b[i].name);
System.out.println("Book ID: " + b[i].id);
System.out.println("Author: " + b[i].author);
System.out.println("Quantity: " + b[i].quantity);

found = 1;
break;
}
}
if (found == 0) {
System.out.println("Book not found");
}
}

void returnBook() {
System.out.println("Enter book ID: ");
int id = sc.nextInt();

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
System.out.println("Book not found");
}
}
}
class Main{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
lib lb = new lib();
int ch;

do{
System.out.println("\n-----LIBRARY MANAGEMENT SYSTEM-----");
System.out.println("1. Add book, 2. Delete book, 3. Update book, 4. Search book, 5. Return book, 6. Exit program");
System.out.println("Enter your choice: ");
ch = sc.nextInt();

switch (ch){
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
System.out.println("Exiting...");
break;

default:
System.out.println("Invalid choice");
}
}
while (ch != 6);
sc.close();
}
}
