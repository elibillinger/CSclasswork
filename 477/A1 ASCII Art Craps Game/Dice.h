//
// Created by Eli Billinger on 1/14/22.
//

#ifndef A1_DICE_H
#define A1_DICE_H
class Dice {
public:
    void RollDice();
    int Point = 0;
    int DiceRoll;

private:
    int Dice1;
    int Dice2;
    void GenerateDiceRolls();
    void DrawDice(int dice1, int dice2);
    void DrawDiceLineTop(int roll);
    void DrawDiceLineMiddle(int roll);
    void DrawDiceLineBottom(int roll);
};
#endif //A1_DICE_H
