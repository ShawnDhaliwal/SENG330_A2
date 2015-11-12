//
//  main.cpp
//  SENG330_A2
//
//  Created by Shawn Singh Dhaliwal on 2015-11-11.
//  Copyright (c) 2015 Shawn Singh Dhaliwal. All rights reserved.
//

#include <iostream>

using namespace std;

// Base class
class Machine
{
    public:
  
    protected:
        int TotalTreadmills;
        int TotalElipticals;
};

// Derived class
class Treadmill: public Machine
{
    public:
        void addTreadmills(int x)
        {
            TotalTreadmills = TotalTreadmills + x;
        }
        int TotalTreads(){
            return TotalTreadmills;
        }
};

// Derived class
class Eliptical: public Machine
{
    public:
        void addElipticals(int x)
        {
            TotalElipticals = TotalElipticals + x;
        }
        int TotalElip(){
            return TotalElipticals;
        }
};




int main(int argc, const char * argv[]) {

    std::cout << "Lets start SENG330-A2 Assignment\n";
    Eliptical Elip;
    Treadmill Tread;
    Elip.addElipticals(5);
    Tread.addTreadmills(7);
    cout << "Total Elipticals: " << Elip.TotalElip() << endl;
    cout << "Total Treadmills: " << Tread.TotalTreads();

    
    return 0;
}
