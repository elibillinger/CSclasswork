
public class Detective {
	int badgeNum;
	String Name;
	
	//Constructor 
	public Detective(int badgeNum, String name) {
		super();
		this.badgeNum = badgeNum;
		Name = name;
	}

	@Override
	public String toString() {
		return "Detective [Badge=" + badgeNum + ", Name=" + Name + "]";
	}
}
