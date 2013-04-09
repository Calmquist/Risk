#include <iostream>
#include <time.h>
#include <vector>

#include "DiceRoll.h"
#include "Sorter.h"
#include "get_int.h"

using namespace std;

Sorter mySorter;

DiceRoll::DiceRoll() {

}

namespace atk {
    int roll;
}

namespace def {
    double roll;
}

int DiceRoll::GetDefArmies(int D) {
    if (D > 1)
        def::roll = 2;
    else if (D == 1)
        def::roll = 1;
    return def::roll;
}

int DiceRoll::GetAtkArmies(int A) {
    do {
        cout << "How Many Units is the Attacker using?: ";
        do {
        cout << "How Many Units is the Attacker using?: ";
        atk::roll = get_int();
        if(atk::roll == INT_MIN) {
            \cout << "You did not input a number, try again." << endl;
        }

        else if (atk::roll >= A) {
            if ((atk::roll - A) <= 0) {
                cout << "Sorry, there needs to be at least one left. Try again." << endl;
                continue;
            } else {
                cout << "Sorry, you do not have enough. Try Again " << endl;
                continue;
            }
        } else
            break;
    } while (true);

    return atk::roll;
}


int DiceRoll::Roll(int atk, int def) {
    vector<int> aroll;
    vector<int> droll;
    srand (time(NULL));
    for (size_t i = 0; i < atk; ++i)
        aroll.push_back ((rand() % 6)+1);
    cout << "Attacker Rolls: " << aroll << endl;

    for (size_t i = 0; i < def; ++i)
        droll.push_back ((rand() % 6)+1);
    cout << "Defenders Rolls: " << droll << endl;

    return mySorter.asorter(aroll, droll);
}
