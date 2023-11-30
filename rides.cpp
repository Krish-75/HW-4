#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "rides.h"



// Adds ride object to collection if possible
void Rides::AddRide(Passengers passengers, Drivers drivers) {
    int ID;
    string pickUpLocation;
    string dropOffLocation;
    time_t pickUpTime;
    time_t now;
    int sizeOfParty;
    int inputTime;
    unsigned int i;
    unsigned int j;

    cout << "ADD RIDE: " << endl;
    Ride ride;
    cout << "Enter passenger ID: ";
    cin >> ID;
    cin.ignore();
    ride.SetPassenger(passengers.GetPassenger(ID));
    cout << "Enter ride ID: ";
    cin >> ID;
    cin.ignore();
    ride.SetID(ID);
    cout << "Enter pick up location: ";
    getline(cin, pickUpLocation);
    ride.SetPickUpLocation(pickUpLocation);
    cout << "Enter drop off location: ";
    getline(cin, dropOffLocation);
    ride.SetDropOffLocation(dropOffLocation);
    // Get the pick up time
    time(&now);
    struct tm *time = gmtime(&now);
    cout << "Enter year: ";
    cin >> inputTime;
    cin.ignore();
    time->tm_year = inputTime - 1900;
    cout << "Enter month (1-12): ";
    cin >> inputTime;
    cin.ignore();
    time->tm_mon = inputTime - 1;
    cout << "Enter day (1-31): ";
    cin >> inputTime;
    cin.ignore();
    time->tm_mday = inputTime;
    cout << "Enter hour (0-24): ";
    cin >> inputTime;
    cin.ignore();
    time->tm_hour = inputTime - 1;
    cout << "Enter minute (0-59): ";
    cin >> inputTime;
    cin.ignore();
    time->tm_min = inputTime;
    pickUpTime = mktime(time);
    ride.SetPickUpTime(pickUpTime);

    // For loop checks all drivers for compatibility
    for (i = 0; i < drivers.GetDrivers().size(); i++) {
        // Sees if rides exist
        bool driverCompatible = true;
        if (rides.size() != 0) {
            for (j = 0; j < rides.size(); j++) {
                if (rides.at(j).GetDriver() == drivers.GetDrivers().at(i)) {
                    // sees if ride should be considered
                    if (rides.at(j).GetStatus() == "Pending" || rides.at(j).GetStatus() == "Active") {
                        // Sees if there is enough of a difference between this ride and other rides
                        if (abs(difftime(ride.GetPickUpTime(), rides.at(j).GetPickUpTime())) < 1800) {
                            driverCompatible = false;
                            break;
                        }
                    }
                }
            }

            if (driverCompatible) {
                if (ride.SetDriver((drivers.GetDrivers().at(i)))) {
                    ride.SetStatus("Pending");
                    rides.push_back(ride);
                    StoreData();
                    cout << "Ride added" << endl;
                    return;
                }
            }
        }
        
        // Checks if driver is compatible with ride
        else{
            if (ride.SetDriver((drivers.GetDrivers().at(i)))) {
                ride.SetStatus("Pending");
                rides.push_back(ride);
                StoreData();
                cout << "Ride added" << endl;
                return;
            }
        }
    }

    cout << "Couldn't find driver for ride" << endl;
}


// Loops through ride and returns matching index
int Rides::FindRide(int ID) {
    for (unsigned int i = 0; i < rides.size(); i++) {
        if (ID == rides.at(i).GetID()) {
            return i;
        }
    }

    cout << "Couldn't find ride" << endl;
    return -1;
}

// Edits variables of matching ride if allowed
void Rides::EditRide() {
    int ID;
    unsigned int i;
    unsigned int j;
    string pickUpLocation;
    string dropOffLocation;
    time_t pickUpTime;
    time_t now;
    time_t tempTime;
    int minutesFromNow;
    int hoursFromNow;
    int inputTime;
    int numPassengers;
    string handicap;
    string pets;

    cout << "EDIT RIDE: " << endl;
    cout << "Enter ride ID: ";
    cin >> ID;
    cin.ignore();
    int rideIndex = FindRide(ID);
    if (rideIndex >= 0) {
        // See what variables can be edited while pending
        if (rides.at(rideIndex).GetStatus() == "Pending") {
            cout << "Enter pick up location";
            getline(cin, pickUpLocation);
            rides.at(rideIndex).SetPickUpLocation(pickUpLocation);
            cout << "Enter drop off location: ";
            getline(cin, dropOffLocation);
            rides.at(rideIndex).SetDropOffLocation(dropOffLocation);
            // Get new time
            time(&now);
            struct tm *time = gmtime(&now);
            cout << "Enter year: ";
            cin >> inputTime;
            cin.ignore();
            time->tm_year = inputTime - 1900;
            cout << "Enter month (1-12): ";
            cin >> inputTime;
            cin.ignore();
            time->tm_mon = inputTime - 1;
            cout << "Enter day (1-31): ";
            cin >> inputTime;
            cin.ignore();
            time->tm_mday = inputTime;
            cout << "Enter hour (0-24): ";
            cin >> inputTime;
            cin.ignore();
            time->tm_hour = inputTime - 1;
            cout << "Enter minute (0-59): ";
            cin >> inputTime;
            cin.ignore();
            // Store original time
            time->tm_min = inputTime;
            tempTime = rides.at(rideIndex).GetPickUpTime();
            pickUpTime = mktime(time);
            rides.at(rideIndex).SetPickUpTime(pickUpTime);
            for (j = 0; j < rides.size(); j++) {
                    if (rides.at(j).GetDriver() == rides.at(rideIndex).GetDriver()) {
                        // sees if ride should be considered
                        if (rides.at(j).GetStatus() == "Pending" || rides.at(j).GetStatus() == "Active") {
                            // Sees if there is enough of a difference between this ride and other rides of 30 min
                            if (abs(difftime(rides.at(rideIndex).GetPickUpTime(), rides.at(j).GetPickUpTime())) < 1800) {
                                // If not, revert time to original
                                cout << "Can't change time: interferes with driver" << endl;
                                rides.at(rideIndex).SetPickUpTime(tempTime);
                            }
                        }
                    }
            }
            cout << "Enter number of passengers: ";
            cin >> numPassengers;
            cin.ignore();

            // Only change if compatible with driver
            if (numPassengers > rides.at(rideIndex).GetDriver()->GetCapacity()) {
                cout << "Sorry, too many passengers" << endl;
            }
            else {
                rides.at(rideIndex).SetSizeOfParty(numPassengers);
            }

            // Only change if compatible with driver
            cout << "Enter is handicapped (true/false): ";
            cin >> handicap;
            cin.ignore();
            if (handicap == "true") {
                if (rides.at(rideIndex).GetDriver()->GetHasHandicap() == false) {
                    cout << "Can't add handicapped" << endl;
                }

                else {
                    rides.at(rideIndex).SetHasHandicap(true);
                }
            }

            else {
                rides.at(rideIndex).SetHasHandicap(false);
            }

            // Only change if compatible with driver
            cout << "Enter has pets (true/false): ";
            cin >> pets;
            cin.ignore();
            if (pets == "true") {
                if (rides.at(rideIndex).GetDriver()->GetCanHavePets() == false) {
                    cout << "Can't add pets" << endl;
                }

                else {
                    rides.at(rideIndex).SetHasPets(true);
                }
            }

            else {
                rides.at(rideIndex).SetHasPets(false);
            }

            StoreData();
        }

        // Edits variables appropriate to active ride
        else if (rides.at(rideIndex).GetStatus() == "Active") {
            cout << "Enter drop off location: ";
            getline(cin, dropOffLocation);
            rides.at(rideIndex).SetDropOffLocation(dropOffLocation);
            StoreData();
        }

        else {
            cout << "Can't edit ride (completed/canceled)" << endl;
        }
    }
}


// Removes matching ride
void Rides::DeleteRide() {
    int ID;
    cout << "Enter ride ID: ";
    cin >> ID;
    cin.ignore();
    int index = FindRide(ID);
    if (index >= 0) {
        // Deallocates memory
        delete rides.at(index).GetPassenger();
        delete rides.at(index).GetDriver();
        rides.erase(rides.begin() + index);
        StoreData();
    }

    else {
        cout << "Can't delete ride" << endl;
    }
}

// Used for sort function, return true if ride 1 before ride 2
bool Rides::CompareRideTimes(Ride ride1, Ride ride2) {
    return ride1.GetPickUpTime() < ride2.GetPickUpTime();
}

// Cancel/Complete ride
void Rides::UpdateRideStatus() {
    int ID;
    int choice;
    cout << "Enter ride ID: ";
    cin >> ID;
    int rideIndex = FindRide(ID);
    if (rideIndex >= 0) {
        cout << "Type 0 to cancel ride, 1 to complete" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 0) {
            // Checks to see if ride is cancellable
            if (rides.at(rideIndex).GetStatus() == "Pending") {
                rides.at(rideIndex).SetStatus("Cancelled");
                rides.at(rideIndex).SetDropOffTime(rides.at(rideIndex).GetPickUpTime());
                cout << "Ride cancelled" << endl;
                StoreData();
                return;
            }
            else {
                cout << "Can't cancel ride; ride not pending" << endl;
                return;
            }
        }

        // Checks to see if ride is endable
        else if (choice == 1) {
            if (rides.at(rideIndex).GetStatus() == "Active") {
            rides.at(rideIndex).SetStatus("Complete");
            time_t now;
            time(&now);
            rides.at(rideIndex).SetDropOffTime(now);
            cout << "Ride completed" << endl;
            StoreData();
            return;
            }

            else {
                cout << "Can't complete ride; not active" << endl;
                return;
            }
        }

        else {
            cout << "Enter valid number" << endl;
        }
    }
}

// Sets driver availability
void Rides::UpdateDriverAvailability(Drivers drivers) {
    int ID;
    Driver* driverIndex;

    cout << "Enter driver ID: ";
    cin >> ID;
    cin.ignore();
    driverIndex = drivers.GetDriver(ID);
    if (driverIndex != nullptr) {
        // Ensures all rides are active as appropriate
        ActivateRides();
        for (auto it = rides.begin(); it != rides.end(); it++) {
            // Sees if ride is active
            if (it->GetStatus() == "Active") {
                Driver *currDriver = it->GetDriver();
                //see if both pointers point to same driver
                if (currDriver >= driverIndex && currDriver <= driverIndex) {
                    driverIndex->SetAvailable(false);
                    drivers.StoreData();
                    return;
                }
            }
        }

        driverIndex->SetAvailable(true);
        drivers.StoreData();
        return;
    }

    else {
        cout << "Can't find driver" << endl;
    }
}

// Prints out all rides
void Rides::PrintAllRides() {
    cout << "PRINT ALL RIDES:" << endl;
    cout << "=============================================" << endl;
    for (auto it = rides.begin(); it != rides.end(); it++) {
        it->Print();
    }
    cout << "=============================================" << endl;
}

// Finds and prints appropriate ride
void Rides::PrintRide() {
    cout << "PRINT A RIDE:" << endl;
    int ID;
    cout << "Enter Ride ID: ";
    cin >> ID;
    cin.ignore();
    cout << "=============================================" << endl;
    for (auto it = rides.begin(); it != rides.end(); it++) {
        if (it->GetID() == ID) {
            it->Print();
            return;
        }
    }
    cout << "=============================================" << endl;
}

// Sees if rides should be active
void Rides::ActivateRides() {
    time_t now;
    time(&now);
    for (auto it = rides.begin(); it != rides.end(); it++) {
        // Checks if ride is pending
        if (it->GetStatus() == "Pending"){
            // Is current time past pick up time? If so, change ride status
            if (it->GetPickUpTime() < now) {
                it->SetStatus("Active");
            }
        }
    }
    cout << "Rides activated" << endl;
    StoreData();
}

// Print all pending rides
void Rides::PrintAllPendingRides() {
    cout << "PRINT ALL PENDING RIDES:" << endl;
    cout << "=============================================" << endl;
    for (auto it = rides.begin(); it != rides.end(); it++) {
        if (it->GetStatus() == "Pending") {
            it->Print();
        }
    }
    cout << "=============================================" << endl;
}

// Print all active rides
void Rides::PrintAllActiveRides() {
    cout << "PRINT ALL ACTIVE RIDES:" << endl;
    cout << "=============================================" << endl;
    for (auto it = rides.begin(); it != rides.end(); it++) {
        if (it->GetStatus() == "Active") {
            it->Print();
        }
    }
    cout << "=============================================" << endl;
}

// Print all completed rides
void Rides::PrintAllCompletedRides() {
    cout << "PRINT ALL COMPLETED RIDES:" << endl;
    cout << "=============================================" << endl;
    for (auto it = rides.begin(); it != rides.end(); it++) {
        if (it->GetStatus() == "Completed") {
            it->Print();
        }
    }
    cout << "=============================================" << endl;
}

// Print all canceled rides
void Rides::PrintAllCanceledRides() {
    cout << "PRINT ALL CANCELED RIDES:" << endl;
    cout << "=============================================" << endl;
    for (auto it = rides.begin(); it != rides.end(); it++) {
        if (it->GetStatus() == "Cancelled") {
            it->Print();
        }
    }
    cout << "=============================================" << endl;
}

// Prints all rides for passenger
void Rides::PrintAllRidesForPassenger() {
    cout << "PRINT ALL RIDES FOR PASSENGER" << endl;
    int ID;
    cout << "Enter passenger ID: ";
    cin >> ID;
    cin.ignore();
    cout << "=============================================" << endl;
    for (auto it = rides.begin(); it != rides.end(); it++) {
        if (it->GetPassenger()->GetID() == ID) {
            it->Print();
        }
    }
    cout << "=============================================" << endl;
}

// Prints all rides for driver
void Rides::PrintAllRidesForDriver() {
    cout << "PRINT ALL RIDES FOR DRIVER" << endl;
    int ID;
    cout << "Enter driver ID: ";
    cin >> ID;
    cin.ignore();
    cout << "=============================================" << endl;
    for (auto it = rides.begin(); it != rides.end(); it++) {
        if (it->GetDriver()->GetID() == ID) {
            it->Print();
        }
    }
    cout << "=============================================" << endl;
}

// Prints passenger rides in order
void Rides::PrintPassengerSchedule() {
    cout << "PRINT PASSENGER SCHEDULE" << endl;
    int ID;
    cout << "Enter passenger ID: ";
    cin >> ID;
    cin.ignore();
    vector<Ride> passengerRides;
    // Adds all of passenger's rides to one vector
    for (unsigned int i = 0; i < rides.size(); i++) {
        if (rides.at(i).GetPassenger()->GetID() == ID) {
            passengerRides.push_back(rides.at(i));
        }
    }

    // Sort vector based on start time
    sort(passengerRides.begin(), passengerRides.end(), CompareRideTimes);
    
    // Print all rides in vector
    cout << "=============================================" << endl;
    for (unsigned int i = 0; i < passengerRides.size(); i++) {
        time_t startTime;
        string startTimeString;
        startTime = passengerRides.at(i).GetPickUpTime();
        startTimeString = ctime(&startTime);
        cout << "Ride #" << i+1 << ":" << endl;
        passengerRides.at(i).Print();
        cout << endl;
    }
    cout << "=============================================" << endl;
}

// Prints driver rides in order
void Rides::PrintDriverSchedule() {
    cout << "PRINT DRIVER SCHEDULE" << endl;
    int ID;
    cout << "Enter driver ID: ";
    cin >> ID;
    cin.ignore();
    // Adds all of driver's rides to one vector
    vector<Ride> driverRides;
    for (unsigned int i = 0; i < rides.size(); i++) {
        if (rides.at(i).GetDriver()->GetID() == ID) {
            driverRides.push_back(rides.at(i));
        }
    }

    // Sort vector based on start time
    sort(driverRides.begin(), driverRides.end(), CompareRideTimes);
    
    // Print all rides in vector
    cout << "=============================================" << endl;
    for (unsigned int i = 0; i < driverRides.size(); i++) {
        time_t startTime;
        string startTimeString;
        startTime = driverRides.at(i).GetPickUpTime();
        startTimeString = ctime(&startTime);
        cout << "Ride #" << i+1 << ":" << endl;
        driverRides.at(i).Print();
        cout << endl;
    }
    cout << "=============================================" << endl;
}

// Delete ride if ride status is canceled
void Rides::DeleteAllCanceledRides() {
    for (unsigned int i = 0; i < rides.size(); i++) {
        if (rides.at(i).GetStatus() == "Cancelled") {
            rides.erase(rides.begin() + i);
            i--;
        }
    }
    StoreData();
    cout << "Deleted all canceled rides" << endl;
}

// Delete ride if ride status is completed
void Rides::DeleteAllCompletedRides() {
    for (unsigned int i = 0; i < rides.size(); i++) {
        if (rides.at(i).GetStatus() == "Completed") {
            rides.erase(rides.begin() + i);
            i--;
        }
    }
    StoreData();
    cout << "Deleted all completed rides" << endl;
}

// Stores each ride variable in text except for pointers
void Rides::StoreData() {
    ofstream file("rides.txt", ios_base::trunc);
    for (auto it = rides.begin(); it != rides.end(); it++) {
        file << it->GetID();
        file << endl;
        file << it->GetPickUpLocation();
        file << endl;
        file << it->GetPickUpTime();
        file << endl;
        file << it->GetDropOffLocation();
        file << endl;
        file << it->GetDropOffTime();
        file << endl;
        file << it->GetSizeOfParty();
        file << endl;
        file << it->GetHasPets();
        file << endl;
        file << it->GetHasHandicap();
        file << endl;
        file << it->GetStatus();
        file << endl;
        file << it->GetCustomerRating();
        file << endl;
        file << it->GetPassengerID();
        file << endl;
        file << it->GetDriverID();
        file << endl;
    }
}

// Creates ride objects while possible and adds them to collection
void Rides::LoadData(Passengers passengers, Drivers drivers) {
    rides.clear();
    ifstream file("rides.txt");
    string inputText;
    int inputNum;
    bool inputBool;
    float inputFloat;

    while (file >> inputNum) {
        Ride ride;
        ride.SetID(inputNum);
        file.ignore();
        getline(file, inputText);
        ride.SetPickUpLocation(inputText);
        file >> inputNum;
        ride.SetPickUpTime(inputNum);
        file.ignore();
        getline(file, inputText);
        ride.SetDropOffLocation(inputText);
        file >> inputNum;
        ride.SetDropOffTime(inputNum);
        file >> inputNum;
        file.ignore();
        ride.SetSizeOfParty(inputNum);
        file >> inputBool;
        file.ignore();
        ride.SetHasPets(inputBool);
        file >> inputBool;
        file.ignore();
        ride.SetHasHandicap(inputBool);
        file.ignore();
        getline(file, inputText);
        ride.SetStatus(inputText);
        file >> inputFloat;
        file.ignore();
        ride.SetCustomerRating(inputFloat);
        file >> inputNum;
        file.ignore();
        // Add passenger pointer based on passenger ID
        ride.SetPassenger(passengers.GetPassenger(inputNum));
        ride.SetPassengerID(inputNum);
        file >> inputNum;
        file.ignore();
        // Add passenger pointer based on passenger ID
        ride.SetDriver(drivers.GetDriver(inputNum));
        ride.SetDriverID(inputNum);
        rides.push_back(ride);
    }
}