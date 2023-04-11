#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void displayStartupMessage();
bool login();
void displayMenu();
void displayTariffDetails();
void calculateBill();

int main(){
    displayStartupMessage();
    bool loggedIn = 0;
    int loginAttempts = 0;

    while (!loggedIn && loginAttempts < 3) {
        loggedIn = login();
        cout << "Incorrect username/password. Please try again." << endl;
        loginAttempts++;
    }

    system("cls");

    if (loggedIn == 1){
        displayMenu();
        char choice;
        do {
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        
        system("cls");

        switch(choice) {
            case '1':
                displayTariffDetails();
                break;
            case '2':
                calculateBill();
                break;
            case '3':
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
        // Prompt user to continue or exit
        if (choice != '3') {
            char continueChoice;
            do {
                cout << "Do you want to continue? (Y/N): ";
                cin >> continueChoice;
                cout << endl;
            } while (continueChoice != 'Y' && continueChoice != 'y' && continueChoice != 'N' && continueChoice != 'n');
            
            if (continueChoice == 'N' || continueChoice == 'n') {
                cout << "Exiting system..." << endl;
                break;
            }
            
            system("cls");
            // Display menu again
            displayMenu();
        }
    } while (choice != '3');
    }

    
    if (loggedIn == 0){
        cout << "Maximum login attempts reached. Exiting system." << endl;
    }

}

void displayStartupMessage() {
    cout << "*********************************************" << endl;
    cout << "*          UNITED SOLAR RENEWABLES           *" << endl;
    cout << "*                 Sri Lanka                  *" << endl;
    cout << "*********************************************" << endl;
    
    // Get current date and time
    time_t now = time(0);
    char* dateTime = ctime(&now);
    
    cout << "          " << dateTime <<"       "<< endl;
}

bool login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    // Check username and password against allowed users
    if (username == "Admin" && password == "Admin123") {
        return true;
    }
    else if (username == "Chidi" && password == "chidi@#USSL") {
        return true;
    }
    else if (username == "Asad" && password == "AK@#US") {
        return true;
    }
    else {
        return false;
    }
}

void displayMenu() {
    cout << "***********************" << endl;
    cout << "*       MAIN MENU      *" << endl;
    cout << "***********************" << endl;
    cout << "1. Electricity Tariff Details" << endl;
    cout << "2. Bill Calculator" << endl;
    cout << "3. Log Out" << endl; 
    }

void displayTariffDetails() {
    cout << endl << "Electricity Tariff Details:" << endl;
    cout << "-------------------------------" << endl;
    cout << "Consumer Category   Energy Charge for kWh   Fixed Price" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Residential         25.00                  150.00" << endl;
    cout << "Commercial          30.00                  200.00" << endl;
    cout << "Industrial          35.00                  300.00" << endl;
    cout << "-------------------------------------------------------" << endl;
}

void calculateBill() {
    string category;
    int units;
    double energyCharge, fixedPrice, totalBill;
    cout << "1.Residential" << endl;
    cout << "2.Commercial" << endl;
    cout << "3.Industrial" << endl;
    cout << "Please enter consumer category (Residential/Commercial/Industrial): ";
    cin >> category;
    cout << "Please enter number of units consumed: ";
    cin >> units;
    system("cls");
    // Set the energy charge and fixed price based on the consumer category
    if (category == "Residential" || category == "1") {
        energyCharge = 25.00;
        fixedPrice = 150.00;
        category = "Residential";
    } else if (category == "Commercial" || category == "2") {
        energyCharge = 30.00;
        fixedPrice = 200.00;
        category = "Commercial";
    } else if (category == "Industrial" || category == "3") {
        energyCharge = 35.00;
        fixedPrice = 300.00;
        category = "Industrial";
    } else {
        cout << "Invalid consumer category entered." << endl;
        return;
    }

    // Calculate the total bill
    totalBill = units * energyCharge + fixedPrice;

    // Display the bill
    cout << "        Consumer Category: " << category << endl;
    cout << " Number of Units Consumed: " << units << endl;
    cout << "    Energy Charge per kWh: " << energyCharge << endl;
    cout << "              Fixed Price: " << fixedPrice << endl;
    cout << "              Total Price: " << totalBill << endl;
}