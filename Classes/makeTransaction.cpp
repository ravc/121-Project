#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "makeTransaction.h"
#include <cmath>

rideWindow::rideWindow(Point xy, int w, int h, const string& title) : Window(xy, w, h, title),
back_button(Point(0, 0), 70, 20, "Back", cb_back),
quit_button(Point(x_max() - 70, 0), 70, 20, "Exit", cb_quit),
proceed_button(Point(x_max() / 2 - 35, 370), 70, 20, "Proceed", cb_proceed),
name_box(Point(200, 100), 70, 20, "Customer Name:"),
startPlace_box(Point(200, 125), 70, 20, "Name of Starting Place:"),
finalPlace_box(Point(200, 150), 70, 20, "Name/Tag of Final Place:"),
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
void rideWindow::menu1() {
	menu = 1;
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
void rideWindow::menu2() {
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
void rideWindow::proceed_pressed() {
	//Two possible situations,
	//1: proceed is pressed on the request ride menu (menu 1);
	//2: proceed is pressed at the confirmation menu (menu 2);
	if (menu == 2) {
		//Process the transaction
		dr.changeLocation(fin.getLocation());
		dr.addMoney(minDistance*.5);
		current.addAmountOwed(minDistance);
		hide();
	}
	else
	{
		//Check to see if the name is actually the name of a customer
		inputName = name_box.get_string();
		startPlace = startPlace_box.get_string();
		finalPlace = finalPlace_box.get_string();
		stringstream ss;
		bool nameCorrect = false;
		bool startCorrect = false;
		bool finalCorrect = false;
		for (int i = 0; i<listOfCustomers.size(); i++) {
			if (listOfCustomers[i].getName() == inputName) {
				current = listOfCustomers[i];
				nameCorrect = true;
			}
		}

		for (int i = 0; i<listOfPlaces.size(); i++) {
			if (listOfPlaces[i].getName() == startPlace) {
				st = listOfPlaces[i];
				startCorrect = true;
			}
		}
		for (int j = 0; j<listOfPlaces.size(); j++) {
			if (listOfPlaces[j].getName() == finalPlace) {
				options.push_back(listOfPlaces[j]);
				finalCorrect = true;
			}
			for (int k = 0; k<listOfPlaces[j].getTags().size(); k++) {
				if (listOfPlaces[j].getTags()[k] == finalPlace) {
					options.push_back(listOfPlaces[j]);
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
				double temp = st.getLocation().getDistance(st.getLocation(), options[i].getLocation());
				if (temp<minDistance) {
					minDistance = temp;
					fin = options[i];
				}
			}
			//Figure out the correct driver
			double driverDist = 5000000;
			for (int i = 0; i<listOfDrivers.size(); i++) {
				if (listOfDrivers[i].getCurrentLocation().getDistance(listOfDrivers[i].getCurrentLocation(), st.getLocation())<driverDist) {
					dr = listOfDrivers[i];
					driverDist = listOfDrivers[i].getCurrentLocation().getDistance(listOfDrivers[i].getCurrentLocation(), st.getLocation());
				}
			}
			//Set all of the images for the next step
			customerPic = new Image(Point(40, 100), current.getPicture());
			driverPic = new Image(Point(180, 100), dr.getPicture());
			startPic = new Image(Point(320, 100), st.getPicture());
			finalPic = new Image(Point(460, 100), fin.getPicture());

			customerPic->resize(100, 200);
			startPic->resize(100, 200);
			finalPic->resize(100, 200);
			driverPic->resize(100, 200);
			attach(*customerPic);
			attach(*startPic);
			attach(*finalPic);
			attach(*driverPic);
			menu2();
		}
	}

}
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
void rideWindow::quit_pressed() {
	hide();
}
void rideWindow::cb_quit(Address, Address pw) {
	reference_to<rideWindow>(pw).quit_pressed();
}
void rideWindow::cb_proceed(Address, Address pw) {
	reference_to<rideWindow>(pw).proceed_pressed();
}
void rideWindow::cb_back(Address, Address pw) {
	reference_to<rideWindow>(pw).back_pressed();
}

int main() {
	cout << "Enter input file name: ";
	string ifname;
	cin >> ifname;
	ifstream ist{ ifname };
	if (!ist) error("Can't open input file ", ifname);
	int n;
	ist >> n;
	for (int l = 0; l<n; l++){
		string name;
		double a;
		double b;
		double c;
		string pic;
		ist >> name >> a >> b >> c >> pic;
		listOfDrivers.push_back(drivers(Geo_loc(b,c),name,a,pic));
	}
	ist>>n;
	for (int i = 0; i<n; i++) {
		string name;
		double balance;
		string picName;
		ist >> name >> balance >> picName;
		listOfCustomers.push_back(customers(name, balance,picName));
	}
	ist >> n;
	for (int j=0;j<n;j++){
		string a;
		string b;
		double c;
		double d;
		int m;
		ist >> a >> b >> c >> d;
		ist >> m;
		string e;
		vector<string> tags;
		for(int k=0;k<m;k++){
			ist >> e;
			tags.push_back(e);
		}
		string pic;
		ist >> pic;
		listOfPlaces.push_back(Place_info(a,b,tags,Geo_loc(c,d),pic));
	}
	while (true) {
		try {

			rideWindow win1(Point(100, 200), 600, 400, "Currency Menu");
			return gui_main();
		}
		catch (exception& e) {
			cerr << "exception: " << e.what() << '\n';
			break;
		}
		catch (...) {
			cerr << "Some exception\n";
			break;
		}
	}
}
