#include "std_lib_facilities_4.h"
#include "Graphics/Simple_window.h"
#include "Graphics/Graph.h"
#include "AddMoney.h"
#include <cmath>

paymentWindow::paymentWindow(Point xy, int w, int h, const string& title, vector<customers>& inputCustomers, vector<Place_Info>& inputPlaces, vector<drivers>& inputDrivers) : Window(xy, w, h, title),
//Initializes all of the referenced vectors
listOfCustomers(inputCustomers),
listOfDrivers(inputDrivers),
listOfPlaces(inputPlaces),
//Initializes all of the buttons to their proper locations
back_button(Point(0, 0), 70, 20, "Back", cb_back),
quit_button(Point(x_max() - 70, 0), 70, 20, "Exit", cb_quit),
proceed_button(Point(x_max() / 2 - 35, y_max() * 3 / 4), 70, 20, "Proceed", cb_proceed),
//Initializing the in boxes to their proper locations
name_box(Point(100, 100), 70, 20, "Name"),
added_box(Point(100, 150), 70, 20, "Deposit"),
//Initializing all of the text objects that will eventually need to be used
//Set the ones for menu 2 equal to "" so they don't show
makePaymentName(Point(120, 50), "Make Payment"),
notWorking(Point(100, 200), ""),
confirmPaymentName(Point(110, 50), ""),
confirmation_text(Point(100, 200), ""),
confirmation_text2(Point(200,216),"")
{
	//Attach all of the necessary buttons and widgets
	attach(back_button);
	attach(quit_button);
	attach(proceed_button);
	attach(name_box);
	attach(added_box);
	attach(makePaymentName);
	attach(notWorking);
	attach(confirmPaymentName);
	attach(confirmation_text);
	attach(confirmation_text2);
	//Change the font size for titles
	makePaymentName.set_font_size(45);
	confirmPaymentName.set_font_size(45);
	//Set the menu equal to 1
	menu=1;
}
//Function that will display everything necessary for menu 1
void paymentWindow::menu1() {
	//make sure the menu is at 1
	menu = 1;
	//Change the text objects so that they show the proper values necessary
	makePaymentName.set_label("Make Payment");
	confirmPaymentName.set_label("");
	confirmation_text.set_label("");
	confirmation_text2.set_label("");
	//Redraw the window to update the text objects
	redraw();
	//Show the boxes necessary for menu 1
	name_box.show();
	added_box.show();
}
//Function that will display everything necessary for menu 2
void paymentWindow::menu2() {
	//make sure the menu is at 2
	menu = 2;
	//Change all of the text objects to what they should show
	makePaymentName.set_label("");
	confirmPaymentName.set_label("Confirm Payment");
	notWorking.set_label("");
	//Hide the previous boxes
	name_box.hide();
	added_box.hide();
	//Redraw to make the text objects update
	redraw();
}
//Function that will use the current menu state to change variables
void paymentWindow::proceed_pressed() {
	//Two possible situations,
	//1: proceed is pressed on the make payment (menu 1);
	//2: proceed is pressed at the confirmation menu (menu 2);
	if (menu == 2) {
		//If proceed is pressed at confirmation menu then add the deposit to the customers account
		listOfCustomers[currCustomer].makePayment(moneyAdded);
		//get rid of this window and go back to the main menu.
		hide();
	}
	else
	{
		//Check to see if the name is actually the name of a customer
		inputName = name_box.get_string();
		moneyAdded = stod(added_box.get_string());
		stringstream ss;
		bool isCorrect = false;
		for (int i = 0; i<listOfCustomers.size(); i++) {
			if (listOfCustomers[i].getName() == inputName) {
				currCustomer = i;
				isCorrect = true;
			}
		}

		//If the customer does not exist, go back to menu 1 and tell them
		if (!isCorrect) {
			menu = 1;
			ss << "The customer " << inputName << " can not be found in the system";
			notWorking.set_label(ss.str());
			menu1();
		}
		//Otherwise go to confirmation screen
		else {
			ss << "The customer is " << listOfCustomers[currCustomer].getName() << " and has a current account balance of " << listOfCustomers[currCustomer].getAccountBalance();
			confirmation_text.set_label(ss.str());
			notWorking.set_label("");
			confirmation_text2.set_label("Are you sure you want to continue?");
			menu = 2;
			menu2();
		}
	}

}
//Uses the current state of the machine to either exit or go back to the previous menu
void paymentWindow::back_pressed() {
	//Again we have two options, either its at menu 1 or menu 2
	//If it is at menu 1, it should exit
	if (menu == 1) hide();
	//If it is at menu 2, it should set all of the inputs back to 0 and go to the first menu
	currCustomer = 0;
	moneyAdded = 0;
	inputName = "";
	menu = 1;
	menu1();
}
//Exits the program at any time
void paymentWindow::quit_pressed() {
	hide();
}

//All of the callbacks necessary
void paymentWindow::cb_quit(Address, Address pw) {
	reference_to<paymentWindow>(pw).quit_pressed();
}
void paymentWindow::cb_proceed(Address, Address pw) {
	reference_to<paymentWindow>(pw).proceed_pressed();
}
void paymentWindow::cb_back(Address, Address pw) {
	reference_to<paymentWindow>(pw).back_pressed();
}
