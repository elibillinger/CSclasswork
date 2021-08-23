package tests;

import java.util.Set;

import org.junit.Assert;
import org.junit.Test;
import org.junit.jupiter.api.BeforeEach;

import clueGame.Board;
import clueGame.BoardCell;
import expirament.TestBoardCell;

class BoardAdjTargetTest {
	//creates a new testBoard called board
	Board Board;
	
	@BeforeEach //Run before each test
	public void setUp() {
		//board should create adjacency list
		Board = new Board();
	}
	
	//Location with only walkway
	@Test
	public void adjacencyWalkways() {
		BoardCell cell = Board.getCell(1, 1);
		Set<BoardCell> testList = cell.getAdjList();
		Assert.assertTrue(testList.contains(Board.getCell(0, 1)));
		Assert.assertTrue(testList.contains(Board.getCell(1, 0)));
		Assert.assertTrue(testList.contains(Board.getCell(2, 1)));
		Assert.assertTrue(testList.contains(Board.getCell(1, 2)));
		Assert.assertEquals(4, testList.size());
	}
	
	//Location within room not center
	@Test
	public void adjacencyCenterRoom() {
		BoardCell cell = Board.getCell(1, 1);
		Board.getCell(0, 1).setRoom(true);
		Board.getCell(1, 0).setRoom(true);
		Board.getCell(2, 1).setRoom(true);
		Board.getCell(1, 2).setRoom(true);
		Set<BoardCell> testList = cell.getAdjList();
		Assert.assertEquals(0, testList.size());
	}
	
	//Edge of board
	@Test
	public void adjacencyEdge() {
		BoardCell cell = Board.getCell(3, 1);
		Set<BoardCell> testList = cell.getAdjList();
		Assert.assertTrue(testList.contains(Board.getCell(3, 0)));
		Assert.assertTrue(testList.contains(Board.getCell(2, 1)));
		Assert.assertTrue(testList.contains(Board.getCell(3, 2)));
		Assert.assertEquals(3, testList.size());
	}
	
	//Location beside a room
	@Test
	public void besideRoom() {
		BoardCell cell = Board.getCell(1, 1);
		Board.getCell(0, 0).setRoom(true);
		Board.getCell(0, 1).setRoom(true);
		Board.getCell(0, 2).setRoom(true);
		Set<BoardCell> testList = cell.getAdjList();
		Assert.assertTrue(testList.contains(Board.getCell(1, 0)));
		Assert.assertTrue(testList.contains(Board.getCell(2, 1)));
		Assert.assertTrue(testList.contains(Board.getCell(1, 2)));
		Assert.assertEquals(3, testList.size());
	}
	
	//Locations that are doorways
	@Test
	public void adjacencyDoorway() {
		BoardCell cell = Board.getCell(1, 1);
		Board.getCell(0, 1).setDoorway(true);
		Set<BoardCell> testList = cell.getAdjList();
		Assert.assertTrue(testList.contains(Board.getCell(1, 0)));
		Assert.assertTrue(testList.contains(Board.getCell(2, 1)));
		Assert.assertTrue(testList.contains(Board.getCell(1, 2)));
		Assert.assertTrue(testList.contains(Board.getCell(0, 1)));
		Assert.assertEquals(4, testList.size());
	}
	
	//Locations connected by secret passage
	@Test
	public void adjacencySecret() {
		BoardCell cell = Board.getCell(1, 1);
		Board.getCell(0, 1).setSecretPassage('k');
		Set<BoardCell> testList = cell.getAdjList();
		Assert.assertTrue(testList.contains(Board.getCell(1, 0)));
		Assert.assertTrue(testList.contains(Board.getCell(2, 1)));
		Assert.assertTrue(testList.contains(Board.getCell(1, 2)));
		Assert.assertTrue(testList.contains(Board.getCell(0, 1)));
		Assert.assertEquals(4, testList.size());
	}
	
	//Tests targets along walkways
	@Test
	public void targetsWalkway() {
		//roll of 7
		BoardCell cell = Board.getCell(1, 1);
		Set<BoardCell> targets = Board.getTargets();
		Board.calcTargets(cell, 7);
		Assert.assertEquals(7, targets.size());
		Assert.assertTrue(targets.contains(Board.getCell(1, 3)));
		Assert.assertTrue(targets.contains(Board.getCell(3, 3)));
		Assert.assertTrue(targets.contains(Board.getCell(3, 1)));
		Assert.assertTrue(targets.contains(Board.getCell(1, 1)));
		Assert.assertTrue(targets.contains(Board.getCell(0, 0)));
		Assert.assertTrue(targets.contains(Board.getCell(2, 0)));
		Assert.assertTrue(targets.contains(Board.getCell(0, 2)));
		
		//roll of 1
		Board.calcTargets(cell, 1);
		Assert.assertEquals(4, targets.size());
		Assert.assertTrue(targets.contains(Board.getCell(1, 2)));
		Assert.assertTrue(targets.contains(Board.getCell(2, 1)));
		Assert.assertTrue(targets.contains(Board.getCell(0, 1)));
		Assert.assertTrue(targets.contains(Board.getCell(1, 0)));
	}
	
	//Test entering a room
	@Test
	public void targetsEnterRoom() {
		Board.getCell(1, 2).setRoom(true);
		BoardCell cell = Board.getCell(0, 3);
		Board.calcTargets(cell, 3);
		Set<BoardCell> targets = Board.getTargets();
		Assert.assertEquals(3, targets.size());
		Assert.assertTrue(targets.contains(Board.getCell(1, 2)));
		Assert.assertTrue(targets.contains(Board.getCell(2, 2)));
		Assert.assertTrue(targets.contains(Board.getCell(3, 3)));
	}
	
	//Test leaving room without secret passage 
	public void targetsLeavingRoom() {
		Board.getCell(1, 2).setRoom(true);
		BoardCell cell = Board.getCell(1, 2);
		Board.calcTargets(cell, 3);
		Set<BoardCell> targets = Board.getTargets();
		Assert.assertEquals(0, targets.size());
	}
	
	//Tests leaving room with secret passage
	public void targetsLeavingRoomSecret() {
		Board.getCell(1, 2).setRoom(true);
		BoardCell cell = Board.getCell(1, 2);
		Board.calcTargets(cell, 3);
		Set<BoardCell> targets = Board.getTargets();
		Assert.assertEquals(0, targets.size());
	}
	
	//Tests reflexes from other players blocking
	public void targetsBlocking() {
		Board.getCell(1, 2).setOccupied(true);
		Board.getCell(2, 1).setOccupied(true);
		Board.getCell(1, 0).setOccupied(true);
		Board.getCell(0, 1).setOccupied(true);
		BoardCell cell = Board.getCell(1, 1);
		Board.calcTargets(cell, 3);
		Set<BoardCell> targets = Board.getTargets();
		Assert.assertEquals(0, targets.size());
	}
}
