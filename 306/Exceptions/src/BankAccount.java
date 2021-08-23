
public class BankAccount {

	private double balance;

	//constructor to set the balance
	public BankAccount(double balance) {
		super();
		this.balance = balance;
	}
	
	// withdraw that amount using the 1 parameter exception from NegativeBalanceException
	public void withdraw(double withdrawAmount) throws NegativeBalanceException {
		if( withdrawAmount > balance) {
			throw new NegativeBalanceException(balance-withdrawAmount);
		} else {
			balance = balance-withdrawAmount;
		}
	}
	
	// withdraw that amount using the default exception from NegativeBalanceException
	public void quickWithdraw(double withdrawAmount) throws NegativeBalanceException{
		if( withdrawAmount > balance) {
			throw new NegativeBalanceException();
		} else {
			balance = balance-withdrawAmount;
		}
	}
}
