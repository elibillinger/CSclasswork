
public class WriteReport {

	public WriteReport(String reportType, String name, long bill) {
		if (reportType.equalsIgnoreCase("CSV")) {
			System.out.println("CSV Report: " + name + "'s bill is " + bill);
		}
		if (reportType.equalsIgnoreCase("XML")) {
			System.out.println("XML Report: " + name + "'s bill is " + bill);
		}
	}
}
