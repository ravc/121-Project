#ifndef makeTransaction_H
#define makeTransaction_H
#include "std_lib_facilities_4.h"
#include "Customer.h"
#include "Place_Info.h"
#include "Driver.h"
#include "Geo_Loc.h"

struct rideWindow : Graph_lib::Window {
	rideWindow(Point xy, int w, int h, const string& title,vector<customers>inputCustomers,vector<Place_Info>inputPlaces,vector<drivers>inputDrivers);

private:
	vector<customers>listOfCustomers;
	vector<drivers>listOfDrivers;
	vector<Place_Info>listOfPlaces;
	customers current=listOfCustomers[0];
	Place_Info st=listOfPlaces[0];
	drivers dr=listOfDrivers[0];
	vector<Place_Info> options;
	double minDistance=1000000;
	Place_Info fin=listOfPlaces[0];
	
	int menu;
	//MENU 1
	//Variables to be shown for request ride screen
	string inputName = "";
	string startPlace = "";
	string finalPlace = "";
	Text requestRideName;
	Text nameWrong;
	Text startWrong;
	Text finalWrong;
	Button back_button;  //Button to go to previous screen
	Button quit_button; //Button to quit the program
	In_box name_box; //Box to input the name of the person you are 
	In_box startPlace_box;  //Box to input the starting place
	In_box finalPlace_box; // Box to input the tag/name of final place
	Button proceed_button; //Button to continue with the program
	Image* customerPic;
	Image* startPic;
	Image* finalPic;
	Image* driverPic;

	//MENU 2
	//Variables to be shown for Confirm transaction screen
	//Also should include back_button/quit_button/proceed_button
	Text confirmTransactionName;  // Name of the sub menu
	Text customerLabel;	//Label for the customer image
	Text startPlaceLabel; //Label for the start place image
	Text destinationLabel; //Label for the end place image
	Text driverLabel;


	//All of the functions necessary for the window to work
	void menu1();
	void menu2();
	void proceed_pressed();
	void back_pressed();
	void quit_pressed();
	static void cb_proceed(Address, Address);
	static void cb_back(Address, Address);
	static void cb_quit(Address, Address);
	
};
#endif
