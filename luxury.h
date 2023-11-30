#ifndef LUXURY_H
#define LUXURY_H
#include <string>
#include <vector>
#include "driver.h"

using namespace std;

class Luxury : public Driver {
    private: 
    int luggageSpace; 
    vector<string> amenities;
    int amenitiesSize;

    public: 
    void PrintInfo();
    void AddAmenities();
    void AddAmenity(string amenity) {amenities.push_back(amenity);};
    vector<string> GetAmenities() {return amenities;};
    int GetLuggageSpace() const {return luggageSpace;};
    void SetLuggageSpace(int space) {luggageSpace = space;};
    string GetAmenity(int index);
    double const pricePerMile = 5.50;
    ~Luxury() {};
};

#endif