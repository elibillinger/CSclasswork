/* CSCI 261 Lab 6B: Classes Part I: Get, Set, Go-Go-Godzilla
 *
 * Author: Eli Billinger
 *
 * USING 3 SKIP DAYS 2 REMAINING
 * Create a Pass by Value and Pass by Reference functions
 */
#include <iostream>
#include <string>
using namespace std;

class Godzilla{
public:
    void getName();
    void getHealth();
    void getPower();
    void print();

private:
    string name;
    double health;
    double power;
};
void Godzilla::getName(){
    cout << "Enter the name: ";
    getline(cin, name);
}
void Godzilla::getHealth(){
    cout << "Enter the health: ";
    cin >> health;

}
void Godzilla::getPower(){
    cout << "Enter the power: ";
    cin >> power;
}
void Godzilla::print(){
    cout << name << " has " << health << " health and " << power << " power.";
}

int main() {
    Godzilla godzilla;
    godzilla.getName();
    godzilla.getHealth();
    godzilla.getPower();
    godzilla.print();
    return 0;
}
