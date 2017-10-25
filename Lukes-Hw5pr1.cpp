#include "std_lib_facilities_4.h"
/*
Program Created by Luke Witt for CSCE 121-200
Homework 5:Problem 1 (Adjusting the myRide Program)

The purpose of this program is to adjust the intial myRide program so that it can read from a file and write to the file. This will allow the program to keep its data continually changing
*/


/*Helper Functions-
deg2rads: Takes in a degree in double form and returns its equivalent radian value in double form
geoDistanceCalculator: Takes two sets of coordinates of the double data type and returns the distance between those two points in miles(also double format)*/
double deg2rads(double deg)
{
	return deg / 180.0 * 3.1415926;
}
double geoDistanceCalculator(double lat1, double lon1, double lat2, double lon2)
{

	//Setting up all of the variables prior to the calculation
	lat1 = deg2rads(lat1);
	lat2 = deg2rads(lat2);
	lon1 = deg2rads(lon1);
	lon2 = deg2rads(lon2);
	double earthRadius = 3963.1676;

	//Plugging everything into the equation
	double distance = acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(lon1 - lon2))*earthRadius;
	return distance;
}
ostream& operator<<(ostream&os, vector<string> var) {
	for (int i = 0; i < var.size(); i++) {
		os << "\t" << var[i] << endl;
	}
	return os;
}
vector<string> emptyKeys;


//3 Global variables that are used to check for input later in the program
bool driversFailed = false;
bool customersFailed = false;
bool locationsFailed = false;


//All of the classes
//The Geo_loc class holds a place in the world based on their geographic coordinates.
class Geo_loc {

public:
	Geo_loc(double x, double y);

	double getLatitude() { return lat; }

	double getLongitude() { return lon; }

	double getDistance(Geo_loc a, Geo_loc b) {
		return geoDistanceCalculator(a.getLatitude(), a.getLongitude(), b.getLatitude(), b.getLongitude());
	}
private:
	double lat;
	double lon;

};


//The Place_info class holds all of the information about a certain place. 
//This consists of the geo_loc of their coordinates as well as the name of the place and certain keys that could be used to describe it
class Place_info {

public:
	Place_info(string inputName, string inputAddress, vector<string> inputTags, Geo_loc inputLocation);
	string getName() { return name; }
	string getAddress() { return address; }
	vector<string> getTags() { return tags; }
	Geo_loc getLocation() { return location; }


private:
	string name;
	string address;
	vector<string> tags;
	Geo_loc location;
};


//The customers class creates a customer for the myRide problem. 
//It contains the currentLocation of the customer as well as their amount owed and name
class customers {
public:
	customers(string inputName, double inputAccountbalance);
	int getAccountNumber() { return accountNumber; }
	double getAccountBalance() { return accountBalance; }
	void addAmountOwed(double amount) { accountBalance -= amount; }
	Place_info getCurrentLocation() { return currentLocation; }
	void makePayment(double payment) { accountBalance += payment; }
	string getName() { return name; }
	void changeLocation(Place_info loc) { currentLocation = loc; }
private:
	int accountNumber;
	double accountBalance;
	Place_info currentLocation;
	string name;
};


//The drivers class creates a driver to be used in the myRide problem
//It contains information about the driver such as user number, name, account balance and current location
class drivers {
public:
	drivers(Geo_loc location, string inputName, double balance);
	Geo_loc getCurrentLocation() { return currentLocation; }
	double getCurrentPaycheck() { return currentPaycheck; }
	void addMoney(double amount) { currentPaycheck += amount; }
	string getName() { return name; }
	void changeLocation(Geo_loc loc) { currentLocation = loc; }
private:
	Geo_loc currentLocation;
	double currentPaycheck;
	string name;

};


//All of the constructor's for the classes
Geo_loc::Geo_loc(double x, double y) : lat(x), lon(y) {}
Place_info::Place_info(string inputName, string inputAddress, vector<string> inputTags, Geo_loc inputLocation) :
	name(inputName), address(inputAddress), tags(inputTags), location(inputLocation) {}
customers::customers(string inputName, double inputAccountbalance) :
	name(inputName), accountBalance(inputAccountbalance), currentLocation(Place_info("", "", emptyKeys, Geo_loc(0, 0))) {}
drivers::drivers(Geo_loc location, string inputName, double balance) : currentLocation(location), name(inputName), currentPaycheck(balance) {}


//All of the overwriting operators functions
ostream& operator<<(ostream&os, drivers d) {
	return os << "Driver Name: " << d.getName() << endl << "Current Paycheck: " << d.getCurrentPaycheck() << endl
		<< "Latitude: " << d.getCurrentLocation().getLatitude() << endl << "Longitude: " << d.getCurrentLocation().getLongitude() << endl;
}
ostream& operator<<(ostream&os, customers c) {
	return os << "Customers Name: " << c.getName() << endl << "Account Balance: " << c.getAccountBalance() << endl << "Current Location: " << c.getCurrentLocation().getName();
}
ostream& operator<<(ostream&os, Place_info p) {
	return os << "Location: " << p.getName() << endl << "Address: " << p.getAddress() << endl << "Tags: " << p.getTags();
}
ostream& operator<<(ostream&os, Geo_loc g) {
	return os << "Latitude: " << g.getLatitude() << endl << "Longitude: " << g.getLongitude() << endl;
}
istream& operator>>(istream&ist, drivers& d) {
	vector<drivers> list;
	string name;
	double balance;
	double lat;
	double lon;
	ist >> name >> balance >> lat >> lon;
	if (ist.fail()) {
		cout << "The Drivers could not be loaded";
		ist.clear();
		ist.ignore(2147483647, '\n');
		driversFailed = true;
	}
	d = drivers(Geo_loc(lat, lon), name, balance);
	return ist;
}
istream& operator>>(istream&ist, customers& c) {
	string name;
	double balance;
	ist >> name >> balance;
	if (ist.fail()) {
		cout << "The Customers could not be loaded";
		ist.clear();
		ist.ignore(2147483647, '\n');
		customersFailed = true;
	}
	c = customers(name, balance);
	return ist;
}
istream& operator>>(istream&ist, Place_info& p) {
	string name;
	string address;
	double lat;
	double lon;
	int numKeys;
	string key = "";
	ist >> name >> address >> lat >> lon >> numKeys;
	vector<string> keys;
	for (int j = 0; j < numKeys; j++)
	{
		ist >> key;
		keys.push_back(key);
		if (ist.fail()) {
			cout << "The places could not be loaded";
			ist.clear();
			ist.ignore(2147483647, '\n');
			locationsFailed = true;
			break;
		}
	}
	p = Place_info(name, address, keys, Geo_loc(lat, lon));

	return ist;
}


//The 3 Global vectors that contain all of the customers, places, and drivers
vector<customers> listOfCustomers;
vector<Place_info> listOfPlaces;
vector<drivers> listOfDrivers;


/*More Helper Functions
printMenu-Prints out the main menu
loadDrivers-imports the drivers from the input file stream
loadCustomers-imports the customers from the input file stream
loadPlaces-imports the places from the input file stream
clearScreen-prints out multiple end lines to "clear" the screen
checkForFailure-This checks to see if all of the data was able to be loaded without error (return 0 if there is a problem)
getChoice-This gets the menu selection from the user
loadDataFile-This function asks the user for the name of a file and checks to see if it can be loaded (returns the naem of the file as a string)
case1-This function does the 1st option in the menu (print out the drivers)
case2-This function does the 2nd option in the menu (print out the customers)
case3-This function does the 3rd option in the menu (print out the places)
case4-This function does the 4th option in the menu (Add a customer to the system)
case5-This function does the 5th option in the menu (Add a driver to the system)
case6-This function does the 6th option in the menu (Add a place to the system) (return 0 to exit program)
writeToFile-This function writes all of the information to the file to be used for next time*/
void printMenu() {
	cout << "Please select an option from the following menu" << endl;
	cout << "-----------------------------------------------" << endl << endl;
	cout << "1:Print out Drivers" << endl;
	cout << "2:Print out Customers" << endl;
	cout << "3:Print out Places" << endl;
	cout << "4:Add a Customer to the system" << endl;
	cout << "5:Add a Driver to the system" << endl;
	cout << "6:Add a Place to the system" << endl;
	cout << "7:Make a Transaction" << endl;
	cout << "8:Make a Payment for a customer" << endl;
	cout << "9:Exit the program" << endl;
	cout << "Your selection: ";
}
vector<drivers> loadDrivers(ifstream& ist)
{
	vector<drivers> list;
	drivers d = drivers(Geo_loc(0, 0), "", 0);
	int max;
	ist >> max;
	for (int i = 0; i < max; i++)
	{
		ist >> d;
		if (ist.fail()) {
			cout << "The Drivers could not be loaded";
			ist.clear();
			ist.ignore(2147483647, '\n');
			driversFailed = true;
		}
		list.push_back(d);
	}
	return list;
}
vector<customers> loadCustomers(ifstream& ist)
{
	vector<customers> list;
	customers c = customers("", 0);
	int max;
	ist >> max;
	for (int i = 0; i < max; i++) {
		ist >> c;
		if (ist.fail()) {
			cout << "The Customers could not be loaded";
			ist.clear();
			ist.ignore(2147483647, '\n');
			customersFailed = true;
			break;
		}
		list.push_back(c);
	}
	return list;
}
vector<Place_info> loadPlaces(ifstream& ist)
{
	vector<Place_info> list;
	vector<string> fakeTags;
	Place_info p = Place_info("", "", fakeTags, Geo_loc(0, 0));
	int max;
	ist >> max;
	for (int i = 0; i < max; i++) {
		ist >> p;
		list.push_back(p);
	}
	return list;
}
void clearScreen() {
	for (int i = 0; i < 25; i++)
		cout << endl;
}
int checkForFailure() {
	if (locationsFailed) {
		cout << "The Places were not able to be loaded correctly";
		keep_window_open();
		return 0;
	}
	if (driversFailed) {
		cout << "The Drivers were not able to be loaded correctly";
		keep_window_open();
		return 0;
	}
	if (customersFailed) {
		keep_window_open();
		cout << "The customers were not able to be loaded correctly";
		return 0;
	}
	return 1;
}
int getChoice() {
	int choice = 0;
	while (!(cin >> choice)) {
		cin.clear();
		cout << "Your input was not a number, try again";
		cin.ignore(2147483647, '\n');
	}
	return choice;
}
string loadDataFile() {
	string fileName;
	cout << "Enter input file name: ";
	cin >> fileName;
	return fileName;
}
void case1() {
	clearScreen();
	for (int i = 0; i < listOfDrivers.size(); i++) {
		cout << listOfDrivers[i] << endl;
	}
	keep_window_open();
}
void case2() {
	clearScreen();
	for (int i = 0; i < listOfCustomers.size(); i++) {
		cout << listOfCustomers[i] << endl;
	}
	keep_window_open();
}
void case3() {
	clearScreen();
	for (int i = 0; i < listOfPlaces.size(); i++) {
		cout << listOfPlaces[i] << endl;
	}
	keep_window_open();
}
void case4() {
	clearScreen();
	string newName;
	double newBalance;
	cout << "What is the name of the customer you would like to add? \n" << "Name: ";
	cin >> newName;
	cout << "\nWhat is the customers current balance? \n" << "Balance: ";
	cin >> newBalance;
	listOfCustomers.push_back(customers(newName, newBalance));
}
void case5() {
	clearScreen();
	string newName;
	double newBalance;
	double lat;
	double lon;
	cout << "What is the name of the driver you would like to add? \n" << "Name: ";
	cin >> newName;
	cout << "\nWhat is the drivers current paycheck? \n" << "Balance: ";
	cin >> newBalance;
	cout << "\nWhat is the drivers currrent latitude? \n" << "Latitude: ";
	cin >> lat;
	cout << "\nWhat is the drivers current longitude? \n" << "Longitude: ";
	cin >> lon;
	listOfDrivers.push_back(drivers(Geo_loc(lat, lon), newName, newBalance));
}
int case6() {
	clearScreen();
	string newName;
	string newAddress;
	int numTags;
	vector<string> newTags;
	string tag;
	double lat;
	double lon;
	cout << "What is the name of the new place you would like to add? \n Name: ";
	cin >> newName;
	cout << "\nWhat is the address of the new place? \nAddress: ";
	cin >> newAddress;
	cout << "\nWhat is the latitude of the new place? \nLatitude: ";
	cin >> lat;
	cout << "\nWhat is the longitude of the new place? \nLongitude: ";
	cin >> lon;
	cout << "\nHow many tags will be associated with this place?\nNumber of Tags: ";
	cin >> numTags;
	if (cin.fail()) return 0;
	cout << "Please enter in your tags";
	for (int i = 1; i <= numTags; i++) {
		cout << endl << i << ": ";
		cin >> tag;
		newTags.push_back(tag);
	}
	listOfPlaces.push_back(Place_info(newName, newAddress, newTags, Geo_loc(lat, lon)));
	return 1;
}
void writeToFile(string fileName) {
	ofstream ost{ fileName };
	if (!ost) error("Can't open output file ", fileName);
	ost << listOfDrivers.size() << endl;
	for (int i = 0; i < listOfDrivers.size(); i++) {
		ost << listOfDrivers[i].getName() << " " << listOfDrivers[i].getCurrentPaycheck() << " "
			<< listOfDrivers[i].getCurrentLocation().getLatitude() << " " << listOfDrivers[i].getCurrentLocation().getLongitude() << endl;
	}
	ost << listOfCustomers.size() << endl;
	for (int i = 0; i < listOfCustomers.size(); i++) {
		ost << listOfCustomers[i].getName() << " " << listOfCustomers[i].getAccountBalance() << endl;
	}
	ost << listOfPlaces.size() << endl;
	for (int i = 0; i < listOfPlaces.size(); i++) {
		ost << listOfPlaces[i].getName() << " " << listOfPlaces[i].getAddress() << " " << listOfPlaces[i].getLocation().getLatitude() << " " << listOfPlaces[i].getLocation().getLongitude() << " " << listOfPlaces[i].getTags().size();
		for (int j = 0; j < listOfPlaces[i].getTags().size(); j++) {
			ost << " " << listOfPlaces[i].getTags()[j];
		}
		ost << endl;
	}
}


int main()
{
	//Initializing all of the variables needed
	string fileName = loadDataFile();
	ifstream ist{ fileName };
	if (!ist) {
		error("Can't find data file ", fileName);
		return 0;
	}
	listOfDrivers = loadDrivers(ist);
	listOfCustomers = loadCustomers(ist);
	listOfPlaces = loadPlaces(ist);
	if (checkForFailure() == 0) return 0;
	printMenu();

	//Goes through the choices on the menu
	int choice = getChoice();
	while (choice > 0 && choice <= 9) {
		switch (choice) {
			//print out drivers
		case 1: {
			case1();
			break;
		}
				//print out customers
		case 2: {
			case2();
			break;
		}
				//print out locations
		case 3: {
			case3();
			break;
		}
				//Add a customer to the system
		case 4: {
			case4();
			break;
		}
				//Add an employee to the system
		case 5: {
			case5();
			break;
		}
				//Add a new place to the system
		case 6: {
			int x = case6();
			if (x == 0) {
				writeToFile(fileName);
				return 0;
			}
			break;
		}
				//Make a transaction
		case 7: {
			//FIGURING OUT WHICH CUSTOMER IS MAKING THE TRANSACTION
			cout << "Current Customers in System:\n";
			for (int i = 0; i < listOfCustomers.size(); i++) {
				cout << listOfCustomers[i].getName() << endl;
			}
			cout << "Which customer would like a ride?\n Name: ";
			string name;
			cin >> name;
			//Checking for errors
			bool check = false;
			int custPointer = 0;
			for (int i = 0; i < listOfCustomers.size(); i++) {
				if (listOfCustomers[i].getName() == name) {
					check = true;
					custPointer = i;
				}
			}
			clearScreen();
			if (!check) {
				cout << "That customer can not be found in the system.\nPlease add your customer to the directory from the main screen";
				break;
			}
			//FINDING THE CUSTOMERS STARTING LOCATION
			cout << "Current Locations and keys in the directory are:\n";
			for (int i = 0; i < listOfPlaces.size(); i++) {
				cout << listOfPlaces[i].getName() << endl << listOfPlaces[i].getTags();
			}
			cout << "Where is the customer located?\n";
			string custLocation;
			Geo_loc startLocation = Geo_loc(0, 0);
			cin >> custLocation;
			//Checking for errors 
			bool check2 = false;
			for (int i = 0; i < listOfPlaces.size(); i++) {
				for (int j = 0; j < listOfPlaces[i].getTags().size(); j++) {
					if (listOfPlaces[i].getName() == custLocation || listOfPlaces[i].getTags()[j] == custLocation) {
						check2 = true;
						startLocation = listOfPlaces[i].getLocation();
					}
				}
			}
			if (!check2) {
				cout << "That location can not be found in the system.\nPlease add your location to the directory from the main screen";
				break;
			}
			//FINDING THE CUSTOMERS ENDING LOCATION
			cout << "Current Locations and keys in the directory are:\n";
			for (int i = 0; i < listOfPlaces.size(); i++) {
				cout << listOfPlaces[i].getName() << endl << listOfPlaces[i].getTags();
			}
			cout << "Where would the customer like to go?\n";
			string custLocation2;
			Geo_loc endLocation = Geo_loc(0, 0);
			cin >> custLocation2;
			//Checking for errors
			bool check3 = false;
			for (int i = 0; i < listOfPlaces.size(); i++) {
				for (int j = 0; j < listOfPlaces[i].getTags().size(); j++) {
					if (listOfPlaces[i].getName() == custLocation2 || listOfPlaces[i].getTags()[j] == custLocation2) {
						check3 = true;
						endLocation = listOfPlaces[i].getLocation();
					}
				}
			}
			if (!check3) {
				cout << "That location can not be found in the system.\nPlease add your location to the directory from the main screen";
				break;
			}

			//Finding the correct driver
			double minDistance = startLocation.getDistance(startLocation, listOfDrivers[0].getCurrentLocation());
			int pointer = 0;
			for (int i = 0; i < listOfDrivers.size(); i++) {
				if (startLocation.getDistance(startLocation, listOfDrivers[i].getCurrentLocation()) < minDistance) {
					minDistance = startLocation.getDistance(startLocation, listOfDrivers[i].getCurrentLocation());
					pointer = i;
				}
			}
			//Make the transaction
			double routeDist = startLocation.getDistance(startLocation, endLocation);
			listOfCustomers[custPointer].addAmountOwed(1.0*routeDist);
			listOfDrivers[pointer].addMoney(.50*routeDist);
			listOfDrivers[pointer].changeLocation(endLocation);
			break;
		}
		case 8: {
			clearScreen();
			cout << "Current Customers in System:\n";
			for (int i = 0; i < listOfCustomers.size(); i++) {
				cout << listOfCustomers[i].getName() << endl;
			}
			cout << "Which customer would like a ride?\n Name: ";
			string name;
			cin >> name;
			bool check = false;
			int custPointer = 0;
			for (int i = 0; i < listOfCustomers.size(); i++) {
				if (listOfCustomers[i].getName() == name) {
					check = true;
					custPointer = i;
				}
			}
			clearScreen();
			if (!check) {
				cout << "That customer can not be found in the system.\nPlease add your customer to the directory from the main screen";
				break;
			}
			double balanceAdded;
			cout << "How much would you like to pay towards the customers balance?\nBalance: ";
			cin >> balanceAdded;
			listOfCustomers[custPointer].makePayment(balanceAdded);
			break;

		}
		default:
			writeToFile(fileName);
			return 0;
			break;
		}
		clearScreen();
		printMenu();
		while (!(cin >> choice)) {
			cin.clear();
			cout << "Your input was not a number, try again";
			cin.ignore(2147483647, '\n');
		}
	}
	writeToFile(fileName);
}