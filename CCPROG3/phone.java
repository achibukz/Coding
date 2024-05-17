
import java.util.Scanner;


public class Phone {
    private String brand;
    private String model;
    private int yearMade;
    private int price;

    public Phone(String brand, String model, int yearMade, int price){
        this.brand = brand;
        this.model = model;
        this.yearMade = yearMade;
        this.price = price;
    }

    public void changeBrand(String newBrand){
        this.brand = newBrand;
    }
    
    public void changeModel(String newModel){
        this.model = newModel;
    }

    public void changeYearMade(int newYear){
        this.yearMade = newYear;
    }

    public void changePrice(int newPrice){
        this.price = newPrice;
    }

    public String getBrand(){
        return brand;
    }

    public String getModel(){
        return model;
    }

    public int getYearMade(){
        return yearMade;
    }

    public int getPrice(){
        return price;
    }

    public void message(String message){
        blank();
        System.out.println("You: \n" + "  " + message);
        String textBack = "User 1: \n   Hello! I am busy right now so this is an automated \n   response! I will get back to you as soon as possible!";
        System.out.println(textBack);
        blank();
        
    }

    public void call(int number){
        blank();
        System.out.println("Calling " + number +  "...");
        System.out.println("Ringing....");
        System.out.println("User did not answer.....");
        blank();
    }

    public void blank(){
        System.out.println("--------------------------------------------------------");
    }
}


class Main {

    public static void sendMessage(Phone phone) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your message: ");
        String message = sc.nextLine();
        phone.message(message);
        sc.close();
    }
    
    public static void makeCall(Phone phone) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number you want to call: ");
        int number = sc.nextInt();
        phone.call(number);
        sc.close();
    }

    public static void displayDetails(Phone phone) {
        phone.blank();
        System.out.println("Phone Details: ");
        System.out.println("Brand: " + phone.getBrand());
        System.out.println("Model: " + phone.getModel());
        System.out.println("Year Made: " + phone.getYearMade());
        System.out.println("Price: " + phone.getPrice());
        phone.blank();

    }

    public static void main(String[] args) throws Exception {
        Phone phone1 = new Phone("Apple", "Iphone 15", 2023, 56990);

        Scanner sc = new Scanner(System.in);
        int choice;
        System.out.println("1. Send a message");
        System.out.println("2. Make a call");
        System.out.println("3. Display Details");
        System.out.println("4. Exit");
        System.out.print("Enter your choice: ");
        choice = sc.nextInt();
            
            switch (choice) {
                case 1 -> sendMessage(phone1);
                case 2 -> makeCall(phone1);
                case 3 -> displayDetails(phone1);
                case 4 -> System.out.println("Exiting...");
                default -> System.out.println("Invalid choice. Please enter 1, 2, or 3.");
            }
        
            sc.close();
       
    }


}
