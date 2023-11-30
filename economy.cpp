#include <iostream>
#include <string>

#include "economy.h"

using namespace std;

void Economy::PrintInfo() {
    Driver::PrintInfo();
    cout << "Driver type: Economy" << endl;
    cout << "Luggage space: " << luggageSpace << endl;
    cout << "Price per mile: $" << pricePerMile << endl;
}