// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Grid.h"
#include "Tile.h"
#include "Enemy.h"
#include <algorithm>
#include "SDL2_image/SDL_image.h"


Grid::Grid(class Game* game)
:Actor(game)
,_pSelectedTile(nullptr)
{
	// 7 rows, 16 columns
	_vecTiles.resize(NUM_ROWS);
	for (size_t i = 0; i < _vecTiles.size(); i++)
	{
		_vecTiles[i].resize(NUM_COLUMNS);
	}
	
	// Create tiles
	for (size_t i = 0; i < NUM_ROWS; i++)
	{
		for (size_t j = 0; j < NUM_COLUMNS; j++)
		{
			_vecTiles[i][j] = new Tile(GetGame());
			_vecTiles[i][j]->SetPosition(Vector2(TILE_SIZE/2.0f + j * TILE_SIZE, START_Y + i * TILE_SIZE));
		}
	}
	
	// Set start/end tiles
	GetStartTile()->SetTileState(Tile::EStart);
	GetEndTile()->SetTileState(Tile::EBase);
	
	// Set up adjacency lists
	for (size_t i = 0; i < NUM_ROWS; i++)
	{
		for (size_t j = 0; j < NUM_COLUMNS; j++)
		{
			if (i > 0)
			{
				_vecTiles[i][j]->_vecAdjacent.push_back(_vecTiles[i-1][j]);
			}
			if (i < NUM_ROWS - 1)
			{
				_vecTiles[i][j]->_vecAdjacent.push_back(_vecTiles[i+1][j]);
			}
			if (j > 0)
			{
				_vecTiles[i][j]->_vecAdjacent.push_back(_vecTiles[i][j-1]);
			}
			if (j < NUM_COLUMNS - 1)
			{
				_vecTiles[i][j]->_vecAdjacent.push_back(_vecTiles[i][j+1]);
			}
		}
	}
	
	// Find path (in reverse)
	FindPath(GetEndTile(), GetStartTile());
	_updatePathTiles(GetStartTile());
	
	_fNextEnemy = ENEMY_TIME;
}

void Grid::_selectTile(size_t row, size_t col)
{
	// Make sure it's a valid selection
	Tile::TileState tstate = _vecTiles[row][col]->GetTileState();
	if (tstate != Tile::EStart && tstate != Tile::EBase)
	{
		// Deselect previous one
		if (_pSelectedTile)
		{
			_pSelectedTile->ToggleSelect();
		}
		_pSelectedTile = _vecTiles[row][col];
		_pSelectedTile->ToggleSelect();
        if(tstate == Tile::EPath){
            _blockPath();
        }
	}
}

void Grid::ActorInput(const uint8_t *keyState) {
    // Process mouse
    int x, y;
    Uint32 buttons = SDL_GetMouseState(&x, &y);
    if (SDL_BUTTON(buttons) & SDL_BUTTON_LEFT) {
        _processClick(x, y);
    }
}

void Grid::_processClick(int x, int y)
{
	y -= static_cast<int>(START_Y - TILE_SIZE / 2);
	if (y >= 0)
	{
		x /= static_cast<int>(TILE_SIZE);
		y /= static_cast<int>(TILE_SIZE);
		if (x >= 0 && x < static_cast<int>(NUM_COLUMNS) && y >= 0 && y < static_cast<int>(NUM_ROWS))
		{
			_selectTile(y, x);
		}
	}
}

// Implements A* pathfinding
bool Grid::FindPath(Tile* start, Tile* goal)
{
    // Initialize entire _vecTiles grid to have _g of 0.0f,
    // _bInOpenSet to false, _bInClosedSet to false.
	for (size_t i = 0; i < NUM_ROWS; i++)
	{
		for (size_t j = 0; j < NUM_COLUMNS; j++)
		{
			_vecTiles[i][j]->_g = 0.0f;
			_vecTiles[i][j]->_bInOpenSet = false;
			_vecTiles[i][j]->_bInClosedSet = false;
		}
	}
	
    // Declare a vector of Tile pointers to be the open set.
	std::vector<Tile*> openSet;
	
	// Set current node to start, and add to closed set
	Tile* current = start;
	current->_bInClosedSet = true;
	
    // Loop until current is equal to goal.
	do
	{
        // For every Tile* in current's adjacency list.
		for (Tile* neighbor : current->_vecAdjacent)
		{
            // If this Tile is blocked, just continue.
			if (neighbor->_bBlocked)
			{
				continue;
			}
			
			// Only check nodes that aren't in the closed set
			if (!neighbor->_bInClosedSet)
			{
                // Only check nodes that aren't in the open set.

				if (!neighbor->_bInOpenSet)
				{
                    // Set next of this neighbor to current.
					neighbor->_pNext = current;
                    // Compute _h (heuristic) to be the magnitude of the neighbor's position minus the goal's position.
					neighbor->_h = (neighbor->GetPosition() - goal->GetPosition()).Length();
                    // Compute g(x) to be the next's g plus the cost of traversing
                    // this edge (just the TILESIZE).
                    neighbor->_g = current->_g + TILE_SIZE;
                    // Compute the f(x) to be _h + _g.
					neighbor->_f = neighbor->_g + neighbor->_h;
                    // Add this Tile to the open set.
					openSet.emplace_back(neighbor);
					neighbor->_bInOpenSet = true;
				}
				else
				{
					// Compute new g if current becomes next
					float newG = current->_g + TILE_SIZE;
					if (newG < neighbor->_g)
					{
						// Adopt this node
						neighbor->_pNext = current;
						neighbor->_g = newG;
						// f(x) changes because g(x) changes
						neighbor->_f = neighbor->_g + neighbor->_h;
					}
				}
			}
		}
		
		// If open set is empty, all possible paths are exhausted
		if (openSet.empty())
		{
			break;
		}
		
		// Find lowest cost node in open set
		auto iter = std::min_element(openSet.begin(), openSet.end(),
									 [](Tile* a, Tile* b) {
										 return a->_f < b->_f;
									 });
        // iter is the node with the lowest _f in the open set, make
        // this the new current and move it from open to closed.
		current = *iter;
		openSet.erase(iter);
		current->_bInOpenSet = false;
		current->_bInClosedSet = true;
	}
	while (current != goal);
	
	// Did we find a path?
	return (current == goal) ? true : false;
}

// Sets state of each tile in Grid, making
// ones on path look different from others.
void Grid::_updatePathTiles(class Tile* start)
{
	// Reset all tiles to normal (except for start/end)
	for (size_t i = 0; i < NUM_ROWS; i++)
	{
		for (size_t j = 0; j < NUM_COLUMNS; j++)
		{
			if (!(i == 3 && j == 0) && !(i == 3 && j == 15))
			{
				_vecTiles[i][j]->SetTileState(Tile::EDefault);
			}
		}
	}
	
	Tile* t = start->_pNext;
	while (t != GetEndTile())
	{
		t->SetTileState(Tile::EPath);
		t = t->_pNext;
	}
}

void Grid::_blockPath() {
    if (_pSelectedTile && !_pSelectedTile->_bBlocked)
    {
        _pSelectedTile->_bBlocked = true;
        if (!FindPath(GetEndTile(), GetStartTile()))
        {
            _pSelectedTile->_bBlocked = false;
            FindPath(GetEndTile(), GetStartTile());
        }
        _updatePathTiles(GetStartTile());
    }

}


Tile* Grid::GetStartTile()
{
	return _vecTiles[3][0];
}

Tile* Grid::GetEndTile()
{
	return _vecTiles[3][15];
}

void Grid::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	
	// Is it time to spawn a new enemy?
	_fNextEnemy -= deltaTime;
	if (_fNextEnemy <= 0.0f)
	{
		new Enemy(GetGame());
		_fNextEnemy += ENEMY_TIME;
	}
}
