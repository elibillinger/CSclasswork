import java.util.Random;
//chooses a random question and a random answer
public class PersonTwo extends Person {

	public PersonTwo(String myName, String Occupation) {
		super(myName, Occupation);
	}

	@Override
	public void askQuestion() {
		String questions[] = {"Where do you live?","What do you do in your spare time?","Do you like video games?","Do you have any pets?"};
		Random randNum = new Random();
		int num = randNum.nextInt(4);
		System.out.println(questions[num]);
	}

	@Override
	public void answerQuestion() {
		String answers[] = {"I live in California","I like to play video games","My favorite gmae is Minecraft","I stream on Twitch"};
		Random randNum = new Random();
		int num = randNum.nextInt(4);
		System.out.println(answers[num]);
	}

}
