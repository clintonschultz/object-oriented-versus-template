//
// Created by clinton schultz on 4/6/21.
//
#ifndef COMPARINGMETHODS_DROWNINGPOOL_H
#define COMPARINGMETHODS_DROWNINGPOOL_H

#include <iostream>

using namespace std;

class DrowningPool
{
public:
    static void bodiesHitTheFloor() {
        for (int i = 1; i <= 4; i++) {
            cout << i << ", nothin's wrong with me!" << endl;
        }
        for (int i = 1; i <= 4; i++) {
            cout << i << ", somethin's got to give!" << endl;
        }
        cout << "AAAAAAAAAAAAAAAHHHHHHHHH" << endl;
        for (int i = 1; i <= 8; i++) {
            cout << "LET THE BODIES HIT THE FLOOOOOR!" << endl;
        }
    }
};

#endif //COMPARINGMETHODS_COMPAREOOP_H