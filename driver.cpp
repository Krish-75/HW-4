#include <iostream>
#include <string>

#include "driver.h"

using namespace std;

void Driver::PrintInfo() {
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Can accomodate handicapped: " << hasHandicap << endl;
    cout << "Vehicle: " << vehicle << endl;
    cout << "Availabile: " << available << endl;
    cout << "Rating: " << rating << endl;
    cout << "Can Have Pets: " << canHavePets << endl;
    cout << "Notes: " << notes << endl;
    cout << endl;
}