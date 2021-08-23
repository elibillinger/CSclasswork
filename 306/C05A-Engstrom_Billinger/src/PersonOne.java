// Goes through the list of questions or answers in order
public class PersonOne extends Person {

	public PersonOne(String myName, String Occupation) {
		super(myName, Occupation);
	}

	@Override
	public void askQuestion() {
		int counter = 0;
		String questions[] = {"How was your day?","Do you have a house?","Need to do any renovations?","Do you need anything built?"};
		if(counter !=3) {
			System.out.println(questions[counter]);
			counter++;
		} else {
			counter = 0;
		}
	}

	@Override
	public void answerQuestion() {
		int counter = 0;
		String answers[] = {"I am very happy","I am looking for work","I can do many things","I like to build things"};
		if(counter !=3) {
			System.out.println(answers[counter]);
			counter++;
		} else {
			counter = 0;
		}
	}

}
