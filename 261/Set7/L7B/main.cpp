/* CSCI 261 Lab 7B: Classes Part IV: Validate Godzilla
 *
 * Author: Eli Billinger
 *
 * Updating L7A to validate
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
    void checkPower();
    void checkHealth();
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
    checkPower();
    checkHealth();
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
    } else{
        cout << userMonster.name << " has be vanquished." << endl;
    }
}

void Godzilla::print(){
    cout << name << " (P: " << power << ") - H: " << health << endl;
}

void Godzilla::checkPower() {
    if(power < 10 || power > 25){
        srand(time(0));
        rand();
        power = int((15) * ((double) rand() / (double) RAND_MAX) + 10);
    }
}

void Godzilla::checkHealth() {
    if(health < 0){
        health = 0;
    }
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
