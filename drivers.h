#ifndef DRIVERS_H
#define DRIVERS_H
#include "driver.h"
#include <vector>


using namespace std;

class Drivers {
    private:
    vector<Driver*> drivers;
    int FindDriver (int ID);

    public:
    vector<Driver*> GetDrivers () {return drivers;};
    void AddDriver ();
    void EditDriver (int ID);
    int DeleteDriver ();
    Driver* GetDriver(int ID);
    void PrintAllDrivers();
    void FindAndPrintDriver();
    void StoreData();
    void LoadData();
};

#endif