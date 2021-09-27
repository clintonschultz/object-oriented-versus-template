#include <iostream>
#include <string>
#include <chrono>
#include <stdlib.h>
#include <vector>

#include "Template.cpp"

using namespace std;
using namespace std::chrono;

void fillIntVector(vector<IntWrapper2 *> &v) {

    cout << "fillIntVector called." << endl;

    for (int i = 0; i <= 10000; i++) {
        v.push_back(new IntWrapper2(rand() % 1000));
    }
}

void fillStringVector(vector<StringWrapper2 *> &v) {

    cout << "fillStringVector called." << endl;

    string tmp_s;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    srand(time(NULL));

    int len = 4;
    tmp_s.reserve(len);

    for (int i = 0; i <= 10000; i++) {
        len = rand() % 4 + 1;
        tmp_s = "";
        for (int j = 0; j < len; ++j) {
            tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
        }
        v.push_back(new StringWrapper2(tmp_s));
    }
}

void printIntVector(vector<IntWrapper2*> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << "Element " << i << ": " << v[i]->getVal() << endl;
    }
}

void printStringVector(vector<StringWrapper2*> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << "Element " << i << ": " << v[i]->getVal() << endl;
    }
}

int main() {

    cout << "Begin - Template Integer Vector Test" << endl;
    vector<IntWrapper2*> vectorOfIntsTemplate;
    fillIntVector(vectorOfIntsTemplate);
    printIntVector(vectorOfIntsTemplate);
    // begin time
    auto startIntVector = high_resolution_clock::now();
    sortVector(vectorOfIntsTemplate, IsLessThan<IntWrapper2>());
    // end time
    auto stopIntVector = high_resolution_clock::now();
    auto durationIntVector = duration_cast<microseconds>(stopIntVector-startIntVector);
    sortVerification(vectorOfIntsTemplate, IsLessThan<IntWrapper2>());
    printIntVector(vectorOfIntsTemplate);
    cout << "End - Template Integer Vector Test\n" << endl;

    cout << "Begin - Template String Vector Test" << endl;
    vector<StringWrapper2*> vectorOfStringsTemplate;
    fillStringVector(vectorOfStringsTemplate);
    printStringVector(vectorOfStringsTemplate);
    // begin time
    auto startStringVector = high_resolution_clock::now();
    sortVector(vectorOfStringsTemplate, IsLessThan<StringWrapper2>());
    // end time
    auto stopStringVector = high_resolution_clock::now();
    auto durationStringVector = duration_cast<microseconds>(stopStringVector-startStringVector);
    sortVerification(vectorOfStringsTemplate, IsLessThan<StringWrapper2>());
    printStringVector(vectorOfStringsTemplate);
    cout << "End - Template String Vector Test\n" << endl;

    cout << "Sorting vector of 10000 ints took " << durationIntVector.count() << " microseconds using Template." << endl;
    cout << "Sorting vector of 10000 Strings took " << durationStringVector.count() << " microseconds using Template." << endl;

    return 0;
}
