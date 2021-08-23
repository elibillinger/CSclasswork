// instance variables add to whatIDo() then repeat same question and answer
public class PersonThree extends Person {
	private String trait;
	public PersonThree(String myName, String Occupation, String trait) {
		super(myName, Occupation);
		this.trait = trait;
	}

	@Override
	public String toString() {
		return "PersonThree [trait=" + trait + "]";
	}
	

	@Override
	public void whatIDo() {
		super.whatIDo();
		System.out.println("I am very " + trait);
	}

	@Override
	public void askQuestion() {
		System.out.println("What are you doing here?");
	}

	@Override
	public void answerQuestion() {
		System.out.println("I am not answering that");
	}

}
