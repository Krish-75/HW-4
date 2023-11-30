#include <iostream>
#include <string>

#include "basic.h"

using namespace std;

void Basic::PrintInfo() {
    Driver::PrintInfo();
    cout << "Driver type: Basic" << endl;
    cout << "Luggage space: " << luggageSpace << endl;
    cout << "Price per mile: $" << pricePerMile << endl;
}