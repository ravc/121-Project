#ifndef AddMoney_H
#define AddMoney_H
#include "Geo_Loc.h"
#include "Place_Info.h"
#include "Driver.h"
#include "Customer.h"

struct paymentWindow : Graph_lib::Window {
	paymentWindow(Point xy, int w, int h, const string& title,vector<customers>& inputCustomers,vector<Place_Info>& inputPlaces,vector<drivers>& inputDrivers);

private:
	vector<customers>& listOfCustomers;
	vector<drivers>& listOfDrivers;
	vector<Place_Info>& listOfPlaces;
	//MENU 1
	//Variables to be shown for make payment screen
	int currCustomer = 0;
	string inputName = "";
	double moneyAdded = 0;
	int menu;
	Text makePaymentName;
	Button back_button;  //Button to go to previous screen
	Button quit_button; //Button to quit the program
	In_box name_box; //Box to input the name of the person you are 
	In_box added_box;  //Box to add money
	Button proceed_button; //Button to continue with the program
	Text notWorking;

	//MENU 2
	//Variables to be shown for make payment confirmation screen
	//Also should include back_button/quit_button/proceed_button
	Text confirmation_text;
	Text confirmation_text2;
	Text confirmPaymentName;

	//All of the functions necessary to make the window run
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