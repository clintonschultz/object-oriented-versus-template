//
// Created by clinton schultz on 4/4/21.
//
//
// Created by clinton schultz on 4/3/21.
//
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace std::chrono;

class IntWrapper2
{
private:
    int val;

public:
    IntWrapper2(int a): val(a) {};

    void setVal(int val) {
        IntWrapper2::val = val;
    }

    int getVal() const {
        return val;
    }

    bool operator<(const IntWrapper2 &rhs) const {
        return val < rhs.getVal();
    }

    bool operator>(const IntWrapper2 &rhs) const {
        return val > rhs.getVal();
    }

    bool operator<=(const IntWrapper2 &rhs) const {
        return val <= rhs.getVal();
    }

    bool operator>=(const IntWrapper2 &rhs) const {
        return val >= rhs.getVal();
    }

};

// string wrapper class - no longer inherits IComparable()
class StringWrapper2
{
private:
    string val;

public:
    StringWrapper2(string a): val(a) {};

    void setVal(int val) {
        StringWrapper2::val = val;
    }

    string getVal() const {
        return val;
    }

    bool operator<(const StringWrapper2 &rhs) const {
        return val < rhs.getVal();
    }

    bool operator>(const StringWrapper2 &rhs) const {
        return val > rhs.getVal();
    }

    bool operator<=(const StringWrapper2 &rhs) const {
        return val <= rhs.getVal();
    }

    bool operator>=(const StringWrapper2 &rhs) const {
        return val >= rhs.getVal();
    }
};

template<typename Object>
class IsLessThan
{
public:
    bool operator() (const Object & lhs, const Object & rhs) const
    {
        return lhs < rhs;
    }
};

template <typename T, typename Comparator>
void sortVector(vector<T*> &v, Comparator isLessThan) {

    bool sorted = false;

    while (!sorted) {
        sorted = true;
        for (int i = 0; i < v.size() - 1; i++) {
            if (isLessThan(*v[i+1], *v[i])) {
                sorted = false;
                T* temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
        }
    }
}

template <typename T, typename Comparator>
bool sortVerification(const vector<T*> &v, Comparator isLessThan) {

    for (int i = 1; i < v.size(); i++) {
        if (isLessThan(*v[i], *v[i-1])) {
            return false;
        }
    }
    return true;
}

