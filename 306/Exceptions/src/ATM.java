
public class ATM {
	
	private BankAccount bankAccount = new BankAccount(500);

	public void handleTransactions() throws NegativeBalanceException {
		// complete transaction using withdraw from BankAccount
		try {
			bankAccount.withdraw(600);
		} catch(NegativeBalanceException e) {
			System.out.println(e);
			System.out.println(e.getMessage());
		}
		// complete transaction using quick withdraw from BankAccount
		try {
			bankAccount.quickWithdraw(600);
		} catch(NegativeBalanceException e) {
			System.out.println(e);
			System.out.println(e.getMessage());
		}
	}
	
	// main creates object and calls handleTransactions
	public static void main(String[] args) throws NegativeBalanceException{
		ATM atm = new ATM();
		atm.handleTransactions();
	}
}
