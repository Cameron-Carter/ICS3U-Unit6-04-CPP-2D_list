// Copyright (c) Cameron Carter All rights reserved
//
// Created by: Cameron Carter
// Created on: June 2021
// This program finds the smallest of 10 random numbers

#include <iostream>
#include <random>


template<int row, int column>
float FindAverage(int (&twoDArray)[row][column]) {
    // This function averages the numbers

    // Declarations
    int total = 0;
    float average = 0;

    for (int rowCounter = 0; rowCounter < row; rowCounter++) {
        for (
            int columnCounter = 0; columnCounter < column; columnCounter++
        ) {
            total += twoDArray[rowCounter][columnCounter];
        }
        average = total / (row * column);
    }
    return average;
}


main() {
    // This function gets random numbers for a 2d array

    // Declaring variables
    int generatedNumber = 0;
    int total = 0;
    const int rows = 2;
    const int columns = 5;
    int twoDArray[rows][columns];
    float averageNumber;

    // Process and Output
    for (int rowCounter = 0; rowCounter < rows; rowCounter++) {
        for (int columnCounter = 0; columnCounter < columns; columnCounter++) {
            std::random_device rseed;
            std::mt19937 rgen(rseed());  // mersenne_twister
            std::uniform_int_distribution<int> idist(1, 50);
            generatedNumber = idist(rgen);
            twoDArray[rowCounter][columnCounter] = generatedNumber;
            std::cout << generatedNumber << " ";
        }
        std::cout << "\n";
    }
    // Calls FindAverage
    averageNumber = FindAverage(twoDArray);
    std::cout << "The average is " << averageNumber << std::endl;
    std::cout << "\nDone" << std::endl;
}
