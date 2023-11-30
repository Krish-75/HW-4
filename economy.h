#ifndef ECONOMY_H
#define ECONOMY_H
#include <string>
#include "driver.h"

using namespace std;

class Economy : public Driver{
    private: 
    int luggageSpace;

    public: 
    void PrintInfo();
    int GetLuggageSpace() const {return luggageSpace;};
    void SetLuggageSpace(int space) {luggageSpace = space;};
    int const MAX_CAPACITY = 2;
    int const MIN_CAPACITY = 1;
    double const pricePerMile = 1.00; 
    ~Economy() {};
};

#endif