#include <iostream>
#include <string>

#include "luxury.h"

using namespace std;

void Luxury::PrintInfo() {
    Driver::PrintInfo();
    cout << "Driver type: Basic" << endl;
    cout << "Luggage space: " << luggageSpace << endl;
    cout << "Price per mile: $" << pricePerMile << endl;
    cout << "Amenities: " << endl;
    for (size_t i = 0; i < amenities.size() - 1; i++) {
        cout << amenities.at(i) << endl;
    }
}

void Luxury::AddAmenities() {
    cout << "ADD LUXURY AMENITIES" << endl;
    cout << "TYPE 'STOP' TO STOP ADDING AMENITIES" << endl;
    string amenity;

    getline(cin, amenity);
    // Adds amenity names to amenities vector until told to stop
    while (amenity != "STOP") {
        AddAmenity(amenity);
        getline(cin, amenity);
    }
    AddAmenity("STOP");
    amenitiesSize = amenities.size();
    cout << "AMENITIES ADDED" << endl;
}

string Luxury::GetAmenity(int index) {
    return amenities.at(index);
}