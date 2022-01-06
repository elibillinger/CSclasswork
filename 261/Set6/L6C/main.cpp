/* CSCI 261 Lab 6C: Classes Part II: Construct a Godzilla
 *
 * Author: Eli Billinger
 *
 * USING 3 SKIP DAYS 2 REMAINING
 * Create a Pass by Value and Pass by Reference functions
 */
#include <iostream>
using namespace std;
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Godzilla{
public:
    Godzilla();
    void getName();
    void getHealth();
    void getPower();
    void print();

private:
    string name;
    double health;
    double power;
};
Godzilla::Godzilla() {
    name = "Godzilla";
    srand(time(0));
    rand();
    health = int((50) * ((double) rand() / (double) RAND_MAX) + 50);
    power = int((15) * ((double) rand() / (double) RAND_MAX) + 10);
}
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
    cout << name << " (P: " << power << ") - H: " << health;
}


int main() {
    Godzilla userMonster;
    userMonster.getName();
    userMonster.getHealth();
    userMonster.getPower();
    userMonster.print();
    Godzilla godzilla;
    cout << "\n";
    godzilla.print();
    return 0;
}
