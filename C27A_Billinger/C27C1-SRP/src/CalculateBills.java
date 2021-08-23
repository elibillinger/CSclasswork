import java.util.ArrayList;

public class CalculateBills {
	long bill;

	public CalculateBills(long tax, ArrayList<Item> listsOfItems) {
		for (Item item : listsOfItems) {
			bill += item.getPrice();
		}
		bill += tax;
		this.setBill(bill);
	}
	
	public long getBill() {
		return bill;
	}

	public void setBill(long bill) {
		this.bill = bill;
	}
}
