//Abstract Person Class which asks for name gives name and occupation
abstract class Person {
	private String myName;
	private String Occupation;

	public Person(String myName, String Occupation) {
		super();
		this.myName = myName;
		this.Occupation = Occupation;
	}

	@Override
	public String toString() {
		return "Person [myName=" + myName + ", Occupation=" + Occupation + "]";
	}

	public void askName() {
		System.out.println("What is your name?");
	}
	public void giveName() {
		System.out.println("My name is " + myName);
	}
	public void whatIDo() {
		System.out.println("I am a " + Occupation);
	}
	public abstract void askQuestion();
	public abstract void answerQuestion();

}



