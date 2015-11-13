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

class Eliptical : public Machine
{
    public:
        Machine*   clone() const { return new Eliptical; }
        void setName(string d){ name = d;}
        void store() const { cout << "Eliptical " << name <<endl;  }

};


class Treadmill : public Machine
{
    public:
        Machine* clone() const { return new Treadmill; }
        void setName(string d){ name = d;}
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
    0, new Treadmill, new Eliptical
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

// Client
int main() {
    vector<Machine*> Mach(1000);
    int choice;     //Client choice machine to add into gym.
    int TotalTreadmills = 0;      //Keeps track of the number of treadmills.
    int TotalElipticals = 0;      //Keeps track of the number of elipticals
    string name;

    int i = 0;
    while (true) {
        cout << "What would you like to add? \nType in a 1 to add Treadmill or a 2 to add Eliptical.\n";
        cin >> choice;
        i = i + 1;
        if (choice <= 0){
            cout <<"\n";
            break;
        }
        if(choice == 1){
            TotalTreadmills = TotalTreadmills + 1;
            cout << "What is the name of the Treadmill?\n";
            cin >> name;
        }
        if(choice == 2){
            TotalElipticals = TotalElipticals + 1;
            cout << "What is the name of the Eliptical?\n";
            cin >> name;
        }
        cout << "\n";
        Mach[i] = MachineManager::makeMachine( choice );
        Mach[i]->setName(name);
    }
    
    for (int i = 1; i < Mach.size(); ++i){
        if(Mach[i]) Mach[i]->store();
    }
    
    cout << "\nTotal Machines: " << TotalElipticals+TotalTreadmills << endl;
    cout << "   -->Treadmills: " << TotalTreadmills << endl;
    cout << "   -->Elipticals: " << TotalElipticals << endl;
    Destruct d;
    // this calls Destruct::operator()
    for_each(Mach.begin(), Mach.end(), d);
    
    return 0;
}
