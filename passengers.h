#ifndef PASSENGERS_H
#define PASSENGERS_H
#include "passenger.h"
#include <vector>


using namespace std;

class Passengers {
    private: 
    vector<Passenger*> passengers;
    int FindPassenger (int ID);

    public:
    vector<Passenger*> GetPassengers () {return passengers;};
    void AddPassenger ();
    void EditPassenger (int ID);
    int DeletePassenger ();
    Passenger* GetPassenger (int ID);
    void PrintAllPassengers ();
    void FindAndPrintPassenger ();
    void StoreData();
    void LoadData();
};

#endif