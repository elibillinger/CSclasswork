import java.util.Scanner;
public class Station {
	static int lastBadgeNumber = 0;
	int maxDetective = 5;
	int numOfDetectives = 0;
	String stationName;
	Detective[] detectiveList = new Detective[maxDetective];
	Scanner sc = new Scanner(System.in);
	
	public Station(String stationName) {
		super();
		this.stationName = stationName;
	}
	
	// print detective list
	void printDetectiveLists() {
		for (int i = 0; i < maxDetective; i++) {
			if(detectiveList[i] != null)
			System.out.println(detectiveList[i]);
		}
		return;
	}
	
	// hire if able to 
	void hire(String s) {
		if(numOfDetectives < maxDetective) {
			System.out.print("New hire for " + s + "... Enter Detective's name: ");

			String name = sc.nextLine();
			lastBadgeNumber++;
			int badge = lastBadgeNumber;
			Detective newHire = new Detective(badge, name);

			detectiveList[numOfDetectives] = newHire;
			numOfDetectives++;
		} else {
			System.out.println("Can't hire any more detectives for " + s);
		}
		return;	
	}
}
