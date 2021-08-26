#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int adjMatrix[70][70];
string edge[70];
int cities;
int edges;


void addEdge(int i, int j){
    adjMatrix[i][j] = 1;
}

void createMatrix(){
    for( int i = 0; i< 70; i++){
        for ( int j = 0; j < 70; j++){
            string one = edge[i];
            string two = edge[j];
            if(one[2] == two[0]) {
                if (one.at(4) == two.at(4) || one.at(6) == two.at(6)) {
                    addEdge(i,j);
                }
            }
        }
    }
}

void displayMatrix(){
    for( int i = 0; i < 70; i++){
        for(int j = 0; j< 70; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

//DFS algorithm from https://www.geeksforgeeks.org/implementation-of-dfs-using-adjacency-matrix/
void DFS(int start,vector<bool> visited) {
    cout << edge[start].at(2) << " ";
    visited[start] = true;
    for (int i = 0; i < 70; i++) {
            if (adjMatrix[start][i] == 1 && (!visited[i])) {
                DFS(i, visited);
            }
        }
    }

int main() {
    ifstream input("MazeInput.txt");
    if (input.fail()) {
        cerr << "Could not open 'input.txt' " << endl;
    }
    input >> cities;
    input >> edges;
    int counter = 0;
    string temp;
    getline(input,temp);
    while(!input.eof()){
        string inputValue;
        getline(input,inputValue);
        edge[counter] = inputValue;
        counter++;
    }
    createMatrix();
    //displayMatrix();
    vector<bool> visited(36, false);
    cout << "A" << " ";
    DFS(0,visited);
    cout << "j";
    return 0;

}
