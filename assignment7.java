package ass7;
import java.util.*;

public class Start {
    private static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println(" Inventory Management System");

        Collection<Product> inventory = selectStructure();
        InventoryOperations operations = new InventoryOperations(inventory);

        int choice;
        do {
            displayMenu();
            System.out.print("Enter your choice: ");
            choice = scan.nextInt();
            scan.nextLine();

            switch (choice) {
                case 1:
                    operations.addInventory();
                    break;
                case 2:
                    operations.deleteInventory();
                    break;
                case 3:
                    operations.updateInventory();
                    break;
                case 4:
                    operations.checkDuplicates();
                    break;
                case 5:
                    operations.normDisplay();
                    break;
                case 6:
                    operations.iterateDisplay();
                    break;
                case 7:
                    System.out.println("Exiting the program...");
                    break;
                default:
                    System.out.println("Invalid choice, please try again.");
            }
        } while (choice != 7);

        // Do not close System.in scanners manually to avoid NoSuchElementException
    }

    public static Collection<Product> selectStructure() {
        System.out.println("\nSelect a structure:");
        System.out.println("1. ArrayList");
        System.out.println("2. LinkedList");
        System.out.println("3. PriorityQueue");
        System.out.println("4. ArrayDeque");
        System.out.println("5. TreeSet");
        System.out.println("6. HashSet");
        System.out.print("Enter your choice: ");

        int choice = scan.nextInt();
        scan.nextLine();

        switch (choice) {
            case 1:
                System.out.println("Using ArrayList");
                return new ArrayList<>();
            case 2:
                System.out.println("Using LinkedList");
                return new LinkedList<>();
            case 3:
                System.out.println("Using PriorityQueue");
                return new PriorityQueue<>(Comparator.comparingInt(Product::getId));
            case 4:
                System.out.println("Using ArrayDeque");
                return new ArrayDeque<>();
            case 5:
                System.out.println("Using TreeSet");
                return new TreeSet<>(Comparator.comparingInt(Product::getId));
            case 6:
                System.out.println("Using HashSet");
                return new HashSet<>();
            default:
                System.out.println("Invalid choice. Defaulting to ArrayList.");
                return new ArrayList<>();
        }
    }

    public static void displayMenu() {
        System.out.println("\n--- Menu ---");
        System.out.println("1. Add");
        System.out.println("2. Remove");
        System.out.println("3. Update");
        System.out.println("4. Duplicate");
        System.out.println("5. Display");
        System.out.println("6. Iterate Display");
        System.out.println("7. Exit");
    }
}

class Product {
    private int id;
    private String category;
    private String name;
    private double price;
    private int quantity;

    public Product(int id, String category, String name, double price, int quantity) {
        this.id = id;
        this.category = category;
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public int getId() {
        return id;
    }

    public String getCategory() {
        return category;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    @Override
    public String toString() {
        return "ID: " + id + " | Category: " + category + " | Name: " + name +
                " | Price: " + price + " | Quantity: " + quantity;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Product product = (Product) obj;
        return id == product.id && Objects.equals(name, product.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, name);
    }
}

class InventoryOperations {
    private Collection<Product> inventory;
    private Scanner scan;
    private int nextId = 1;

    public InventoryOperations(Collection<Product> inventory) {
        this.inventory = inventory;
        this.scan = new Scanner(System.in);
    }

    public void addInventory() {
        System.out.println("\n--- Add New Item ---");
        System.out.print("Enter Item name: ");
        String name = scan.nextLine();

        System.out.print("Enter Item Category (Electronics/Groceries/Clothing): ");
        String category = scan.nextLine();

        System.out.print("Enter quantity: ");
        int quantity = scan.nextInt();
        System.out.print("Enter price: ");
        double price = scan.nextDouble();
        scan.nextLine();

        if (checkDuplicates(name)) {
            System.out.println("Item '" + name + "' already exists!");
            return;
        }

        Product product = new Product(nextId++, category, name, price, quantity);
        inventory.add(product);
        System.out.println("Item added successfully!");
    }

    public void deleteInventory() {
        System.out.println("\n--- Delete Item ---");
        System.out.print("Enter the name of the item to delete: ");
        String name = scan.nextLine();

        Product target = null;
        for (Product product : inventory) {
            if (product.getName().equalsIgnoreCase(name)) {
                target = product;
                break;
            }
        }

        if (target != null) {
            inventory.remove(target);
            System.out.println("Item '" + name + "' deleted successfully!");
        } else {
            System.out.println("Item '" + name + "' not found in inventory!");
        }
    }

    public void updateInventory() {
        System.out.println("\n--- Update Item ---");
        System.out.print("Enter the name of the item you want to edit: ");
        String name = scan.nextLine();

        Product target = null;
        for (Product product : inventory) {
            if (product.getName().equalsIgnoreCase(name)) {
                target = product;
                break;
            }
        }

        if (target == null) {
            System.out.println("Item '" + name + "' not found in inventory!");
            return;
        }

        System.out.println("Current details: " + target);

        System.out.print("Enter new category (press Enter to keep current): ");
        String category = scan.nextLine();
        if (!category.isEmpty()) {
            target.setCategory(category);
        }

        System.out.print("Enter new quantity (-1 to keep current): ");
        int quantity = scan.nextInt();
        if (quantity != -1) {
            target.setQuantity(quantity);
        }

        System.out.print("Enter new price (-1 to keep current): ");
        double price = scan.nextDouble();
        scan.nextLine();
        if (price != -1) {
            target.setPrice(price);
        }

        System.out.println("Item updated successfully!");
    }

    public boolean checkDuplicates(String name) {
        for (Product product : inventory) {
            if (product.getName().equalsIgnoreCase(name)) {
                return true;
            }
        }
        return false;
    }

    public void checkDuplicates() {
        System.out.println("\n--- Check Duplicate ---");
        System.out.print("Enter item name to check: ");
        String name = scan.nextLine();

        if (checkDuplicates(name)) {
            System.out.println("Duplicate found: '" + name + "' already exists.");
        } else {
            System.out.println("No duplicate found for '" + name + "'.");
        }
    }

    public void normDisplay() {
        System.out.println("\n--- Inventory Display ---");
        if (inventory.isEmpty()) {
            System.out.println("Inventory is empty!");
            return;
        }
        for (Product product : inventory) {
            System.out.println(product);
        }
    }

    public void iterateDisplay() {
        System.out.println("\n--- Inventory Display (Sorted by Name) ---");
        if (inventory.isEmpty()) {
            System.out.println("Inventory is empty!");
            return;
        }

        List<Product> sortedProducts = new ArrayList<>(inventory);
        sortedProducts.sort(Comparator.comparing(Product::getName));

        for (Product product : sortedProducts) {
            System.out.println(product);
        }
    }
}
