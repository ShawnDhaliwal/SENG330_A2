/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * Hello George!
 * This is my doxygen genreated browsable document of my SENG330 Assignment 2.
 * It includes descriptions of almost everything I can think of in my files.
 * I obviously can not take snapshots of every little bit of my documentation but I will try to get the 
 * point across that I have learned to use doxygen.
 *
 *
 */

/**
 * @file   main.cpp
 * @Author Shawn Dhaliwal
 * @date   Nov 11, 2015
 * @brief  Program uses prototype design pattern to create Machines and stores them.
 *
 * The user can either add an Elliptical or a Treadmill. They can then choose the name of the machine. Machines are continuously added until users types in Exit. Then all machines are printed out along with a numerical total.
 */

/*! \namespace SENG330_A2
 \brief My project.
 
 */

#include <vector>
#include <iostream>
#include <string>
#include "functions.h"
#include "A2.pb.h"
using namespace std;


//!  This is the one and only base class. It has two derived classes called Treadmill and Elliptical.
/*!
 A more elaborate class description.
 */
class Machine
{
public:
    virtual Machine* clone() const = 0;
    //! Name of machine.
    /*! */
    string name;
    
    virtual void store() const = 0;
    //! This is the deconstructor for Machine class.
    /*!  */
    virtual ~Machine() { }
    //! This sets the name of the Machine.
    /*!  */
    void setName(string d){ name = d;}
    
};

//!  This class is a derived class of the Machine class.
/*!
 A more elaborate class description.
 */
class Elliptical : public Machine
{
public:
    Machine*   clone() const { return new Elliptical; }
    void store() const { cout << "Elliptical " << name <<endl;  }
    
};

//!  This class is a derived class of the Machine class.
/*!
 */
class Treadmill : public Machine
{
public:
    Machine* clone() const { return new Treadmill; }
    void store() const { cout << "Treadmill " << name <<endl; }
    
    
};


//!  This class has a function called makeMachine(). It calls Concrete Portotype's clone() method inherited from Prototype
/*!
 */
class MachineManager {
public:
    static Machine* makeMachine( int choice );
    ~MachineManager(){}
    
private:
    static Machine* mMachineTypes[1000];
};

//! Creates new Treadmill or new Elliptical.
/*!  */
Machine* MachineManager::mMachineTypes[] =
{
    0, new Treadmill, new Elliptical
};

/** Sends to MachineManager which machine to make */
//! Sends to MachineManager which machine to make.
/*! */
Machine* MachineManager::makeMachine( int choice )
{
    return mMachineTypes[choice]->clone();
}

//!  for_each op ().
/*!
 */
struct Destruct
{
    void operator()(Machine *a) const {
        delete a;
    }
};



int main(int argc, char* argv[]) {
    
    vector<Machine*> Mach(1000);
    int choice = -1;
    //!  Total Treadmills tracker().
    /*!
     */
    int TotalTreadmills = 0;
    //!  Total Ellipticals tracker().
    /*!
     */
    int TotalElipticals = 0;
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
    //!  Prints out total number of machines, as well as number of Treadmills and Ellipticals().
    /*!
     */
    cout << "\nTotal Machines: " << TotalElipticals+TotalTreadmills << endl;
    cout << "   -->Treadmills: " << TotalTreadmills << endl;
    cout << "   -->Ellipticals: " << TotalElipticals << endl;
    
    Destruct d;
    //!  This calls the Destruct::operator().
    /*!
     */
    for_each(Mach.begin(), Mach.end(), d);
    
    return 0;
}