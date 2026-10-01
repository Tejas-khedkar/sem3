import java.util.ArrayList;
import java.util.Scanner;
//code written by me
//but now i am bored

public class start 
{

	public static void main(String[] args) {
		
		InventoryOperations IO = new InventoryOperations();
		IO.addInventory();
		}
}

class InventoryOperations{
	Scanner scan = new Scanner(System.in);
	ArrayList<InventoryOperations> inventory = new ArrayList<>();
	
	void Item(int id, String category, String name, int quantity, double price) 
	{
		this.category = category;
		this.name = name;
		this.quantity = quantity;
		this.id = id;
		this.price = price;
		
	}
	
	
	
	String category;
	String name;
	int quantity;
	double price;
	int id;
	
	String searchName;
	
	void addInventory() {
		System.out.println("Enter Item name: ");
		name = scan.nextLine();
		System.out.println("Enter Item Catagory: ");
		category = scan.nextLine();
		System.out.println("Enter quantity: ");
		quantity = scan.nextInt();
		System.out.println("Enter price: ");
		price = scan.nextDouble();
		
		
	}
	
	void deleteInventory() {
		//search and delete the item from inventory with the default deletion function
	}
	
	void updateInventory() {
		System.out.println("Enter the name of the item you want to edit: ");
		searchName = scan.nextLine();
		//search the name, then take inputs to update
		//else say searchName isn't found in the list
		
		
	}
	//void checkDuplicates();
	void normDisplay() {
		//something along the lines of:
		
		System.out.println(category + " | " + name + " | Quantity = " + quantity + " | Price: " + price );
	}
	//void iterateDisplay();
}
