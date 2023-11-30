#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <ctime>

using namespace std;

class Passenger {
    private:
    string name;
    int ID;
    string payment;
    bool handicapped = false;
    float reqRating;
    bool hasPets = false;
    int sizeOfParty;


    public:
    string GetName () {return name;};
    void SetName (string name) {this->name = name;};
    int GetID () {return ID;};
    void SetID (int ID) {this->ID = ID;};
    string GetPayment () {return payment;};
    void SetPayment (string payment) {this->payment = payment;};
    bool GetHandicapped () {return handicapped;};
    void SetHandicapped (bool handicapped) {this->handicapped = handicapped;};
    float GetReqRating () {return reqRating;};
    void SetReqRating (float reqRating) {this->reqRating = reqRating;};
    bool GetHasPets () {return hasPets;};
    void SetHasPets (bool hasPets) {this->hasPets = hasPets;};
    int GetSizeOfParty () {return sizeOfParty;};
    void SetSizeOfParty (int sizeOfParty) {this->sizeOfParty = sizeOfParty;};
    void Print();
};

#endif