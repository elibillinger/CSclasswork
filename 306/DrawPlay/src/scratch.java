
public class scratch {
		
}




public class KnightsOfNi extends Knight{
	private int numShrubbery;
	private Sayings speech;

	public void KnightsOfNi(String name, int numShrubbery) {
		this.numShrubbery = numShrubbery;
		Knight knight = new Knight(name);
	}
	public boolean isNiAttack() {
		if(speech == Sayings.NI) {
			return true;
		} else {
			return false;
		}
	}
	@override
	public void displayStatus() {
		super.displayStatus();
		System.out.println("The knight has " + numShrubbery+" shrubbery.");
	}
}