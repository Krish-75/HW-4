#ifndef RIDE_H
#define RIDE_H
#include <string>
#include <ctime>
#include <vector>
#include "driver.h"
#include "passenger.h"
#include "economy.h"
#include "basic.h"
#include "group.h"
#include "luxury.h"

using namespace std;

class Ride {
    private:
    int ID;
    string pickUpLocation;
    time_t pickUpTime;
    string dropOffLocaton;
    time_t dropOffTime = 0;
    int sizeOfParty;
    bool hasPets;
    bool hasHandicap;
    string status;
    float customerRating;
    Passenger* passenger = new Passenger;
    Driver *driver;
    int passengerID;
    int driverID;
    
    public:
    ~Ride();
    int GetID () {return ID;};
    void SetID (int ID) {this->ID = ID;};
    string GetPickUpLocation () {return pickUpLocation;};
    void SetPickUpLocation (string pickUpLocation) {this->pickUpLocation = pickUpLocation;};
    time_t GetPickUpTime () {return pickUpTime;};
    void SetPickUpTime (time_t pickUpTime) {this->pickUpTime = pickUpTime;};
    string GetDropOffLocation () {return dropOffLocaton;};
    void SetDropOffLocation (string dropOffLocation) {this->dropOffLocaton = dropOffLocation;};
    int GetSizeOfParty () {return sizeOfParty;};
    void SetSizeOfParty (int sizeOfParty) {this->sizeOfParty = sizeOfParty;};
    bool GetHasPets () {return hasPets;};
    void SetHasPets (bool hasPets) {this->hasPets = hasPets;};
    bool GetHasHandicap () {return hasHandicap;};
    void SetHasHandicap (bool hasHandicap) {this->hasHandicap = hasHandicap;};
    time_t GetDropOffTime () {return dropOffTime;};
    void SetDropOffTime (time_t dropOffTime) {this->dropOffTime = dropOffTime;};
    string GetStatus () {return status;};
    void SetStatus (string status) {this->status = status;};
    float GetCustomerRating () {return customerRating;};
    void SetCustomerRating (float customerRating) {this->customerRating = customerRating;};
    Driver* GetDriver () {return driver;};
    Passenger* GetPassenger () {return passenger;};
    int GetPassengerID() {return passengerID;};
    int GetDriverID () {return driverID;};
    void SetPassenger (Passenger* passenger);
    bool SetDriver (Driver* driver);
    void SetDriverID (int ID) {this->driverID = ID;};
    void SetPassengerID (int ID) {this->passengerID = ID;};
    void Print ();
};

#endif