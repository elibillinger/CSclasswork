
public class PublicSafety {
	String cityName;
	String UniversityName;
	
	public PublicSafety(String universityName, String cityName) {
		super();
		this.cityName = cityName;
		UniversityName = universityName;
		
	}
	Station City = new Station(UniversityName);
	Station University = new Station(cityName);
	// tell station to print detective list
	void printDetectiveLists() {
		City.printDetectiveLists();
		University.printDetectiveLists();
	}
	//hire function
	void doHire(boolean hire) {
		if (hire) {
			City.hire(cityName);
		}
		else {
			University.hire(UniversityName);
		}
		return;
	}
}


