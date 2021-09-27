//
// Created by clinton schultz on 3/23/21.
//
//
// Created by clinton schultz on 3/23/21.
//
#ifndef COMPARINGMETHODS_COMPAREOOP_H
#define COMPARINGMETHODS_COMPAREOOP_H

#include <string>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// IComparable() is an interface class
class IComparable
{
public:
    virtual bool isLessThan(IComparable * rhs) const = 0;
};

// int wrapper class - implements IComparable()
class IntWrapper : public IComparable
{
private:
    int val;

public:
    IntWrapper(int a): val(a) {};
    bool isLessThan(IComparable* rhs) const override
    {
        IntWrapper * sref = dynamic_cast<IntWrapper *>(rhs);
        if (sref == nullptr) {
            return false;
        }
        return *this < *sref;
    };

    void setVal(int val) {
        IntWrapper::val = val;
    }

    int getVal() const {
        return val;
    }

    bool operator<(const IntWrapper &rhs) const {
        return val < rhs.getVal();
    }

    bool operator>(const IntWrapper &rhs) const {
        return val > rhs.getVal();
    }

    bool operator<=(const IntWrapper &rhs) const {
        return val <= rhs.getVal();
    }

    bool operator>=(const IntWrapper &rhs) const {
        return val >= rhs.getVal();
    }

};

// string wrapper class - inherits IComparable()
class StringWrapper : public IComparable
{
private:
    string val;

public:
    StringWrapper(string a): val(a) {};
    bool isLessThan(IComparable* rhs) const override
    {
        StringWrapper * sref = dynamic_cast<StringWrapper *>(rhs);
        return *this < *sref;
    };

    void setVal(int val) {
        StringWrapper::val = val;
    }

    string getVal() const {
        return val;
    }

    bool operator<(const StringWrapper &rhs) const {
        return val < rhs.getVal();
    }

    bool operator>(const StringWrapper &rhs) const {
        return val > rhs.getVal();
    }

    bool operator<=(const StringWrapper &rhs) const {
        return val <= rhs.getVal();
    }

    bool operator>=(const StringWrapper &rhs) const {
        return val >= rhs.getVal();
    }
};

#endif //COMPARINGMETHODS_COMPAREOOP_H
