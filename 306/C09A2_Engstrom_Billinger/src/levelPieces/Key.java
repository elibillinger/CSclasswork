package levelPieces;


import gameEngine.Drawable;
import gameEngine.InteractionResult;

public class Key extends GamePiece {
	
	public Key(int loc) {
		super('K',"Key",1);
		super.setLocation(loc);
	}

	@Override
	// Key is point piece collect 2 to advance levels
	public InteractionResult interact(Drawable[] gameBoard, int playerLocation) {
		if(playerLocation == this.getLocation()) {
			return InteractionResult.GET_POINT;
		} else {
			return InteractionResult.NONE;
		}
	}

}
