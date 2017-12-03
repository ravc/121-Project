#ifndef makeTransaction_H
#define makeTransaction_H
#include "std_lib_facilities_4.h"
#include "Customer.h"
#include "Place_Info.h"
#include "Driver.h"
#include "Geo_Loc.h"

struct rideWindow : Graph_lib::Window {
	rideWindow(Point xy, int w, int h, const string& title,vector<customers>&inputCustomers,vector<Place_Info>&inputPlaces,vector<drivers>&inputDrivers);

private:
	//References to the vectors containing the input data
	vector<customers>& listOfCustomers;
	vector<drivers>& listOfDrivers;
	vector<Place_Info>& listOfPlaces;

	int current = 0; //The index of the current customer in the input list
	int st = 0; //The index of the current starting location in the input list
	int dr = 0; //The index of the current driver in the input list
	vector<int> options; //The indices of the possible places
	double minDistance=1000000; //keeps track of the minimum distance 
	int fin = 0; //The index of the final location in the input list
	int menu; //This will keep track of which menu we are on or should be on

	//MENU 1
	//Variables to be shown for request ride screen
	string inputName = "";	//will change based on name input box
	string startPlace = "";	//will change based on start input box
	string finalPlace = ""; //will change based on final location input box
	Text requestRideName; //The title of the window
	Text nameWrong;	//warning that will show if the customer name is not found
	Text startWrong; //warning that will show if the start place is not found
	Text finalWrong; //warning that will show if the final place is not found
	Button back_button;  //Button to go to previous screen
	Button quit_button; //Button to quit the program
	In_box name_box; //Box to input the name of the person you are 
	In_box startPlace_box;  //Box to input the starting place
	In_box finalPlace_box; // Box to input the tag/name of final place
	Button proceed_button; //Button to continue with the program

	//The pictures for the customers at hand 
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
	Text driverLabel;	//Label for the driver image


	//All of the functions necessary for the window to work
	void menu1(); //This will show the widgets necessary for menu 1 to work 
	void menu2(); //This will show the widgets necessary for menu 2 to work
	void proceed_pressed(); //This will use the current state of the menu to decide what to display next
	void back_pressed(); //This will use the current state of the machine to either exit or go to previous menu
	void quit_pressed(); //This will automatically exit the window and go to the main menu

	//All of the callbacks necessary for the function
	static void cb_proceed(Address, Address);
	static void cb_back(Address, Address);
	static void cb_quit(Address, Address);
	
};
#endif
