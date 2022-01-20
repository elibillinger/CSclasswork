//
// Created by Eli Billinger on 1/14/22.
//

#include "Dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

//public function to determine rolls and draw dice
void Dice::RollDice() {
    GenerateDiceRolls();
    DrawDice(Dice1,Dice2);
}

//randomly generate the dice rolls
void Dice::GenerateDiceRolls() {
    if(Point == 0){
        srand(time(0));
    }
    Dice1 = rand() % 6 + 1;
    Dice2 = rand() % 6 + 1;
    if(Point == 0){
        Point = Dice1 + Dice2;
    }
    DiceRoll = Dice1 + Dice2;
}

//print out the dice to cout
void Dice::DrawDice(int dice1, int dice2) {
    std::cout << "-----  -----" << std::endl;
    //Draw Top Line for Both Dice
    DrawDiceLineTop(dice1);
    std::cout << "  ";
    DrawDiceLineTop(dice2);
    std::cout << std::endl;
    //Draw Middle Line for Both Dice
    DrawDiceLineMiddle(dice1);
    std::cout << "  ";
    DrawDiceLineMiddle(dice2);
    std::cout << std::endl;
    //Draw Bottom Line For Both Dice
    DrawDiceLineBottom(dice1);
    std::cout << "  ";
    DrawDiceLineBottom(dice2);
    std::cout << std::endl;
    std::cout << "-----  -----" << std::endl;
}

// draws the top row of the dice
void Dice::DrawDiceLineTop(int roll) {
    if(roll > 1) {
        std::cout << "|o ";
        if(roll > 3) {
            std::cout << "o|";
        } else {
            std::cout << " |";
        }
    } else {
        std:: cout << "|   |";
    }
}

//draws the middle line of the dice
void Dice::DrawDiceLineMiddle(int roll) {
    if(roll % 2 != 0) {
        std::cout << "| o |";
    } else if (roll == 6) {
        std:: cout << "|o o|";
    } else {
        std:: cout << "|   |";
    }
}

//draws the bottom line of the dice
void Dice::DrawDiceLineBottom(int roll) {
    if(roll > 3) {
        std::cout << "|o ";
    } else {
        std::cout << "|  ";
    }
    if(roll > 1) {
        std::cout << "o|";
    } else {
        std:: cout << " |";
    }
}

