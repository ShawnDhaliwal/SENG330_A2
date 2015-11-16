/**
 * @file   functions.h
 * @Author Shawn Dhaliwal
 * @date   Nov 11, 2015
 * @brief  This file contains 3 functions that are used by my main.cpp file.
 *
 * One function gets the machinetype from user, the other gets the name if its in Elliptical, and the other gets the name if its a Treadmill.
 */

#ifndef SENG330_A2_common_h
#define SENG330_A2_common_h

#endif

// Returns the machine type the user wants to add
std::string MachineType(){
    std::string type;
    std::cout << "Do you want to add in Elliptical or Treadmill? \nType in Exit to end\n";
    std::cin >> type;
    
    return type;
}

//Returns the Name of the Elliptical
std::string EllipticalName(){
    std::string name;
    std::cout << "What is the name of the Elliptical?\n";
    std::cin >> name;
    
    return name;
}

//Returns the Name of the Treadmill
std::string TreadmillName(){
    std::string name;
    std::cout << "What is the name of the Treadmill?\n";
    std::cin >> name;
    
    return name;
}