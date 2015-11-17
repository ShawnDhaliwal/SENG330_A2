/**
 * @file   Test.cpp
 * @Author Shawn Dhaliwal
 * @date   Nov 15, 2015
 * @brief  This class has 4 test cases for main.cpp
 *
 * There are 4 test cases, one for each of the following: MachineType (treadmill and Elliptical), mahcine name Treadmill, macine name Elliptical. It uses Google testing framework to do the tests. Functions being tested are from common.h file.
 */


#include "gtest/gtest.h"
#include "functions.h"

//! The user types in Treadmill when prompted for Machine type, is the machine type returned by the MachineType() function actually a Treadmill?
/*! This test essentially prompts the user to enter Treadmill as machine type. It then checks if the MachineType Function actually returns the string Treadmill*/
TEST (SENG330_A2, MachineType_Equals_Treadmill)
{
 

    EXPECT_EQ("Treadmill",MachineType() );
    

}
//! The user types in Elliptical when prompted for Machine type, is the machine type returned by the MachineType() function actually an Elliptical?
/*! This test essentially prompts the user to enter Elliptical as machine type. It then checks if the MachineType Function actually returns the string Elliptical*/

TEST (SENG330_A2, MachineType_Equals_Elliptical)
{
    

    EXPECT_EQ("Elliptical",MachineType() );
    
    
}
//! If the user types in name for Treadmill, in this case T100, does the TreadmillName() function return the correct name?
/*! This test essentially prompts the user to enter T100 as machine name. It then checks if the TreadmillName() Function actually returns the string T100*/

TEST (SENG330_A2, Is_Treadmill_Name_T100)
{
    
    EXPECT_EQ("T100",TreadmillName() );
    
    
}

//! If the user types in name for Elliptical, in this case E100, does the EllipticalName() funciton return the correct name?
/*! This test essentially prompts the user to enter E100 as machine name. It then checks if the EllipticalName() Function actually returns the string E100*/
TEST (SENG330_A2, Is_Elliptical_Name_E100)
{
    
    EXPECT_EQ("E100",EllipticalName() );
    
    
}

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}