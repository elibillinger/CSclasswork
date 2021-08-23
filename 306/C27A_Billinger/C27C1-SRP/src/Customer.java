
import java.util.ArrayList;

public class Customer {

	String name;
	int age;
	long bill;
	ArrayList<Item> listsOfItems;

	Customer(String name, int age) {
		this.name = name;
		this.age = age;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public ArrayList<Item> getListsOfItems() {
		return listsOfItems;
	}

	public void setListsOfItems(ArrayList<Item> listsOfItems) {
		this.listsOfItems = listsOfItems;
	}

	public static void main(String[] args) {
		ArrayList<Item> items = new ArrayList<Item>();

		items.add(new Item(25));
		items.add(new Item(45));

		Customer fred = new Customer("Fred", 25);
		fred.setListsOfItems(items);
		CalculateBills fredBill = new CalculateBills(10,fred.getListsOfItems());
		WriteReport fredReport = new WriteReport("CSV","Fred",fredBill.getBill());
		
		Customer karen = new Customer( "Karen", 30 ) ;
		items.clear() ;
		items.add(new Item(10));
		items.add(new Item(10));
		karen.setListsOfItems(items);
		CalculateBills karenBill = new CalculateBills(20,karen.getListsOfItems());
		WriteReport karenReport = new WriteReport("XML","Karen",karenBill.getBill());
		

	}

}