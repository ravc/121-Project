#include "Customer.h"
#include "std_lib_facilities_4.h"

vector<string> emptyKeys;
string name;
double accountBalance;
int accountNumber = 0;
Place_Info currentLocation;

customers::customers(string inputName, double inputAccountbalance) :
    name(inputName), accountBalance(inputAccountbalance), currentLocation(Place_Info("", "", emptyKeys, Geo_Loc(0, 0))) {}
int customers::getAccountNumber() { return accountNumber; }
double customers::getAccountBalance() { return accountBalance; }
void customers::addAmountOwed(double amount) { accountBalance -= amount; }
Place_Info customers::getCurrentLocation() { return currentLocation; }
void customers::makePayment(double payment) { accountBalance += payment; }
string customers::getName() { return name; }
void customers::changeLocation(Place_Info loc) { currentLocation = loc; }
