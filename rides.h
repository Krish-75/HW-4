#ifndef RIDES_H
#define RIDES_H
#include <vector>
#include "ride.h"
#include "drivers.h"
#include "passengers.h"
#include "iostream"

class Rides {
    private:
    vector<Ride> rides;
    static bool CompareRideTimes(Ride ride1, Ride ride2);

    public:
    vector<Ride> GetRides() {return rides;};
    void AddRide(Passengers passengers, Drivers drivers);
    void EditRide();
    void DeleteRide();
    void UpdateRideStatus();
    void UpdateDriverAvailability(Drivers drivers);
    int FindRide(int ID);
    void PrintAllRides();
    void PrintRide();
    void ActivateRides();
    void PrintAllPendingRides();
    void PrintAllActiveRides();
    void PrintAllCompletedRides();
    void PrintAllCanceledRides();
    void PrintAllRidesForPassenger();
    void PrintAllRidesForDriver();
    void PrintPassengerSchedule();
    void PrintDriverSchedule();
    void DeleteAllCanceledRides();
    void DeleteAllCompletedRides();
    void StoreData();
    void LoadData(Passengers passengers, Drivers drivers);
};


#endif