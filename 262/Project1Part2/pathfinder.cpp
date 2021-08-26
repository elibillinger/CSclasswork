/*
    pathfinder.cpp
        
    Method implementations for the pathfinder class.
    
    assignment: CSCI 262 Project - Pathfinder        

    author: Eli Billinger
*/

#include <iostream>
#include <fstream>
#include "pathfinder.h"

using namespace std;

// constructor - optional, in case you need to initialize anything
pathfinder::pathfinder() { ; }

// public run() method - invokes private methods to do everything;
// returns the total elevation change cost of the best optimal path.
int pathfinder::run(string data_file_name, string save_file_name, bool use_recursion) {
    // suggested implementation - modify as desired!
    _use_recursion = use_recursion;
    if (!_read_data(data_file_name)) {
        cout << "Error reading map data from \"" << data_file_name << "\"!" << endl;
        return -1;
    }

    _draw_map();

    int best_cost = _draw_paths();

    _save_image(save_file_name);

    return best_cost;
}

/*******************/
/* PRIVATE METHODS */
/*******************/

// _read_data - read and store width, height, and elevation data from the
// provided data file; return false if something goes wrong
bool pathfinder::_read_data(string data_file_name) {
    ifstream elevation_file(data_file_name);
    string ncols; // strings to store string in file
    string nrows;
    elevation_file >> ncols >> _width >> nrows >> _height;
    _elevations = vector<vector<int>>(_height, vector<int>(_width)); // set vector size to size of data (from assignment instruc)
    for( int i = 0; i < _height; i++){
        for ( int j = 0; j < _width; j++){
            elevation_file >>_elevations[i][j];
        }
    }
    elevation_file.close();
    return true;
}

// _draw_map - draw the elevation data as grayscale values on our Picture
// object.



void pathfinder::_draw_map() {
    int max = _elevations[0][0]; // initalize at first value at vector for min and max
    int min = _elevations[0][0];
    for( int i = 0; i < _height; i++){        //loop through vector and compare to find max and min
        for ( int j = 0; j < _width; j++){
            if(_elevations[i][j] < min){
                min = _elevations[i][j];
            }
            if(_elevations[i][j] > max){
                max = _elevations[i][j];
            }
        }
    }
    double diff = max-min;
    double scale = (255)/(diff);
    int offset = (-1*min)*(255-0)/(int (diff)) + 0;
    _image.set(_height - 1, _width -1, 0, 0, 0);
    for( int i = 0; i < _height; i++) {
        for (int j = 0; j < _width; j++) {
            int gray = int (_elevations[i][j] * scale) + offset;
            _image.set(i, j, gray, gray, gray);
        }
    }
}

// _draw_paths() - find and draw optimal paths from west to east using either recursion or dynamic programming
// return the best optimal path cost

int pathfinder::_draw_paths() {

    if(_use_recursion) {
        vector<int> final_costs;
        final_costs.reserve(_height);
        int lowest_cost = 1e9;

        for (int i = 0; i < _height; i++) {
            final_costs.push_back(_cost_east(i, 0));
        }
        for (int final_cost : final_costs) {
            if (final_cost < lowest_cost) {
                lowest_cost = final_cost;
            }
        }
        cout << "The optimal cost is: " << lowest_cost;
    } else {
        _costs = vector<vector<int>>(_height, vector<int>(_width));
        _direction = vector<vector<int>>(_height, vector<int>(_width));
        for( int j = _width-1; j >= 0; j--) {
            for (int i = _height-1; i >= 0; i--) {
                _costs_directions(i,j);
            }
        }
    }
    for (int i = 0; i < _height; i++){
            _color_paths(i,0,0,0,255);
    }
    int lowest_cost = 1e9,best_row;
    for ( int i = 0; i < _height; i++){
       if( _costs[i][0] < lowest_cost){
           lowest_cost = _costs[i][0];
           best_row = i;
       }
    }
    _color_paths(best_row,0,255,255,0);
    cout << "The cost for the best path is: " << lowest_cost;
    return 0;
}
void pathfinder::_color_paths(int row, int col, int r, int g, int b) {
    if(col<_width){
        _image.set(row,col,r,g,b);
        _color_paths(row+_direction[row][col],col+1,r,g,b);
    }
}

int pathfinder::_cost_east(int row, int col) {
    int cost_up, cost_down, cost_straight, cost = 0;
    if(col == _width-1){
        cost_up = 0;
        cost_down = 0;
        cost_straight = 0;
    } else {
        cost_straight = abs(_elevations[row][col] - _elevations[row][col+1]) + _cost_east(row, col + 1);
        if(row < _height-1){
            cost_down = abs(_elevations[row][col] - _elevations[row+1][col+1]) + _cost_east(row+1, col + 1);
        } else{
            cost_down = 1e9;
        }
        if(row > 0){
            cost_up = abs(_elevations[row][col] - _elevations[row-1][col+1]) + _cost_east(row-1, col + 1);
        } else {
            cost_up = 1e9;
        }
    }
    if(cost_straight< cost_up && cost_straight < cost_down){
        cost += cost_straight;
        return cost;
    } else if(cost_down< cost_up && cost_down < cost_straight){
        cost += cost_down;
        return cost;
    } else {
        cost += cost_up;
        return cost;
    }
}

void pathfinder::_costs_directions(int row, int col) {
    int cost_up = 0, cost_down = 0, cost_straight = 0;
    if(col == _width-1){
        _costs[row][col] = 0;
    } else {
        cost_straight = abs(_elevations[row][col] - _elevations[row][col+1]) + _costs[row][col+1];
        if (row < _height-1) {
            cost_down = abs(_elevations[row][col] - _elevations[row+1][col+1]) + _costs[row+1][col+1];
        } else {
            cost_down = 1e9;
        }
        if (row > 0) {
            cost_up = abs(_elevations[row][col] - _elevations[row-1][col+1]) + _costs[row-1][col+1];
        } else {
            cost_up = 1e9;
        }
    }
    if(cost_straight< cost_up && cost_straight < cost_down){
        _costs[row][col] = cost_straight;
        _direction[row][col] = 0; // 0 equals east
    } else if(cost_down< cost_up && cost_down < cost_straight){
        _costs[row][col] = cost_down;
        _direction[row][col] = 1; // 1 equals south east
    } else if (cost_up< cost_down && cost_up < cost_straight){
        _costs[row][col] = cost_up;
        _direction[row][col] = -1; // -1 equals north east
    } else if(cost_up == cost_straight || cost_down == cost_straight){
        _costs[row][col] = cost_straight;
        _direction[row][col] = 0; // 0 equals east
    } else if (cost_down == cost_up){
        _costs[row][col] = cost_up;
        _direction[row][col] = -1; // -1 equals north east
    }
}
// _save_image - we'll do this one for you :)
void pathfinder::_save_image(string save_file_name) {
    _image.save(save_file_name);
}