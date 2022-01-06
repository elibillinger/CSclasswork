/* CSCI 261 Lab 7A: Classes Part III: Godzilla vs Mechagodzilla
 *
 * Author: Eli Billinger
 *
 * Updating L6C to simulate fight between monsters
 * USING 1 SKIP DAY 1 REMAINING
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
    Godzilla(string monsterName, double monsterHealth, double monsterPower);
    void attack(Godzilla userMonster);
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
Godzilla::Godzilla(string monsterName, double monsterHealth, double monsterPower) {
    name = monsterName;
    health = monsterHealth;
    power = monsterPower;
}
void Godzilla::attack(Godzilla userMonster){
    cout  <<name << " attacks " << userMonster.name << "."<< endl;
    userMonster.health = userMonster.health - power;
    if(userMonster.health > 0){
        while (health > 0) {
            cout << userMonster.name << " attacks " << name  << "."<< endl;
            health = health - userMonster.power;
        }
        cout << name << " has be vanquished. " << endl;
    }
}

void Godzilla::print(){
    cout << name << " (P: " << power << ") - H: " << health << endl;
}


int main() {
    // get information for users monster info
    string name;
    double power, health;
    cout << "Enter the name: ";
    getline(cin, name);
    cout << "Enter the health: ";
    cin >> health;
    cout << "Enter the power: ";
    cin >> power;
    Godzilla userMonster(name,health,power);
    userMonster.print();
    Godzilla godzilla;
    godzilla.print();
    godzilla.attack(userMonster);
    return 0;
}
