package levelPieces;

import gameEngine.Drawable;
import gameEngine.Moveable;
import gameEngine.InteractionResult;
import java.util.Random;

//Wolf pieces moves randomly and hits player when the player is near by
public class Wolf extends GamePiece implements Moveable{
	Random rand = new Random();
	public Wolf(int location) {
		super('W',"Wolf",location);
		super.setLocation(location);
	}

	@Override
	// Wolf hits player if player is within 2 spots
	public InteractionResult interact(Drawable[] gameBoard, int playerLocation) {
		if(playerLocation == getLocation() ) {
			return InteractionResult.HIT;
		} else {
			return InteractionResult.NONE;
		}
		
	}
	
	@Override
	//Wolf moves to a random open space
	public void move(Drawable[] gameBoard, int playerLocation) {
		int r = rand.nextInt(21);
		if(gameBoard[r] == null) {
			gameBoard[r] = gameBoard[getLocation()];
			gameBoard[getLocation()] = null;
			setLocation(r);
		} else {
			move(gameBoard,playerLocation);
		}
		
	}

}
