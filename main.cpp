/*  Name: Krish Kohir
    Email: krishkohir@my.unt.edu
    This code allows you to create passengers, drivers, and rides
    Creating a ride matches a passenger to a compatible driver
    The code also allows you to monitor and manipulate rides 
*/

#include <iostream>
#include <string>
#include "rides.h"
#include "drivers.h"
#include "passengers.h"


using namespace std;

int main () {
    
    string input;

    Passengers passengers;
    Drivers drivers;
    Rides rides;

    cout << "Name: Krish Kohir" << endl;
    cout << "krishkohir@my.unt.edu" << endl;
    cout << "Class: CSCE 1040" << endl;
    cout << "Section: 002" << endl;
    cout << endl;

    // Main menu system
    while (input != "q") {
        cout << "p - passengers" << endl;
        cout << "d - drivers" << endl;
        cout << "r - rides" << endl;
        cout << "q - quit" << endl;
        cout << endl;

        cin >> input;
        cin.ignore();
        // All passenger options
        if (input == "p") {
            while (input != "l") {
                cout << "a - add passenger" << endl;
                cout << "e - edit passenger" << endl;
                cout << "d - delete passenger" << endl;
                cout << "p - print passengers" << endl;
                cout << "f - find and print passenger" << endl;
                cout << "ld - load data" << endl;
                cout << "l - leave" << endl;

                cin >> input;
                cin.ignore(); 

                if (input == "a") {
                    passengers.AddPassenger();
                }

                else if (input == "e") {
                    int ID;
                    cout << "Enter passenger ID:";
                    cin >> ID;
                    cin.ignore();
                    // sees if passenger is in pending or active ride. If not, allow edit
                    bool passengerInRide; 
                    for (unsigned int i = 0; i < rides.GetRides().size(); i++) {
                        if (ID == rides.GetRides().at(i).GetPassengerID()) {
                            if (rides.GetRides().at(i).GetStatus() == "Pending" || rides.GetRides().at(i).GetStatus() == "Active")
                            passengerInRide = true;
                            break;
                        }
                    }

                    if (!passengerInRide) {
                        cout << "EDIT PASSENGER:" << endl;
                        passengers.EditPassenger(ID);
                    }

                    else {
                        cout << "Can't edit passenger in pending or active ride" << endl;
                    }
                }

                else if (input == "d") {
                    int index = passengers.DeletePassenger();
                    // set ride's passenger to null and cancels ride
                    for (unsigned int i = 0; i < rides.GetRides().size(); i++) {
                        if (index = rides.GetRides().at(i).GetPassengerID()) {
                            delete rides.GetRides().at(i).GetPassenger();
                            rides.GetRides().at(i).SetPassenger(nullptr);
                            rides.GetRides().at(i).SetPassengerID(-1);
                            rides.GetRides().at(i).SetStatus("Cancelled");
                        }
                    }
                }

                else if (input == "p") {
                    passengers.PrintAllPassengers();
                }

                else if (input == "f") {
                    passengers.FindAndPrintPassenger();
                }

                else if (input == "ld") {
                    passengers.LoadData();
                }
            }
        }
        // All driver options
        else if (input == "d") {
            while (input != "l") {
                cout << "a - add driver" << endl;
                cout << "e - edit driver" << endl;
                cout << "d - delete driver" << endl;
                cout << "p - print all drivers" << endl;
                cout << "f - find and print driver" << endl;
                cout << "ld - load data" << endl;
                cout << "l - leave" << endl;

                cin >> input;
                cin.ignore();

                if (input == "a") {
                    drivers.AddDriver();
                }

                else if (input == "e") {
                    int ID;
                    cout << "Enter driver ID:";
                    cin >> ID;
                    cin.ignore();
                    // sees if driver is in pending or active ride. If not, allow edit
                    bool driverInRide; 
                    for (unsigned int i = 0; i < rides.GetRides().size(); i++) {
                        if (ID == rides.GetRides().at(i).GetDriverID()) {
                            if (rides.GetRides().at(i).GetStatus() == "Pending" || rides.GetRides().at(i).GetStatus() == "Active")
                            driverInRide = true;
                            break;
                        }
                    }

                    if (!driverInRide) {
                        cout << "EDIT DRIVER: " << endl;
                        drivers.EditDriver(ID);
                    }

                    else {
                        cout << "Can't edit driver in pending or active ride" << endl;
                    }
                }

                else if (input == "d") {
                    int index = drivers.DeleteDriver();
                    // set ride's driver to null and cancels ride
                    for (unsigned int i = 0; i < rides.GetRides().size(); i++) {
                        if (index = rides.GetRides().at(i).GetDriverID()) {
                            delete rides.GetRides().at(i).GetDriver();
                            rides.GetRides().at(i).SetDriver(nullptr);
                            rides.GetRides().at(i).SetDriverID(-1);
                            rides.GetRides().at(i).SetStatus("Cancelled");
                        }
                    }

                }

                else if (input == "p") {
                    drivers.PrintAllDrivers();
                }

                else if (input == "f") {
                    drivers.FindAndPrintDriver();
                }

                else if (input == "ld") {
                    drivers.LoadData();
                }
            }
        }
        // All ride options
        else if (input == "r") {
            while (input != "l") {
                cout << "a - add ride" << endl;
                cout << "e - edit ride" << endl;
                cout << "d - delete ride" << endl;
                cout << "u - update ride status" << endl;
                cout << "ud - update driver availability" << endl;
                cout << "p - print all rides" << endl;
                cout << "f - find and print ride" << endl;
                cout << "ac - update rides to active" << endl;
                cout << "n - print all pending rides" << endl;
                cout << "pa - print all active rides" << endl;
                cout << "pco - print all completed rides" << endl;
                cout << "pca - print all canceled rides" << endl;
                cout << "pp - print all rides for passenger" << endl;
                cout << "pps - print passenger schedule" << endl;
                cout << "pd - print all rides for driver" << endl;
                cout << "pds - print driver schedule" << endl;
                cout << "dco - delete completed rides" << endl;
                cout << "dca - delete canceled rides" << endl;
                cout << "ld - load data" << endl;
                cout << "l - leave" << endl;

                cin >> input;
                cin.ignore();

                if (input == "a") {
                    rides.AddRide(passengers, drivers);
                }

                else if (input == "e") {
                    rides.EditRide();
                }

                else if (input == "d") {
                    rides.DeleteRide();
                }

                else if (input == "u") {
                    rides.UpdateRideStatus();
                }

                else if (input == "ud") {
                    rides.UpdateDriverAvailability(drivers);
                }

                else if (input == "p") {
                    rides.PrintAllRides();
                }

                else if (input == "f") {
                    rides.PrintRide();
                }

                else if (input == "ac") {
                    rides.ActivateRides();
                }

                else if (input == "m") {
                    rides.PrintAllPendingRides();
                }

                else if (input == "pa") {
                    rides.PrintAllActiveRides();
                }

                else if (input == "pco") {
                    rides.PrintAllCompletedRides();
                }

                else if (input == "pca") {
                    rides.PrintAllCanceledRides();
                }

                else if (input == "pp") {
                    rides.PrintAllRidesForPassenger();
                }

                else if (input == "pps") {
                    rides.PrintPassengerSchedule();
                }

                else if (input == "pd") {
                    rides.PrintAllRidesForDriver();
                }

                else if (input == "pds") {
                    rides.PrintDriverSchedule();
                }

                else if (input == "dco") {
                    rides.DeleteAllCompletedRides();
                }

                else if (input == "dca") {
                    rides.DeleteAllCanceledRides();
                }

                else if (input == "ld") {
                    rides.LoadData(passengers, drivers);
                }
            }
        }
    }

    //Deallocate all memory
    for (unsigned int i = 0; i < passengers.GetPassengers().size(); i++) {
        delete passengers.GetPassengers().at(i);
    }

    for (unsigned int i = 0; i < drivers.GetDrivers().size(); i++) {
        delete drivers.GetDrivers().at(i);
    }

    rides.GetRides().clear();
    return 0;
}
