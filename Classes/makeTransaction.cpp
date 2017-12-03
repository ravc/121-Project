#include "std_lib_facilities_4.h"
#include "Graphics/Simple_window.h"
#include "Graphics/Graph.h"
#include "makeTransaction.h"
#include <cmath>

rideWindow::rideWindow(Point xy, int w, int h, const string& title, vector<customers>&inputCustomers, vector<Place_Info>&inputPlaces, vector<drivers>&inputDrivers) : Window(xy, w, h, title),
//All of the references to the input data
listOfCustomers(inputCustomers),
listOfPlaces(inputPlaces),
listOfDrivers(inputDrivers),

//All of the buttons necessary for the windows to run
back_button(Point(0, 0), 70, 20, "Back", cb_back),
quit_button(Point(x_max() - 70, 0), 70, 20, "Exit", cb_quit),
proceed_button(Point(x_max() / 2 - 35, 370), 70, 20, "Proceed", cb_proceed),

//All of the in boxes necessary to take in the information
name_box(Point(200, 100), 70, 20, "Customer Name:"),
startPlace_box(Point(200, 125), 70, 20, "Name of Starting Place:"),
finalPlace_box(Point(200, 150), 70, 20, "Name/Tag of Final Place:"),

//All of the text objects necessary for labels and showing errors
nameWrong(Point(100,300),""),
startWrong(Point(100,330),""),
finalWrong(Point(100,360),""),
requestRideName(Point(150,60),"Request Ride"),
confirmTransactionName(Point(75,60),""),
customerLabel(Point(50,95),""),
startPlaceLabel(Point(325,95),""),
destinationLabel(Point(470,95),""),
driverLabel(Point(208,95),"")
{
	//Attach all of the widgets necessary to run the window
	attach(back_button);
	attach(quit_button);
	attach(proceed_button);
	attach(name_box);
	attach(startPlace_box);
	attach(finalPlace_box);
	attach(nameWrong);
	attach(startWrong);
	attach(finalWrong);
	attach(requestRideName);
	attach(confirmTransactionName);
	attach(customerLabel);
	attach(startPlaceLabel);
	attach(destinationLabel);
	attach(driverLabel);
	requestRideName.set_font_size(45);
	confirmTransactionName.set_font_size(45);
	menu=1;
}
//Will show the necessary widgets for menu 1
void rideWindow::menu1() {
	//Make sure the menu is set to 1
	menu = 1;
	//reset the minimum distance for the searching algorithm used later
	minDistance = 5000000;
	//The Back,Exit, and Proceed buttons are visible all the time
	//Show the stuff necessary
	requestRideName.set_label("Request Ride");
	name_box.show();
	startPlace_box.show();
	finalPlace_box.show();
	//Hide the previous stuff
	detach(*customerPic);
	detach(*startPic);
	detach(*finalPic);
	detach(*driverPic);
	confirmTransactionName.set_label("");
	customerLabel.set_label("");
	startPlaceLabel.set_label("");
	destinationLabel.set_label("");
	driverLabel.set_label("");
	//Redraw the entire GUI
	redraw();
}
//Will show the necessary widgets for menu 2
void rideWindow::menu2() {
	//Make sure the menu is set to 2
	menu = 2;
	//The Back, Exit, and Proceed buttons are visible all the time 
	//Show the stuff necessary
	confirmTransactionName.set_label("Confirm Transaction");
	customerLabel.set_label("Customer");
	startPlaceLabel.set_label("Starting Place");
	destinationLabel.set_label("Destination");
	driverLabel.set_label("Driver");
	//Hide the previous stuff
	requestRideName.set_label("");
	name_box.hide();
	startPlace_box.hide();
	finalPlace_box.hide();
	//Redraw the entire GUI
	redraw();
}
//Will use the current state of the menu to take in input and change the state
void rideWindow::proceed_pressed() {
	//Two possible situations,
	//1: proceed is pressed on the request ride menu (menu 1);
	//2: proceed is pressed at the confirmation menu (menu 2);
	if (menu == 2) {
		//Process the transaction (transfer the money)
		listOfDrivers[dr].changeLocation(listOfPlaces[fin].getLocation());
		listOfDrivers[dr].addMoney(minDistance*.5);
		listOfCustomers[current].addAmountOwed(minDistance);
		hide();
	}
	else
	{
		//Get all of the inputs from the in boxes
		inputName = name_box.get_string();
		startPlace = startPlace_box.get_string();
		finalPlace = finalPlace_box.get_string();
		stringstream ss;
		//variables necessary for error throwing later on
		bool nameCorrect = false;
		bool startCorrect = false;
		bool finalCorrect = false;
		//Check to see if the customer given exists in the list
		for (int i = 0; i<listOfCustomers.size(); i++) {
			if (listOfCustomers[i].getName() == inputName) {
				current = i;
				nameCorrect = true;
			}
		}
		//Check to see if the start location exists
		for (int i = 0; i<listOfPlaces.size(); i++) {
			if (listOfPlaces[i].getName() == startPlace) {
				st = i;
				startCorrect = true;
			}
		}
		//Check to see if the final location exists
		for (int j = 0; j<listOfPlaces.size(); j++) {
			if (listOfPlaces[j].getName() == finalPlace) {
				options.push_back(j);
				cout << "j: " << j;
				finalCorrect = true;
			}
			//If it is a tag, then push back all possible places that contain that tag
			for (int k = 0; k<listOfPlaces[j].getTags().size(); k++) {
				if (listOfPlaces[j].getTags()[k] == finalPlace) {
					options.push_back(j);
					finalCorrect = true;
				}
			}
		}
		//Set error labels to empty
		finalWrong.set_label("");
		startWrong.set_label("");
		nameWrong.set_label("");
		//If something is wrong, show the warning message then go back to menu 1
		if (!nameCorrect || !startCorrect || !finalCorrect) {
			if (!nameCorrect)
				nameWrong.set_label("The name listed could not be found");
			if (!startCorrect)
				startWrong.set_label("The start location given could not be found");
			if (!finalCorrect)
				finalWrong.set_label("The final location given could not be found");
			menu1();
		}
		//If all inputs are ok, then continue with the program. 
		else {
			//Figure out which matching destination is closest
			for (int i = 0; i<options.size(); i++) {
				double temp =listOfPlaces[st].getLocation().getDistance(listOfPlaces[st].getLocation(), listOfPlaces[options[i]].getLocation());
				if (temp<minDistance) {
					minDistance = temp;
					fin = options[i];
				}
			}
			//Figure out the closest driver
			double driverDist = 5000000;
			for (int i = 0; i<listOfDrivers.size(); i++) {
				if (listOfDrivers[i].getCurrentLocation().getDistance(listOfDrivers[i].getCurrentLocation(), listOfPlaces[st].getLocation())<driverDist) {
					dr = i;
					driverDist = listOfDrivers[i].getCurrentLocation().getDistance(listOfDrivers[i].getCurrentLocation(), listOfPlaces[st].getLocation());
				}
			}
			//Set all of the images for displaying
			customerPic = new Image(Point(40, 100), listOfCustomers[current].image());
			driverPic = new Image(Point(180, 100), listOfDrivers[dr].image());
			startPic = new Image(Point(320, 100), listOfPlaces[st].image());
			finalPic = new Image(Point(460, 100), listOfPlaces[fin].image());
			//resize the images as necessary
			customerPic->resize(100, 200);
			startPic->resize(100, 200);
			finalPic->resize(100, 200);
			driverPic->resize(100, 200);
			//Attach the pictures
			attach(*customerPic);
			attach(*startPic);
			attach(*finalPic);
			attach(*driverPic);
			//proceed to menu 2
			menu2();
		}
	}

}

//Will use the state of the menu to either close or go to previous menu
void rideWindow::back_pressed() {
	//Again we have two options, either its at menu 1 or menu 2
	//If it is at menu 1, it should exit
	//If it is at menu 2, it should set all of the inputs back to 0 and go to the first menu
	if (menu == 1) {
		hide();
	}
	else {
		menu1();
	}
}

//Will automatically close the window and go back to the main menu
void rideWindow::quit_pressed() {
	hide();
}

//All of the callbacks necessary to link the widgets
void rideWindow::cb_quit(Address, Address pw) {
	reference_to<rideWindow>(pw).quit_pressed();
}
void rideWindow::cb_proceed(Address, Address pw) {
	reference_to<rideWindow>(pw).proceed_pressed();
}
void rideWindow::cb_back(Address, Address pw) {
	reference_to<rideWindow>(pw).back_pressed();
}

