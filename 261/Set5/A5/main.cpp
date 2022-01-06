/* CSCI 261 Lab A5: PPM Image Editor
 *
 * Author: Eli Billinger
 *
 * created program to read a ppm file than manipulate it with grayscale or inverting the color
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// struct for all data for each pixel
struct Pixel {
    int red;
    int green;
    int blue;
};

int main() {
    string filename;
    cout << "Enter a file name ";
    getline(cin, filename);
    ifstream imageFile(filename + ".ppm");
    // check if error in opening
    if(imageFile.fail()){
        cerr << "Error in opening file";
        return -1;
    }
    // reading the file and put data into image vector
    string fileType;
    int width, height, max;
    vector< vector< Pixel > > image;
    imageFile >> fileType >> width >> height >> max;
    for( int i=0; i<height; i++) {
        vector<Pixel> row;
        for( int j=0; j<width; j++){
            Pixel pixel;
            imageFile >> pixel.red >> pixel.green >> pixel.blue;
            row.push_back(pixel);
        }
        image.push_back(row);
    }
    // Close file
    imageFile.close();
    // Ask user for Manipulation and make sure they enter correct value
    int userChoice;
    cout << "Enter your choice for manipulation (1 or 2) \n1. Grayscale\n2. Invert" << endl;
    cin >> userChoice;
    // set variables based on choice

    if(userChoice == 1){
        ofstream newFile (filename + "_grayscale.ppm");

        newFile << fileType << endl;
        newFile << width <<" " << height << endl;
        newFile << max << endl;
        for( int i=0; i<height; i++) {
            for (int j = 0; j < width; j++) {
                int gray = 0.2989 * image[i][j].red + 0.5870 * image[i][j].green + 0.1140 * image[i][j].blue;
                newFile << gray << " " << gray << " " << gray;
                if (j != width - 1) {
                    newFile << "\t";
                }
                newFile << "\n";
            }
        }

    } else if(userChoice == 2){
        ofstream newFile (filename + "_inverted.ppm");

        newFile << fileType << endl;
        newFile << width <<" " << height << endl;
        newFile << max << endl;
        for( int i=0; i<height; i++) {
            for (int j = 0; j < width; j++) {
                newFile << max - image[i][j].red << " " << max - image[i][j].green << " " << max - image[i][j].blue;
                if (j != width - 1) {
                    newFile << "\t";
                }
                newFile << "\n";
            }
        }

    }
    return 0;
}
