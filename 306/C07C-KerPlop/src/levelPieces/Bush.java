package levelPieces;

import gameEngine.Drawable;

//bush is only drawable does nothing
public class Bush implements Drawable {
	String name = "Bush";
	char symbol = 'B';
	int location;
	public Bush(int loc) {
		location = loc;
	}
	public int getLocation() {
		return location;
	}
	@Override
	public void draw() {
		System.out.print(symbol);
	}
}
