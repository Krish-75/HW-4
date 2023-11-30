#ifndef DRIVER_H
#define DRIVER_H
#include <string>

using namespace std;

class Driver {
    private:
    string name;
    int ID;
    bool hasHandicap = false;
    string vehicle;
    bool available;
    float rating;
    bool canHavePets = false;
    string notes;
    int type; 

    protected:
    int capacity;

    public:
    string GetName () {return name;};
    void SetName (string name) {this->name = name;};
    int GetID () {return ID;};
    void SetID (int ID) {this->ID = ID;};
    int GetCapacity () {return capacity;};
    void SetCapacity (int capacity) {this->capacity = capacity;};
    bool GetHasHandicap () {return hasHandicap;};
    void SetHasHandicap (bool hasHandicap) {this->hasHandicap = hasHandicap;};
    string GetVehicle () {return vehicle;};
    void SetVehicle (string vehicle) {this->vehicle = vehicle;};
    bool GetAvailable () {return available;};
    void SetAvailable (bool available) {this->available = available;};
    float GetRating () {return rating;};
    void SetRating (float rating) {this->rating = rating;};
    bool GetCanHavePets () {return canHavePets;};
    void SetCanHavePets (bool canHavePets) {this->canHavePets = canHavePets;};
    string GetNotes () {return notes;};
    void SetNotes (string notes) {this->notes = notes;};
    int GetType () {return type;};
    void SetType (int driverType) {type = driverType;};
    // Set overrideable functions
    virtual int GetLuggageSpace() const = 0;
    virtual void SetLuggageSpace(int space) = 0;
    virtual void PrintInfo();
    // Destructor for child classes
    virtual ~Driver() {};
};

#endif