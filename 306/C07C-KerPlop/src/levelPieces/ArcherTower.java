package levelPieces;

import gameEngine.Drawable;
import gameEngine.InteractionResult;
import java.lang.Math;



public class ArcherTower extends GamePiece {
	public ArcherTower(int location) {
		super('A',"Archer Tower",location);
		super.setLocation(location);
	}
	@Override
	// Archer Tower hits player if they come within 2 spots of tower
	public InteractionResult interact(Drawable[] gameBoard, int playerLocation) {
		if(Math.abs(playerLocation-getLocation()) <=2 ) {
			return InteractionResult.HIT;
		} else {
			return InteractionResult.NONE;
		}
		
	}
}
