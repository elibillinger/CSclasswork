package levelPieces;

import gameEngine.Drawable;
import gameEngine.InteractionResult;
import gameEngine.Moveable;
import java.util.Random;

public class Murderer extends GamePiece implements Moveable{
	Random rand = new Random();
	public Murderer(int location) {
		super('M',"Murderer",location);
		super.setLocation(location);
	}

	@Override
	// Kill Player if they are in the same space
	public InteractionResult interact(Drawable[] gameBoard, int playerLocation) {
		if(playerLocation== getLocation()) {
			return InteractionResult.KILL;
		} else {
			return InteractionResult.NONE;
		}
	}
	
	@Override
	// Murderer moves left 1-2 blocks starting at the far right Once it reaches the end it teleports to space 20 and continues
	public void move(Drawable[] gameBoard, int playerLocation) {
		int r = rand.nextInt(3);
		if(getLocation() > 1) {
			if(gameBoard[getLocation()-r] == null ) {
				gameBoard[getLocation()-r] = gameBoard[getLocation()];
				gameBoard[getLocation()] = null;
				setLocation(getLocation()-r);
			} else move(gameBoard,playerLocation);
		} else {
		 if(getLocation() == 1){
			gameBoard[getLocation()-1] = gameBoard[getLocation()];
			gameBoard[getLocation()] = null;
			setLocation(getLocation()-1);
		}  else if(getLocation() == 0){
			gameBoard[0] = null;
			setLocation(20);
		}
	}
	}
}
		
		
		
		
		

