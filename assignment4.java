import java.util.Scanner;

public class Main {
    
    public static void main(String []args){
        // Car execution
        Car c = new Car();
        c.start();
        c.getSpeed();
        System.out.println("Maintenance performed: " + c.performMaintenance());
        c.stop();
        System.out.println();
        
        // Bus execution
        Bus b = new Bus();
        b.start();
        b.getSpeed();
        System.out.println("Maintenance performed: " + b.performMaintenance());
        b.stop();
        System.out.println();

        // Motorcycle execution
        Motercycle m = new Motercycle();
        m.start();
        m.getSpeed();
        System.out.println("Maintenance performed: " + m.performMaintenance());
        m.stop();
    }
}

interface Vehicle {
    void start();
    void stop();
    void getSpeed();
}

interface Maintenance {
    int handlingCharges = 500;
    boolean performMaintenance();
}

class Car implements Vehicle, Maintenance {
    Scanner scan = new Scanner(System.in);
    int speed;

    public void start() {
        System.out.println("start car");
    }

    public void stop() {
        System.out.println("stop car");
    }

    public void getSpeed() {
        System.out.print("Enter speed: ");
        speed = scan.nextInt();
        System.out.println("Current speed: " + speed + " km/h");
    }

    public boolean performMaintenance() {
        System.out.println("Applying handling charges: $" + handlingCharges);
        return true;
    }
}

class Bus implements Vehicle, Maintenance {
    Scanner scan = new Scanner(System.in);
    int speed;

    public void start() {
        System.out.println("start bus");
    }

    public void stop() {
        System.out.println("stop bus");
    }

    public void getSpeed() {
        System.out.print("Enter bus speed: ");
        speed = scan.nextInt();
        System.out.println("Bus speed: " + speed + " km/h");
    }

    public boolean performMaintenance() {
        System.out.println("Bus maintenance charge added: $" + handlingCharges);
        return true;
    }
}

class Motercycle implements Vehicle, Maintenance {
    Scanner scan = new Scanner(System.in);
    int speed;

    public void start() {
        System.out.println("start motorcycle");
    }

    public void stop() {
        System.out.println("stop motorcycle");
    }

    public void getSpeed() {
        System.out.print("Enter motorcycle speed: ");
        speed = scan.nextInt();
        System.out.println("Motorcycle speed: " + speed + " km/h");
    }

    public boolean performMaintenance() {
        System.out.println("Motorcycle service fee: $" + handlingCharges);
        return true;
    }
}
