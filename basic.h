#ifndef BASIC_H
#define BASIC_H
#include <string>
#include "driver.h"

using namespace std;

class Basic : public Driver {
    private:
    int luggageSpace;

    public: 
    void PrintInfo();
    int GetLuggageSpace() const {return luggageSpace;};
    void SetLuggageSpace(int space) {luggageSpace = space;};
    // capacity sizes for basic ride
    int const MAX_CAPACITY = 4;
    int const MIN_CAPACITY = 2;
    double const pricePerMile = 1.50;
    ~Basic() {};
};

#endif