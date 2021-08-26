
#include "tictactoe.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    //auto start = system_clock::now(); //timer start used for write up
    tic_tac_toe game; //initialize class
    game.generate_boards(); // call to generate boards
    game.output(); // call to print required output

    // timer used for write up
//    auto stop = system_clock::now();
//    auto diff = duration_cast<nanoseconds>(stop - start);
//    double seconds = diff.count() / 1.0e9;
//    cout << seconds << " seconds." << endl;
    return 0;
}
