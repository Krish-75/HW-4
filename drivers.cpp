#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>

#include "drivers.h"
#include "economy.h"
#include "basic.h"
#include "group.h"
#include "luxury.h"

using namespace std;

// Add driver object to collection
void Drivers::AddDriver() {
    string name;
    int ID;
    int capacity;
    char hasHandicap;
    string vehicle;
    char available;
    float rating;
    char canHavePets;
    bool goodPetsChar = false;
    string notes;
    int type;
    int luggage;
    cout << "ADD DRIVER: " << endl;
    cout << endl;
    // Determine the type of driver
    cout << "0 = Economy" << endl;
    cout << "1 = Basic" << endl;
    cout << "2 = Group" << endl;
    cout << "3 = Luxury" << endl;
    cout << endl;
    cout << "Enter driver type: ";
    cin >> type;
    cin.ignore();
    Driver *driver;

    if (type == 0){
        driver = new Economy;
        cout << "Enter capacity: ";
        cin >> capacity;
        cin.ignore();
        // Checks if driver capacity fits with type
        if (capacity <= static_cast<Economy*> (driver)->MAX_CAPACITY && capacity >= static_cast<Economy*> (driver)->MIN_CAPACITY){
            driver->SetCapacity(capacity);
        }
        
        else {
            cout << "Capacity out of range for driver type" << endl;
            driver->SetCapacity(static_cast<Economy*> (driver)->MIN_CAPACITY);
        }

        cout << "Enter luggage capacity: ";
        cin >> luggage;
        cin.ignore();
        static_cast<Economy*> (driver)->SetLuggageSpace(luggage);
    }

    else if (type == 1){
        driver = new Basic;
        cout << "Enter capacity: ";
        cin >> capacity;
        cin.ignore();
        // Checks if driver capacity fits with type
        if (capacity <= static_cast<Basic*> (driver)->MAX_CAPACITY && capacity >= static_cast<Basic*> (driver)->MIN_CAPACITY){
            driver->SetCapacity(capacity);
        }

        else {
            cout << "Capacity out of range for driver type" << endl;
            driver->SetCapacity(static_cast<Basic*> (driver)->MIN_CAPACITY);
        }

        cout << "Enter luggage capacity: ";
        cin >> luggage;
        cin.ignore();
        static_cast<Basic*> (driver)->SetLuggageSpace(luggage);
    }

    else if (type == 2){
        driver = new Group;
        cout << "Enter capacity: ";
        cin >> capacity;
        cin.ignore();
        // Checks if driver capacity fits with type
        if (capacity <= static_cast<Group*> (driver)->MAX_CAPACITY && capacity >= static_cast<Group*> (driver)->MIN_CAPACITY){
            driver->SetCapacity(capacity);
        }

        else {
            cout << "Capacity out of range for driver type" << endl;
            driver->SetCapacity(static_cast<Group*> (driver)->MIN_CAPACITY);
        }

        cout << "Enter luggage capacity: ";
        cin >> luggage;
        cin.ignore();
        static_cast<Group*> (driver)->SetLuggageSpace(luggage);
    }

    else if (type == 3){
        driver = new Luxury;
        cout << "Enter capacity: ";
        cin >> capacity;
        cin.ignore();
        driver->SetCapacity(capacity);

        cout << "Enter luggage capacity: ";
        cin >> luggage;
        cin.ignore();
        static_cast<Luxury*> (driver)->SetLuggageSpace(luggage);
        static_cast<Luxury*> (driver)->AddAmenities();
    }

    driver->SetType(type);
    cout << "Enter name: ";
    getline(cin, name);
    driver->SetName(name);

    cout << "Enter ID: ";
    cin >> ID;
    cin.ignore();
    driver->SetID(ID);

    cout << "Enter can accomodate handicapped (y/n): ";
    cin >> hasHandicap;

    if (hasHandicap == 'y') {
        driver->SetHasHandicap(true);
    }

    else if (hasHandicap == 'n') {
        driver->SetHasHandicap(false);
    }

    cin.ignore();
    cout << "Enter vehicle type: ";
    getline(cin, vehicle);
    driver->SetVehicle(vehicle);

    cout << "Enter availability (y/n): ";
    cin >> available;
    cin.ignore();

    if (available == 'y') {
        driver->SetAvailable(true);
    }

    else if (available == 'n') {
        driver->SetAvailable(false);
    }

    cout << "Enter rating: ";
    cin >> rating;
    cin.ignore();
    driver->SetRating(rating);

    cout << "Enter can have pets (y/n): ";
    cin >> canHavePets;
    
    if (canHavePets == 'y') {
        driver->SetCanHavePets(true);
    }
    
    else if (canHavePets == 'n') {
        driver->SetCanHavePets(false);
    }

    cin.ignore();
    cout << "Enter notes: ";
    getline(cin, notes);
    driver->SetNotes(notes);

    drivers.push_back(driver);
    cout << endl;
    StoreData();
    cout << "Driver added" << endl;
}

// Loops through collection to return index of matching driver
int Drivers::FindDriver (int ID) {
    for (int unsigned i = 0; i < drivers.size(); i++) {
        if (drivers.at(i)->GetID() == ID) {
            return i;
        }
    }

    cout << "Couldn't find driver" << endl;
    return -1;
}

// Returns a reference to matching driver
Driver* Drivers::GetDriver (int ID) {
    return drivers.at(FindDriver(ID));
}


// Deletes matching driver
int Drivers::DeleteDriver () {
    int ID;
    cout << "DELETE DRIVER: " << endl;
    cout << "Enter driver ID: ";
    cin >> ID;
    cin.ignore();
    int index = FindDriver(ID);

    if (index >= 0) {
        delete drivers.at(index);
        drivers.at(index) = nullptr;
        drivers.erase(drivers.begin() + index);
        StoreData();
        cout << "Driver deleted" << endl;
        return ID;
    }

    else {
        cout << "Couldn't delete driver" << endl;
        return -1;
    }
}

// Edits variables of matching driver
void Drivers::EditDriver (int ID) {
    string name;
    int capacity;
    char hasHandicap;
    string vehicle;
    char available;
    float rating;
    char canHavePets;
    string notes;
    int type;
    // Get location of driver
    int index = FindDriver(ID);
    // Assume no restrictions on capacity
    int maxCapacity = INT_MAX;
    int minCapacity = 1;

    if (index >= 0) {
        Driver *driver = drivers.at(index);
        type = driver->GetType();

        if (type == 0) {
            maxCapacity = 2;
        }

        else if (type == 1) {
            maxCapacity = 4;
            minCapacity = 2;
        }

        else if (type == 2) {
            maxCapacity = 7;
            minCapacity = 5;
        }

        cout << "Enter name: ";
        getline(cin, name);
        driver->SetName(name);
        
        cout << "Enter capacity: ";
        cin >> capacity;
        cin.ignore();
        if (capacity <= maxCapacity && capacity >= minCapacity) {
            driver->SetCapacity(capacity);
        }
        else {
            cout << "Capacity doesn't fit in driver range: capacity unedited" << endl;
        }

        cout << "Enter can accomodate handicapped (y/n): ";
        cin >> hasHandicap;

        if (hasHandicap == 'y') {
            driver->SetHasHandicap(true);
        }

        else if (hasHandicap == 'n') {
            driver->SetHasHandicap(false);
        }

        cin.ignore();

        cout << "Enter vehicle: ";
        getline(cin, vehicle);
        driver->SetVehicle(vehicle);

        cout << "Enter availability (y/n): ";
        cin >> available;
        cin.ignore();

        if (available == 'y') {
            driver->SetAvailable(true);
        }

        else if (available == 'n') {
            driver->SetAvailable(false);
        }

        cout << "Enter rating: ";
        cin >> rating;
        cin.ignore();
        driver->SetRating(rating);

        cout << "Enter can have pets (y/n): ";
        cin >> canHavePets;

        if (canHavePets == 'y') {
            driver->SetCanHavePets(true);
        }

        else if (canHavePets == 'n') {
            driver->SetCanHavePets(false);
        }

        cin.ignore();
        cout << "Enter notes: ";
        getline(cin, notes);
        driver->SetNotes(notes);

        *(drivers.at(index)) = *driver;

        cout << endl;
        StoreData();
        cout << "Driver edited" << endl;
    }

    else {
        cout << "Couldn't edit driver." << endl;
    }
}

// Loops and prints all drivers
void Drivers::PrintAllDrivers() {
    cout << "PRINT ALL DRIVERS: " << endl;
    cout << "=============================================" << endl;
    for (unsigned int i = 0; i < drivers.size(); i++) {
        drivers.at(i)->PrintInfo();
    }
    cout << "=============================================" << endl;
}

// Finds and prints matching driver
void Drivers::FindAndPrintDriver() {
    int ID;
    cout << "FIND AND PRINT DRIVER: " << endl;
    cout << "Enter driver ID: "; 
    cin >> ID;
    int index = FindDriver(ID);
    if (index >= 0) {
        cout << "=============================================" << endl;
        drivers.at(index)->PrintInfo();
        cout << "=============================================" << endl;
    }
}

// Stores all driver variables into text file
void Drivers::StoreData() {
    ofstream file("drivers.txt", ios_base::trunc);
    for (auto it = drivers.begin(); it != drivers.end(); it++) {
        file << (*it)->GetType();
        file << endl;
        file << (*it)->GetName();
        file << endl;
        file << (*it)->GetID();
        file << endl;
        file << (*it)->GetCapacity();
        file << endl;
        file << (*it)->GetLuggageSpace();
        file << endl;
        file << (*it)->GetHasHandicap();
        file << endl;
        file << (*it)->GetVehicle();
        file << endl;
        file << (*it)->GetAvailable();
        file << endl;
        file << (*it)->GetRating();
        file << endl;
        file << (*it)->GetCanHavePets();
        file << endl;
        file << (*it)->GetNotes();
        file << endl;
        // Checks if driver is of type luxury
        Driver *test = new Luxury;
        if ((*it)->GetType() == 3) {
            // If so, add the anemities
            for (size_t i = 0; i < static_cast <Luxury*> ((*it))->GetAmenities().size(); i++) {
                file << static_cast <Luxury*> ((*it))->GetAmenity(i);
                file << endl;
            }
        }
        delete test;
    }
}

// Creates driver objects while possible in text file, adds to collection
void Drivers::LoadData() {
    // Clear vector to avoid overlap
    drivers.clear();
    ifstream file("drivers.txt");
    string inputText;
    int inputNum;
    bool inputBool;
    float inputFloat;

    while(file >> inputNum) {
        Driver *driver;
        int type;

        if (inputNum == 0) {
            driver = new Economy;
        }

        else if (inputNum == 1) {
            driver = new Basic;
        }

        else if (inputNum == 2) {
            driver = new Group;
        }

        else if (inputNum == 3) {
            driver = new Luxury;
        }

        driver->SetType(inputNum);
        type = inputNum;
        file.ignore();
        file >> inputText;
        driver->SetName(inputText);
        file >> inputNum;
        driver->SetID(inputNum);
        file >> inputNum;
        driver->SetCapacity(inputNum);
        file >> inputNum;
        driver->SetLuggageSpace(inputNum);
        file >> inputBool;
        driver->SetHasHandicap(inputBool);
        file.ignore();
        getline(file, inputText);
        driver->SetVehicle(inputText);
        file >> inputBool;
        driver->SetAvailable(inputBool);
        file >> inputFloat;
        driver->SetRating(inputFloat);
        file >> inputBool;
        driver->SetCanHavePets(inputBool);
        file.ignore();
        getline(file, inputText);
        driver->SetNotes(inputText);
        // check if driver is luxury, if so add amenities
        if (type == 3) {
            bool foundEnd = false;
            while (!foundEnd) {
                string amenity;
                getline(file, amenity);
                if (amenity == "STOP")
                {
                    foundEnd = true;
                }
                static_cast<Luxury*> (driver)->AddAmenity(amenity);
            }    
        }
        drivers.push_back(driver);
    }
    cout << "Drivers loaded" << endl;
}