#include <iostream>
#include <string>

#include "group.h"

using namespace std;

void Group::PrintInfo() {
    Driver::PrintInfo();
    cout << "Driver type: Group" << endl;
    cout << "Luggage space: " << luggageSpace << endl;
    cout << "Price per mile: $" << pricePerMile << endl;
}