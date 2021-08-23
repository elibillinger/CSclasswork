import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
@SuppressWarnings("serial")

public class NegativeBalanceException extends Exception{

	public double negativeBalance;
	
	// default constructor 
	public NegativeBalanceException() {
		super("Error: negative balance");
	}
	
	// 1 parameter constructor that displays balance in error message
	public NegativeBalanceException(double negativeBalance) {
		super("Amount exceeds balance by " + negativeBalance);
		
		//print to logfile using printwriter
		try {
			FileWriter fileWriter = new FileWriter("C:\\Users\\Eli\\eclipse-workspace\\Exceptions\\logfile.txt");
			PrintWriter printWriter = new PrintWriter(fileWriter);
			printWriter.printf("Amount exceeds balance by " + negativeBalance);
			printWriter.close();
		} catch (IOException e) {
			System.out.println("Error in making file");
		}
	}

	@Override
	public String toString() {
		return "NegativeBalanceException [negativeBalance=" + negativeBalance + "]";
	}
	
}
