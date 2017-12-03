#ifndef AddMoney_H
#define AddMoney_H
#include "Geo_Loc.h"
#include "Place_Info.h"
#include "Driver.h"
#include "Customer.h"

struct paymentWindow : Graph_lib::Window {
	paymentWindow(Point xy, int w, int h, const string& title,vector<customers>& inputCustomers,vector<Place_Info>& inputPlaces,vector<drivers>& inputDrivers);

private:
	//References to the vectors that contain all of the customers/drivers/places
	vector<customers>& listOfCustomers;
	vector<drivers>& listOfDrivers;
	vector<Place_Info>& listOfPlaces;

	//MENU 1
	//Variables to be shown for make payment screen
	int currCustomer = 0; //A number to represent the location of the customer in the referenced list
	string inputName = ""; //Will be changed based on name in box
	double moneyAdded = 0; //Will be changed based on deposit in box
	int menu; //This variable will be used to keep track of which menu the system is currently on.
	Text makePaymentName; //Text for the make payment name
	Button back_button;  //Button to go to previous screen
	Button quit_button; //Button to quit the program
	In_box name_box; //Box to input the name of the person you are 
	In_box added_box;  //Box to add money
	Button proceed_button; //Button to continue with the program
	Text notWorking; //This is the text that is going to describe any errors that we get

	//MENU 2
	//Variables to be shown for make payment confirmation screen
	//Also should include back_button/quit_button/proceed_button
	Text confirmation_text;	//Text that ask would you like to confirm
	Text confirmation_text2; //Second line of the confirmation text
	Text confirmPaymentName; // Text that outputs the confirmation name

	//All of the functions necessary to make the window run
	void menu1();	//This function will display all of the stuff for menu 1
	void menu2();	//This function will display all of the stuff for menu 2
	void proceed_pressed();	//This function will use the current state of the menu to change certain options
	void back_pressed();	//This function will use the current state of the menu to either go back to previous menu or exit 
	void quit_pressed();	//This funciton will automaticallly close the window and send you to the main menu.
	
	//All of the callbacks that are necessary
	static void cb_proceed(Address, Address); 
	static void cb_back(Address, Address);
	static void cb_quit(Address, Address);
};
#endif