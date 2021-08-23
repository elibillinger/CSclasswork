package tests;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import gameEngine.Drawable;
import gameEngine.GameEngine;
import levelPieces.*;

class TestMovingPieces {

	/*
	 * Test Random Movement of the Wolf piece
	 * -Fill every other space with a bush making the remaining spaces free
	 * -Count the number of times each space is chosen when it is run 300 times to determine
	 * if it is chosen randomly
	 * Based on example test in write up for random movement
	 */
	@Test
	void testWolfMovement() {
		Drawable [] gameBoard = new Drawable[GameEngine.BOARD_SIZE];
		Wolf wolf = new Wolf(2);
		gameBoard[2] = wolf;
		//put bush in every other space starting at space 1
		for( int i = 1; i < GameEngine.BOARD_SIZE; i+=2) {
			gameBoard[i] = new Bush(i);
		}
		// Initialize counters
		int count0 = 0, count2 = 0, count4 = 0,count6 = 0,count8 = 0,count10 = 0,count12 = 0,count14 = 0,count16 = 0,count18 = 0,count20 = 0;
		// Call move 300 times and increase counter corresponding to space
		for( int i = 0; i < 300; i++) {
			wolf.move(gameBoard, 10);
			int location = wolf.getLocation();
			if (location % 2 != 0) {
				fail("Invalid space selected");
			}
			//increase counters
			if (location == 0) count0++;
			if (location == 2) count2++;
			if (location == 4) count4++;
			if (location == 6) count6++;
			if (location == 8) count8++;
			if (location == 10) count10++;
			if (location == 12) count12++;
			if (location == 14) count14++;
			if (location == 16) count16++;
			if (location == 18) count18++;
			if (location == 20) count20++;
		}
		// Check to see if each space is chose 5 or more times
		assert(count0 >= 5);
		assert(count2 >= 5);
		assert(count4 >= 5);
		assert(count6 >= 5);
		assert(count8 >= 5);
		assert(count10 >= 5);
		assert(count12 >= 5);
		assert(count14 >= 5);
		assert(count16 >= 5);
		assert(count18 >= 5);
		assert(count20 >= 5);
	}
	
	/*
	 * Test Murderer moves 1-2 spaces to the left
	 * Murderer starts at space 20 and only moves down(left) the board until it reaches space 0 then it teleports to space 20
	 *  -Fail if it moves more than 2 spaces or to the right
	 *  -Fill in a few spaces to force it to move 2 spaces
	 */
	@Test
	void testMurdererMovement() {
		Drawable [] gameBoard = new Drawable[GameEngine.BOARD_SIZE];
		Murderer m = new Murderer(20);
		gameBoard[20] = m;
		//added 2 bushes to force 2 space movement
		gameBoard[4] = new Bush(4);
		gameBoard[14] = new Bush(14);
		//call movement 20 times to ensure it reaches the end of the board and goes back to top
		int previousLocation = 20;
		for( int i = 0; i < 20; i++) {
			m.move(gameBoard, 10);
			int location = m.getLocation();
			System.out.println(location);
			if( previousLocation - location > 2) {
				fail("Moved more than 2 spaces");
			}
			previousLocation = location;
		}
	}
}
