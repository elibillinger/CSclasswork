package levelPieces;

import gameEngine.Drawable;
import gameEngine.InteractionResult;

public class Teleporter extends GamePiece {
	
	public Teleporter(int loc) {
		super('T',"Teleporter",2);
		super.setLocation(loc);
	}

	@Override
	//Teleporter advances player to next level
	public InteractionResult interact(Drawable[] gameBoard, int playerLocation) {
		if(playerLocation == this.getLocation()) {
			return InteractionResult.ADVANCE;
		} else {
			return InteractionResult.NONE;
		}
	}

}
