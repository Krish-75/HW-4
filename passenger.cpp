#include <iostream>
#include <string>

#include "passenger.h"

using namespace std;
// Prints all variables
void Passenger::Print() {
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
    cout << "Payment Preference: " << payment << endl;
    cout << "Handicapped: " << handicapped << endl;
    cout << "Required Rating: " << reqRating << endl;
    cout << "Has Pets: " << hasPets << endl;
    cout << "Size of Party: " << sizeOfParty << endl;
    cout << endl;
}