/*
 * Eli Billinger
 * 
 * TreeMap - when using a tree map the each entry is sorted based on the name
 * 			this makes the output go in alphabetic order while the HashMap was not when it outputed the same values
 * 
 * Map error - Cannot instantiate the type Map<String,Integer>
 * 			I believe that this error is caused because there is not type of just Map which is why you must choose a hash or tree map.
 */


import java.util.*;

public class MapCollection {
	private Map<String, Integer> mapCourses;
	
	public MapCollection() {
		mapCourses = new HashMap<String, Integer>();
	}
	
	//loop to get student name and favorite course and add to map until the user quits
	public void GetCourse() {
		Scanner in = new Scanner(System.in);
		String name = "";
		int course;
		do 
		{
			System.out.print("Enter the student name or Q to quit: ");
			name = in.next();
			if ((name.equalsIgnoreCase("Q")))
				break;	
			System.out.print("Enter the course number: ");
			course = in.nextInt();
			mapCourses.put(name, course);
		} while (!(name.equalsIgnoreCase("Q")));
	}
	
	//print map from https://mkyong.com/java/how-to-loop-a-map-in-java/
	public void PrintStudentCourses() {
		for ( Map.Entry<String, Integer> entry : mapCourses.entrySet()) {
			System.out.println(entry.getKey() + " likes " + entry.getValue());
		}
	}
	
	public static void main(String[] args) {
		MapCollection map = new MapCollection();
		map.GetCourse();
		map.PrintStudentCourses();
		
	}
}
