#include "Customer.h"
#include "std_lib_facilities_4.h"

vector<string> emptyKeys

customers::customers(string inputName, double inputAccountbalance) :
    name(inputName), accountBalance(inputAccountbalance), currentLocation(Place_info("", "", emptyKeys, Geo_loc(0, 0))) {}
int customers::getAccountNumber() { return accountNumber; }
double customers::getAccountBalance() { return accountBalance; }
void customers::addAmountOwed(double amount) { accountBalance -= amount; }
Place_info customers::getCurrentLocation() { return currentLocation; }
void customers::makePayment(double payment) { accountBalance += payment; }
string customers::getName() { return name; }
void customers::changeLocation(Place_info loc) { currentLocation = loc; }
