/* CSCI 261 Lab 5D: Array of Structures
 *
 * Author: Eli Billinger
 *
 * use struct to make a book variable and have an array storing the info for 5 different books.
 */
#include <iostream>
#include <string>
using namespace std;

struct Books{
    string title;
    string author;
    double cost;
    int year;
};

int main() {
    Books bookList[5];
    cout << "Enter the information for each book" << endl;
    for( int i =0; i< 5;i++){
        cout << "For Book " << i+1<< " Enter the Title: ";
        getline(cin, bookList[i].title);
        cout << "Enter the Author: ";
        getline(cin, bookList[i].author);
        cout << "Enter the Cost: ";
        cin >> bookList[i].cost;
        cin.ignore();
        cout << "Enter the Publication Year: ";
        cin >> bookList[i].year;
        cin.ignore();
    }
    cout << "What book would you like the information for? (1,2,3,4,or 5) ";
    int bookChoice;
    cin >> bookChoice;

    cout << "The information for book " << bookChoice <<" is:\nTitle: "<< bookList[bookChoice-1].title << endl;
    cout << "Author: "<<bookList[bookChoice-1].author << endl;
    cout << "Cost: " <<bookList[bookChoice-1].cost << endl;
    cout << "Publication Year: "<<bookList[bookChoice-1].year << endl;
    return 0;
}
