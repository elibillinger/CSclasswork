import java.awt.Point;
public class StringPlay {
	public static void main(String[] args) {
		String cPlus = "C++ is cool";
		String java = "I love Java";
		String combined = cPlus.replace("C++", java.substring(7));
		System.out.println(combined);
		
		Point a = new Point(1,2);
		Point b = new Point(1,2);
		System.out.println(a == b);
		System.out.println(a.equals(b));
		
		String one = "test string";
		String two = "Test String";
		System.out.println(one == two);
		System.out.println(one.equals(two));
		System.out.println(one.equalsIgnoreCase(two));
	}
}
