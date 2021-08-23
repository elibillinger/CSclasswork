package levelPieces;

import java.util.ArrayList;
import gameEngine.Drawable;
import gameEngine.GameEngine;
import gameEngine.Moveable;


public class LevelSetup {
	private Drawable[] board = new Drawable[GameEngine.BOARD_SIZE];
	private ArrayList<Moveable> movablePieces;
	private ArrayList<GamePiece> movePieces;
	private ArrayList<GamePiece> interactPieces;
	private ArrayList<Bush> drawOnly;
	
	public LevelSetup() {
		//Initialize Array Lists
		movePieces = new ArrayList<GamePiece>();
		interactPieces = new ArrayList<GamePiece>();
		drawOnly = new ArrayList<Bush>();
		movablePieces = new ArrayList<Moveable>();
	}
	

	public void createLevel(int levelNum) {
		// initalize blank board
		for(int i = 0; i < GameEngine.BOARD_SIZE; i++) {
			board[i] = null;
		}
		System.out.println("Level " + levelNum);
		//implement different number of pieces and placement based on the level number
		if(levelNum == 1) {
			interactPieces.add(new Teleporter(0));
			interactPieces.add(new ArcherTower(20));
			interactPieces.add(new Key(18));
			interactPieces.add(new Key(7));
			movePieces.add(new Wolf(2));
			drawOnly.add(new Bush(1));
			drawOnly.add(new Bush(5));
			
			
		} else if(levelNum == 2) {
			interactPieces.add(new Teleporter(0));
			interactPieces.add(new ArcherTower(1));
			interactPieces.add(new Key(18));
			interactPieces.add(new Key(7));
			movePieces.add(new Wolf(2));
			movePieces.add(new Wolf(17));
			movePieces.add(new Murderer(20));
			drawOnly.add(new Bush(3));
			drawOnly.add(new Bush(13));
		}
	}

	public Drawable[] getBoard() {
		//Adds pieces to the board
		for( GamePiece p : interactPieces) {
			board[p.getLocation()] = p;
		}
		for( GamePiece p : movePieces) {
			board[p.getLocation()] = p;
		}
		for( Bush b : drawOnly) {
			board[b.getLocation()] = b;
		}
		return board;
	}

	public ArrayList<Moveable> getMovingPieces() {
		for(GamePiece p: movePieces) {
			movablePieces.add((Moveable) p);
		}
		return movablePieces;
	}

	public ArrayList<GamePiece> getInteractingPieces() {
		return interactPieces;
	}

	public int getPlayerStartLoc() {
		return GameEngine.BOARD_SIZE/2;
	}
	
	
}
