#ifndef Customer_H
#define Customer_H
#include "std_lib_facilities_4.h"
#include "Place_Info.h"
//The customers class creates a customer for the myRide problem. 
//It contains the currentLocation of the customer as well as their amount owed and name
class customers {
public:
    customers(string inputName, double inputAccountbalance);
    int getAccountNumber();
    double getAccountBalance();
    void addAmountOwed(double amount);
    Place_info getCurrentLocation();
    void makePayment(double payment);
    string getName();
    void changeLocation(Place_info loc);
private:
    int accountNumber;
    double accountBalance;
    Place_info currentLocation;
    string name;
};
#endif
