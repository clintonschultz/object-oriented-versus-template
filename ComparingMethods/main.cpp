#include <iostream>
#include <string>
#include <chrono>
#include <stdlib.h>
#include <vector>

#include "CompareOOP.cpp"
#include "DrowningPool.cpp" // BONUS - Check the end of the code...

using namespace std;

void sortVector(vector<IComparable *> &v) {

    bool sorted = false;
    // begin time
    auto start = high_resolution_clock::now();

    while (!sorted) {
        sorted = true;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i+1]->isLessThan(v[i])) {
                sorted = false;
                IComparable * temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
        }
    }
    // end time
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << duration.count() << endl;
}

bool sortVerification(vector<IComparable*> &v) {

    for (int i = 1; i < v.size(); i++) {
        if (v[i]->isLessThan(v[i-1])) {
            return false;
        }
    }
    return true;
}

void fillIntVector(vector<IComparable *> &v) {

cout << "fillIntVector called." << endl;

    for (int i = 0; i <= 10000; i++) {
        v.push_back(new IntWrapper(rand() % 1000));
    }
    // print out values of v which are printing in hex currently
    //for (IComparable *x : v) {
        //cout << x << endl;
}

void fillStringVector(vector<IComparable *> &v) {

    cout << "fillStringVector called." << endl;

    if (v.empty() == 0) {
        cout << "fillStringVector : vector is empty." << endl;
    }
    else {
        string tmp_s;
        static const char alphanum[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";

        srand((unsigned) time(NULL) * getpid());

        int len = 4;

        for (int i = 0; i <= 10000; i++) {
            tmp_s = "";
            len = rand() % 4 + 1;
            for (int j = 0; j < len; ++j) {
                tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
            }
            v.push_back(new StringWrapper(tmp_s));
        }
    }
}

void printVector(const vector<IComparable*>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        IntWrapper* intWrapper = dynamic_cast<IntWrapper*>(v[i]);

        if (intWrapper != nullptr)
        {
            cout << "element " << i << ": " << intWrapper->getVal() << endl;
        }

        StringWrapper* stringWrapper = dynamic_cast<StringWrapper*>(v[i]);

        if (stringWrapper != nullptr)
        {
            cout << "element " << i << ": " << stringWrapper->getVal() << endl;
        }
    }
}

int main() {

    cout << "Begin - OOP Integer Vector Test" << endl;
    vector<IComparable*> vectorOfInts;
    fillIntVector(vectorOfInts);
    printVector(vectorOfInts);
    // begin time
    auto startIntVector = high_resolution_clock::now();
    sortVector(vectorOfInts);
    // end time
    auto stopIntVector = high_resolution_clock::now();
    auto durationIntVector = duration_cast<microseconds>(stopIntVector-startIntVector);
    sortVerification(vectorOfInts);
    printVector(vectorOfInts);
    cout << "End - OOP Integer Vector Test\n" << endl;

    cout << "Begin - OOP String Vector Test" << endl;
    vector<IComparable*> vectorOfStrings;
    fillStringVector(vectorOfStrings);
    printVector(vectorOfStrings);
    // begin time
    auto startStringVector = high_resolution_clock::now();
    sortVector(vectorOfStrings);
    // end time
    auto stopStringVector = high_resolution_clock::now();
    auto durationStringVector = duration_cast<microseconds>(stopStringVector-startStringVector);
    sortVerification(vectorOfStrings);
    printVector(vectorOfStrings);
    cout << "End - OOP String Vector Test\n" << endl;

    cout << "Sorting vector of 10000 ints took " << durationIntVector.count() << " microseconds using OOP." << endl;
    cout << "Sorting vector of 10000 Strings took " << durationStringVector.count() << " microseconds using OOP.\n" << endl;

    //cout << "Here is a little treat for you - (Hint: Drowning Pool - Bodies)" << endl;
    //DrowningPool::bodiesHitTheFloor();   UNCOMMENT AND RUN

    return 0;
}