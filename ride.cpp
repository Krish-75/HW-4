#include <string>
#include <ctime>
#include <vector>
#include <iostream>
#include "ride.h"

using namespace std;

Ride::~Ride() {
    delete driver;
    delete passenger;
}

// Returns true and assigns only if driver is compatible with passsenger
bool Ride::SetDriver(Driver* driver) {
    if (driver->GetCapacity() < sizeOfParty) {
        return false;
    }

    if (!driver->GetHasHandicap() && hasHandicap) {
        return false;
    }

    if (!driver->GetCanHavePets() && hasPets) {
        return false;
    }

    if (driver->GetRating() < customerRating) {
        return false;
    }
   
    // allocate memory for the driver here
    if (driver->GetType() == 0) {
        this->driver = new Economy;
    }
    if (driver->GetType() == 1) {
        this->driver = new Basic;
    }
    if (driver->GetType() == 2) {
        this->driver = new Group;
    }
    if (driver->GetType() == 3) {
        this->driver = new Luxury;
    }
    this->driver = driver;
    SetDriverID(driver->GetID());
    return true;
}

// Adds passenger to ride and edits ride variables to match
void Ride::SetPassenger(Passenger* passenger) {
    sizeOfParty = passenger->GetHandicapped();
    hasPets = passenger->GetHasPets();
    hasHandicap = passenger->GetHandicapped();
    customerRating = passenger->GetReqRating();
    SetPassengerID(passenger->GetID());
    this->passenger = passenger;
}

// Prints ride data
void Ride::Print()
{
    string pickUpTime = ctime(&this->pickUpTime);
    string dropOffTime;
    cout << "ID: " << ID << endl;
    cout << "Pick Up Location: " << pickUpLocation << endl;
    cout << "Pick Up Time: " << pickUpTime << endl;
    cout << "Drop Off Location: " << dropOffLocaton << endl;
    if (status == "Completed" || status == "Canceled") {
        dropOffTime = ctime(&this->dropOffTime);
        cout << "Drop Off Time: " << dropOffTime << endl;
    }
    cout << "Number of Passengers: " << sizeOfParty << endl;
    cout << "Has Pets : " << hasPets << endl;
    cout << "Has Handicap: " << hasHandicap << endl;
    if (GetPassenger() != nullptr){
        cout << "Passenger: " << GetPassenger()->GetName() << endl;
    }

    else {
        cout << "Passenger deleted" << endl;
    }

    if (GetDriver() != nullptr) {
        cout << "Driver: " << GetDriver()->GetName() << endl;
    }

    else {
        cout << "Driver deleted" << endl;
    }

    cout << "Status: " << status << endl;
    cout << "Minimum rating allowed by customer: " << customerRating << endl;
    cout << endl;
}
