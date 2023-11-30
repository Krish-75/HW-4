#include <iostream>
#include <string>
#include <fstream>
#include "passengers.h"
using namespace std;

// Adds passenger to vector
void Passengers::AddPassenger() {
    string name;
    int ID;
    string payment;
    char handicapped;
    float reqRating;
    char hasPets;
    Passenger *passenger = new Passenger;
    int sizeOfParty;

    cout << "ADD PASSENGER: " << endl;
    cout << "Enter name: ";
    getline(cin, name);
    passenger->SetName(name);
    cout << "Enter ID: ";
    cin >> ID;
    passenger->SetID(ID);
    cin.ignore();
    cout << "Enter payment: ";
    getline(cin, payment);
    passenger->SetPayment(payment);
    cout << "Enter handicapped (y/n): ";
    cin >> handicapped;
    cin.ignore();

    if (handicapped == 'y') {
        passenger->SetHandicapped(true);
    }

    else if (handicapped == 'n'){
        passenger->SetHandicapped(false);
    }

    cout << "Enter required rating: ";
    cin >> reqRating;
    cin.ignore();
    passenger->SetReqRating(reqRating);

    cout << "Enter HasPets (y/n): ";
    cin >> hasPets;
    cin.ignore();

    if (hasPets == 'y') {
        passenger->SetHasPets(true);
    }

    else if (hasPets == 'n'){
        passenger->SetHasPets(false);
    }

    cout << "Enter size of party: ";
    cin >> sizeOfParty;
    cin.ignore();
    passenger->SetSizeOfParty(sizeOfParty);

    passengers.push_back(passenger);
    cout << endl;
    StoreData();
    cout << "Passenger added" << endl;
}

// Loops through vector to find index of passenger
int Passengers::FindPassenger (int ID) {
    for (int unsigned i = 0; i < passengers.size(); i++) {
        if (passengers.at(i)->GetID() == ID) {
            return i;
        }
    }

    cout << "Couldn't find passenger" << endl;
    return -1;
}

// Returns a reference to the wanted passenger
Passenger* Passengers::GetPassenger (int ID) {
    int i = FindPassenger(ID);
    if (i >= 0) {
        return passengers.at(i);
    }

    return nullptr;
}

// Loops through vector to remove matching passenger
int Passengers::DeletePassenger () {
    cout << "DELETE PASSENGER: " << endl;
    int ID;
    cout << "Enter passenger ID: ";
    cin >> ID;
    cin.ignore();
    int index = FindPassenger(ID);
    if (index >= 0) {
        delete passengers.at(index);
        passengers.at(index) = nullptr;
        passengers.erase(passengers.begin() + index);
        StoreData();
        cout << "Passenger deleted" << endl;
        return ID;
    }

    else {
        cout << "Couldn't delete passenger" << endl;
        return -1;
    }

}

// Changes appropriate variables for any passenger
void Passengers::EditPassenger (int ID) {
    
    string name;
    string payment;
    char handicapped;
    float reqRating;
    char hasPets;
    int sizeOfParty;
    
    int index = FindPassenger(ID);

    if (index >= 0) {
        cout << "Enter name: ";
        getline(cin, name);
        passengers.at(index)->SetName(name);
        cout << "Enter payment: ";
        getline(cin, payment);
        passengers.at(index)->SetPayment(payment);
        cout << "Enter handicapped (y/n): ";
        cin >> handicapped;
        cin.ignore();

        if (handicapped == 'y') {
            passengers.at(index)->SetHandicapped(true);
        }
        else if (handicapped == 'n'){
            passengers.at(index)->SetHandicapped(false);
        }

        cout << "Enter required rating: ";
        cin >> reqRating;
        cin.ignore();
        passengers.at(index)->SetReqRating(reqRating);
        cout << "Enter HasPets (y/n): ";
        cin >> hasPets;
        cin.ignore();

        if (hasPets == 'y') {
            passengers.at(index)->SetHasPets(true);
        }

        else if (hasPets == 'n') {
            passengers.at(index)->SetHasPets(false);

        }

        cout << "Enter size of party: ";
        cin >> sizeOfParty;
        cin.ignore();
        passengers.at(index)->SetSizeOfParty(sizeOfParty);
        cout << endl;
        StoreData();
        cout << "Passenger edited" << endl;
    }

    else {
        cout << "Couldn't edit passenger." << endl;
    }
}

// Loops through all passengers and prints
void Passengers::PrintAllPassengers() {
    cout << "PRINT ALL PASSENGERS: " << endl;
    cout << "=============================================" << endl;
    for (unsigned int i = 0; i < passengers.size(); i++) {
        passengers.at(i)->Print();
    }
    cout << "=============================================" << endl;
}

// Finds passenger and prints
void Passengers::FindAndPrintPassenger() {
    cout << "PRINT A PASSENGER: " << endl;
    int ID;
    cout << "Enter passenger ID: ";
    cin >> ID;
    cin.ignore();
    int index = FindPassenger(ID);
    if (index >= 0) {
        cout << "=============================================" << endl;
        passengers.at(index)->Print();
        cout << "=============================================" << endl;
    }
}

// Stores variables into text file
void Passengers::StoreData() {
    ofstream file ("passengers.txt", ios_base::trunc);
    for (auto it = passengers.begin(); it != passengers.end(); it++) {
        file << (*it)->GetName();
        file << endl;
        file << (*it)->GetID();
        file << endl;
        file << (*it)->GetPayment();
        file << endl;
        file << (*it)->GetHandicapped();
        file << endl;
        file << (*it)->GetReqRating();
        file << endl;
        file << (*it)->GetHasPets();
        file << endl;
        file << (*it)->GetSizeOfParty();
        file << endl;
    }
    cout << "Passengers stored" << endl;
}

// Creates passenger objects while possible and adds to collection
void Passengers::LoadData() {
    // Clear vector to avoid overlap
    passengers.clear();
    ifstream file ("passengers.txt");
    string inputText;
    int inputNum;
    double inputFloat;
    bool inputBool;
    //loops while data can be added
    while (getline(file, inputText)) {
        Passenger *passenger = new Passenger;
        passenger->SetName(inputText);
        file >> inputNum;
        passenger->SetID(inputNum);
        file.ignore();
        getline(file, inputText);
        passenger->SetPayment(inputText);
        file >> inputBool;
        passenger->SetHandicapped(inputBool);
        file >> inputFloat;
        passenger->SetReqRating(inputFloat);
        file >> inputBool;
        passenger->SetHasPets(inputBool);
        file >> inputNum;
        passenger->SetSizeOfParty(inputNum);
        file.ignore();
        passengers.push_back(passenger);
    }
    cout << "Passengers loaded" << endl;
}