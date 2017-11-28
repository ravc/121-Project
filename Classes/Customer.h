#ifndef Customer_H
#define Customer_H
#include "std_lib_facilities_4.h"
#include "Place_Info.h"
//The customers class creates a customer for the myRide problem. 
//It contains the currentLocation of the customer as well as their amount owed and name
class customers {
public:
    customers(string inputName, double inputAccountbalance);
	customers();
    int getAccountNumber();
    double getAccountBalance();
    void addAmountOwed(double amount);
    Place_Info getCurrentLocation();
    void makePayment(double payment);
    string getName();
    void changeLocation(Place_Info loc);
    string image();
private:
    int accountNumber;
    double accountBalance;
    Place_Info currentLocation;
    string custname;
    string image_name;
};
#endif
