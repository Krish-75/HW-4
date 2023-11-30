#ifndef GROUP_H
#define GROUP_H
#include <string>
#include "driver.h"

using namespace std;

class Group : public Driver {
    private: 
    int luggageSpace; 
   

    public: 
    void PrintInfo();
    int GetLuggageSpace() const {return luggageSpace;};
    void SetLuggageSpace(int space) {luggageSpace = space;};
    double const pricePerMile = 2.20; 
    int const MAX_CAPACITY = 7;
    int const MIN_CAPACITY = 5;
    ~Group() {};
};

#endif