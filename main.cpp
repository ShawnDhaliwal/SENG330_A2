//
//  main.cpp
//  SENG330_A2
//
//  Created by Shawn Singh Dhaliwal on 2015-11-11.
//  Copyright (c) 2015 Shawn Singh Dhaliwal. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include "common.h"
using namespace std;


// Base class
class Machine
{
public:
    virtual Machine* clone() const = 0;
    string name;
    virtual void store() const = 0;
    virtual ~Machine() { }
    void setName(string d){ name = d;}
    
};

// Concrete prototypes and Derived classes : Eliptical, Treadmill

class Elliptical : public Machine
{
public:
    Machine*   clone() const { return new Elliptical; }
    //void setName(string d){ name = d;}
    void store() const { cout << "Elliptical " << name <<endl;  }
    
};


class Treadmill : public Machine
{
public:
    Machine* clone() const { return new Treadmill; }
    //  void setName(string d){ name = d;}
    void store() const { cout << "Treadmill " << name <<endl; }
    
    
};

// makeMachine() calls Concrete Portotype's clone() method
// inherited from Prototype
class MachineManager {
public:
    static Machine* makeMachine( int choice );
    ~MachineManager(){}
    
private:
    static Machine* mMachineTypes[1000];
};


Machine* MachineManager::mMachineTypes[] =
{
    0, new Treadmill, new Elliptical
};

Machine* MachineManager::makeMachine( int choice )
{
    return mMachineTypes[choice]->clone();
}

// for_each op ()
struct Destruct
{
    void operator()(Machine *a) const {
        delete a;
    }
};



// Client interacts here.
int main(int argc, char* argv[]) {
    
    vector<Machine*> Mach(1000);
    int choice = -1;               //Client chooses machine to add into gym.
    int TotalTreadmills = 0;      //Keeps track of the number of treadmills.
    int TotalElipticals = 0;      //Keeps track of the number of elipticals
    string name;
    string add;
    
    int i = 0;
    while (true) {
        add = MachineType();
        i = i + 1;
        if (add == "exit" || add == "Exit"){
            choice = 0;
            cout <<"\n";
            break;
        }
        if(add == "Treadmill" || add == "treadmill"){
            TotalTreadmills = TotalTreadmills + 1;
            choice = 1;
            name = TreadmillName();
        }
        if(add == "Elliptical" || add == "elliptical"){
            TotalElipticals = TotalElipticals + 1;
            choice = 2;
            name = EllipticalName();
        }
        cout << "\n";
        if(choice != -1){
            Mach[i] = MachineManager::makeMachine( choice );
            Mach[i]->setName(name);
            choice = -1;
        }
        else{ cout <<"Invalid machine. You can not add that machine or you have a spelling error. You can add a Treadmill or an Elliptical\n" <<endl;}
    }
    
    for (int i = 1; i < Mach.size(); ++i){
        if(Mach[i]) Mach[i]->store();
    }
    //Print out total number of machines, as well as number of Treadmills and Elipticals.
    cout << "\nTotal Machines: " << TotalElipticals+TotalTreadmills << endl;
    cout << "   -->Treadmills: " << TotalTreadmills << endl;
    cout << "   -->Ellipticals: " << TotalElipticals << endl;
    
    Destruct d;
    // this calls Destruct::operator()
    for_each(Mach.begin(), Mach.end(), d);
    
    return 0;
}