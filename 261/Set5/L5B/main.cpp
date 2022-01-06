/* CSCI 261 Lab 5B: Matrix Transposition
 *
 * Author: Eli Billinger
 *
 * using 2D arrays to transpose a matrix
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int ROWS = 4;
    const int COLUMNS = 3;
    int matrixOriginal[ROWS][COLUMNS];

    cout << "Welcome to the Matrix Transpose Calculator! "<< endl;
    cout << "Please enter a " << ROWS <<"x"<< COLUMNS<< " matrix"<<endl;
    // ask user for values of matrix and fill in array with values
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLUMNS;j++){
            int matrixValue;
            cout << "Enter Row "<<i+1<< " Column " << j+1<<": ";
            cin >> matrixValue;
            matrixOriginal[i][j] = matrixValue;
        }
    }
    cout << "The matrix you entered is:" << endl;
    // output original array in format
    for(int i=0;i<ROWS;i++){
        cout <<"[ ";
        for(int j=0;j<COLUMNS;j++){
            cout << setw(4)<< right <<matrixOriginal[i][j] << " ";
        }
        cout << "]" << endl;
    }
    // transpose matrix
    int transposeMatrix[COLUMNS][ROWS];
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLUMNS;j++){
            transposeMatrix[j][i] = matrixOriginal[i][j];
        }
    }
    cout << "\n The transpose of the matrix is:" << endl;
    // output new matrix
    for(int i=0;i<COLUMNS;i++){
        cout <<"[ ";
        for(int j=0;j<ROWS;j++){
            cout << setw(4)<< right <<transposeMatrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
