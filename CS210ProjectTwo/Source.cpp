
#include "Header.h"
#include <iostream>
#include <iomanip>


using namespace std;

double initialInvestAmount;
double currentBalance;
double monthlyDeposit;
double annualInterest;
int numYears;


// Header template for data input
void displayInfoHeader() {

	cout << endl;

	for (int i = 0; i < 34; i++) {
		cout << "*";
	}

	cout << endl;

	for (int i = 0; i < 34; i++) {

		if (i == 9) {
			cout << " Data Input ";
			i = 21;
		}

		cout << "*";
	}

	cout << endl;
};

// Body template for data input
void displayInfoBody() {

	displayInfoHeader();
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
};

// Run program, takes user inputs and updates data input with information, runs both with and without calculation tables
void runProgram() {

	
	displayInfoBody();

	cout << endl << "Please enter initial investment amount ";
	cin >> initialInvestAmount;
	currentBalance = initialInvestAmount;
	cout << endl;

	displayInfoHeader();
	cout << "Initial Investment Amount: $" << initialInvestAmount << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;

	cout << endl << "Please enter monthly deposit ";
	cin >> monthlyDeposit;
	cout << endl;

	displayInfoHeader();;
	cout << "Initial Investment Amount: $" << initialInvestAmount << endl;
	cout << "Monthly Deposit: $" << monthlyDeposit << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;

	cout << endl << "Please enter annual interest ";
	cin >> annualInterest;
	cout << endl;

	displayInfoHeader();
	cout << "Initial Investment Amount: $" << initialInvestAmount << endl;
	cout << "Monthly Deposit: $" << monthlyDeposit << endl;
	cout << "Annual Interest: %" << annualInterest << endl;
	cout << "Number of years: " << endl;

	cout << endl << "Please enter number of years for investment ";
	cin >> numYears;
	cout << endl;

	displayInfoHeader();
	cout << "Initial Investment Amount: $" << initialInvestAmount << endl;
	cout << "Monthly Deposit: $" << monthlyDeposit << endl;
	cout << "Annual Interest: %" << annualInterest << endl;
	cout << "Number of years: " << numYears << endl;

	calculateBalanceWithoutMonthlyDeposit(initialInvestAmount, annualInterest, numYears);
	balanceWithMonthlyDeposit(initialInvestAmount, monthlyDeposit, annualInterest, numYears);

}

// Header template for with deposit table
void displayWithDepositTableHeader() {

	cout << endl << "    " << "Balance and Interest With Additional Monthly Deposits" << endl;

	for (int i = 0; i < 62; i++) {
		cout << "=";
	}

	cout << endl;

	cout << left << setw(16) << " Year";
	cout << left << setw(22) << "Year End Balance";
	cout << left << setw(26) << "Year End Earner Interest";
	cout << endl;

	for (int i = 0; i < 62; i++) {
		cout << "_";
	}

	cout << endl;

}

// Header template for without deposit table
void displayWithoutDepositTableHeader() {

	cout << endl  << "    " << "Balance and Interest Without Additional Monthly Deposits" << endl;

	for (int i = 0; i < 62; i++) {
		cout << "=";
	}

	cout << endl;

	cout << left << setw(16) << " Year";
	cout << left << setw(22) << "Year End Balance";
	cout << left << setw(26) << "Year End Earner Interest";
	cout << endl;

	for (int i = 0; i < 62; i++) {
		cout << "_";
	}

	cout << endl;
};

// Print details to fill in table
void printDetails(int year, double yearEndBalance, double interestEarned) {
	cout << left << setw(16) << year << "$" << fixed << setprecision(2);
	cout << left << setw(22) << yearEndBalance << "$" << fixed << setprecision(2);
	cout << left << setw(26) << interestEarned << endl;
}

// Method to calculate monthly interest without additional deposit for the number of years entered and display it in table format
double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {

	double currBalance = 0.0;
	double interestEarnedThisYear = 0.0;
	double interestEarnedThisMonth = 0.0;
	double tempInterest = 0.0;
	currBalance = initialInvestment;

	  // convert interest from annual to monthly 
	tempInterest = ((interestRate / 100) / 12);

	displayWithoutDepositTableHeader();

	// loop for number of years
	for (int i = 1; i <= numberOfYears; i++) {
		interestEarnedThisYear = 0;

		// Loop to update account with interest per month
		for (int j = 1; j <= 12; j++) {

			if (tempInterest < 0.00001) {
				break;
			}

			interestEarnedThisMonth = currBalance * tempInterest;
			currBalance = currBalance + interestEarnedThisMonth;
			interestEarnedThisYear += interestEarnedThisMonth;

		}

		printDetails(i, currBalance, interestEarnedThisYear);

	}
	return 0;
}

// Method to calculate monthly interest with additional deposit for the number of years entered and display it in table format
double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {

	displayWithDepositTableHeader();

	double currBalance = 0.0;
	double interestEarnedThisYear = 0.0;
	double interestEarnedThisMonth = 0.0;
	double tempInterest = 0.0;
	currBalance = initialInvestment;

	interestRate = ((interestRate / 100) / 12);

	// loop for number of years
	for (int i = 1; i <= numberOfYears; i++) {
		interestEarnedThisYear = 0;

		// Loop to update account with interest per month
		for (int j = 1; j <= 12; j++) {

			if (interestRate < 0.001) {
				currBalance += (12 * monthlyDeposit);
				break;
			}

			tempInterest = currBalance * interestRate;
			currBalance = currBalance + monthlyDeposit + tempInterest;
			interestEarnedThisYear += tempInterest;

		}


		//
		printDetails(i, currBalance, interestEarnedThisYear);

	}
	return 0;
}
