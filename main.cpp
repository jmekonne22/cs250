/* 
 * Name: Joseph Mekonnen
 * Course: CS 250
 * Program: Programming Assignment 1
 *
 * Description: 
 * program that prompts the user to enter the starting population, birth and death rates and the number of years to project. 
 * The program should then calculate and print the growth rate and the estimated population after each year. 
 */
#include <iostream>
using namespace std;

// Function to calculate population growth rate
double GrowthRate(double birthRate, double deathRate) {
    return birthRate - deathRate;
}

// Function to calculate estimated population for the next year
double EstimatedPopulation(double currentPopulation, double birthRate, double deathRate) {
    return currentPopulation + (birthRate * currentPopulation) / 100 - (deathRate * currentPopulation) / 100;
}

int main() {
    double startingPopulation, birthRate, deathRate;
    int numYears;

    // Input validation for starting population
    cout << "Enter starting population: ";
    cin >> startingPopulation;
    if (startingPopulation < 2) {
        cout << "Starting population must be >= 2." << endl;
    }

    // Input validation for birth rate
    cout << "Enter birth rate: ";
    cin >> birthRate;
    if (birthRate < 0) {
        cout << "Birth rate must be >= 0." << endl;
    }

    // Input validation for death rate
    cout << "Enter death rate: ";
    cin >> deathRate;
    if (deathRate < 0) {
        cout << "Death rate must be >= 0." << endl;
    }

    cout << "Enter number of years to project: ";
    cin >> numYears;

    for (int year = 1; year <= numYears; year++) {
        double growth = GrowthRate(birthRate, deathRate);
        double estimatedPop = EstimatedPopulation(startingPopulation, birthRate, deathRate);

        cout << "Year " << year << ": Growth Rate = " << growth << "%, Estimated Population = " << estimatedPop << endl;

        startingPopulation = estimatedPop;
    }

    return 0;
}
