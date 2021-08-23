package tests;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import gameEngine.Drawable;
import gameEngine.GameEngine;
import gameEngine.InteractionResult;
import levelPieces.*;

class TestInteractions {

	/*
	 * Test for Tower hit when player is within 2 spaces
	 * put tower at space 2 and see if it is detected on same space as tower
	 * and on the 2 spaces on either side of the tower pieces
	 * All other spaces should have no interaction
	 */
	@Test
	void testArcherTower() {
		Drawable [] gameBoard = new Drawable[GameEngine.BOARD_SIZE];
		ArcherTower tower = new ArcherTower(2);
		gameBoard[2] = tower;
		// All spaces from 5 to end of board should have no interaction
		for (int i=5; i<GameEngine.BOARD_SIZE; i++) {
			assertEquals(InteractionResult.NONE, tower.interact(gameBoard, i));
		}
		//test for hit on spaces 0-4
		for (int i=0; i<5; i++) {
			assertEquals(InteractionResult.HIT, tower.interact(gameBoard, i));
		}
	}
	/*
	 * Test if key gives point on interaction
	 * Place key at space 0 
	 * Should get point at space 0 and have no interaction for all other spaces
	 */
	
	@Test
	void testKey() {
		Drawable [] gameBoard = new Drawable[GameEngine.BOARD_SIZE];
		Key key = new Key(0);
		gameBoard[0] = key;
		//test for get point at space 0 where key is placed
		assertEquals(InteractionResult.GET_POINT,key.interact(gameBoard, 0));
		//Check for no interaction for remaining locations on board
		for (int i=1; i<GameEngine.BOARD_SIZE; i++) {
			assertEquals(InteractionResult.NONE, key.interact(gameBoard, i));
		}
	}
	
	/*
	 * Test if murderer kills when on same space as player
	 * Put wolf at space 0
	 * Should kill at space 0 and have no interaction for all other spaces
	 */
	@Test
	void testMurderer() {
		Drawable [] gameBoard = new Drawable[GameEngine.BOARD_SIZE];
		Murderer m = new Murderer(0);
		gameBoard[0] = m;
		//test for kill at space 0 where murderer is placed
		assertEquals(InteractionResult.KILL,m.interact(gameBoard, 0));
		//Check for no interaction for remaining locations on board
		for (int i=1; i<GameEngine.BOARD_SIZE; i++) {
			assertEquals(InteractionResult.NONE, m.interact(gameBoard, i));
		}
		
	}
	
	/*
	 * Test if teleporter advances on interaction
	 * Place teleporter at space 0 
	 * Should advance at space 0 and have no interaction for all other spaces
	 */
	@Test
	void testTeleporter() {
		Drawable [] gameBoard = new Drawable[GameEngine.BOARD_SIZE];
		Teleporter teleporter = new Teleporter(0);
		gameBoard[0] = teleporter;
		//test for advance at space 0 where teleporter is placed
		assertEquals(InteractionResult.ADVANCE,teleporter.interact(gameBoard, 0));
		//Check for no interaction for remaining locations on board
		for (int i=1; i<GameEngine.BOARD_SIZE; i++) {
			assertEquals(InteractionResult.NONE, teleporter.interact(gameBoard, i));
		}
	}
	
	/*
	 * Test if wolf hits when on same space as player
	 * Put wolf at space 0
	 * Should hit at space 0 and have no interaction for all other spaces
	 */
	@Test
	void testWolf() {
		Drawable [] gameBoard = new Drawable[GameEngine.BOARD_SIZE];
		Wolf w = new Wolf(0);
		gameBoard[0] = w;
		//test for hit at space 0 where wolf is
		assertEquals(InteractionResult.HIT,w.interact(gameBoard, 0));
		//Check for no interaction for remaining locations on board
		for (int i=1; i<GameEngine.BOARD_SIZE; i++) {
			assertEquals(InteractionResult.NONE, w.interact(gameBoard, i));
		}
	}

}
