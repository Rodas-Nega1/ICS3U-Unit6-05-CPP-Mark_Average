// Copyright (c) Rodas Nega All rights reserved.
//
// Created by: Rodas Nega
// Created on: Oct 2021
// This program uses a list to calculate a user's mark percentages
//  and outputs their average


#include <iostream>
#include <list>


int CalculateAverage(std::list<int> percentageList) {
    // this function calculates the average of percentages inside a list
    //  and rounds it off

    std::list<int> listSize;
    int sum = 0;
    int averageResult;

    // process
    for (int aSingleElement : percentageList) {
        sum += aSingleElement;
    }
    averageResult = sum / percentageList.size();

    return averageResult;
}

int main() {
    // this function creates a list and lets the user enter as many marks as
    //  they want until they use '-1' to end the prompts and call a function
    //  that calculates their average

    std::list<int> percentages;
    std::string tempPercentages = "";
    int tempPercentagesInt;
    int calculatedAverage;

    // input
    std::cout << "Enter your mark percentages."
    << " Then enter -1 to find the average." << std::endl;
    std::cout << "" << std::endl;

    std::cout << "Mark (%) ";
    std::cin >> tempPercentages;

    // output
    try {
        tempPercentagesInt = std::stoi(tempPercentages);
        percentages.push_back(tempPercentagesInt);
        if (tempPercentagesInt < -1) {
            std::cout << "\nThe last mark you wrote makes no sense."
            << std::endl;
        } else if (tempPercentagesInt > 100) {
            std::cout << "\nThe last mark you wrote makes no sense."
            << std::endl;
        } else {
            while (true) {
                if (tempPercentagesInt < -1) {
                    std::cout << "\nThe last mark you wrote makes no sense."
                    << std::endl;
                    break;
                }
                if (tempPercentagesInt > 100) {
                    std::cout << "\nThe last mark you wrote makes no sense."
                    << std::endl;
                    break;
                }
                if (tempPercentagesInt == -1) {
                    break;
                }
                std::cout << "Mark (%) ";
                std::cin >> tempPercentages;
                tempPercentagesInt = std::stoi(tempPercentages);
                percentages.push_back(tempPercentagesInt);
            }
            percentages.pop_back();
            calculatedAverage = CalculateAverage(percentages);
            std::cout << "\nYour average percentage is " << calculatedAverage
            << "%" << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "\nThat is an invalid percentage.";
    }
    std::cout << "" << std::endl;
    std::cout << "\nDone." << std::endl;
}
