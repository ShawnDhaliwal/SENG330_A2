//
//  main.cpp
//  SENG330_A2
//
//  Created by Shawn Singh Dhaliwal on 2015-11-11.
//  Copyright (c) 2015 Shawn Singh Dhaliwal. All rights reserved.
//
#include <vector>
#include <iostream>
using namespace std;
const int N = 4;


// Base class
class Machine
{
    public:
        virtual Machine* clone() const = 0;
        virtual void store() const = 0;
        virtual ~Machine() { }

    
    protected:
        int TotalTreadmills;
        int TotalElipticals;
};

// Concrete prototypes : Eliptical, Treadmill

class Eliptical : public Machine
{
    public:
        Machine*   clone() const { return new Eliptical; }
        void store() const {  }
};

class Treadmill : public Machine
{
    public:
        Machine* clone() const { return new Treadmill; }
        void store() const {  }
};

// makeMachine() calls Concrete Portotype's clone() method
// inherited from Prototype
class MachineManager {
    public:
        static Machine* makeMachine( int choice );
        ~MachineManager(){}
    
    private:
        static Machine* mMachineTypes[N];
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
    vector<Machine*> Mach(N);
    int choice;
    int x = 0;
    int y = 0;
    cout << "Type in 1 to add Treadmills \nType in 2 to add Elipticals \nType in 0 to finish\n";

    while (true) {
        cin >> choice;
        if (choice <= 0 || choice >= N)
            break;
            if(choice == 1)
                x = x + 1;
            if(choice == 2)
                y = y + 1;
        Mach[choice] = MachineManager::makeMachine( choice );
    }
    
    for (int i = 1; i < Mach.size(); ++i)
        if(Mach[i]) Mach[i]->store();
    
    cout << "Total Treadmills: " << x << endl;
    cout << "Total Elipticals: " << y << endl;
    Destruct d;
    // this calls Destruct::operator()
    for_each(Mach.begin(), Mach.end(), d);
    
    return 0;
}
