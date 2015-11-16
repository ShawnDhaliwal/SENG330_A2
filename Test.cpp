//Four test cases for SENG330_A2.

#include "gtest/gtest.h"
#include "common.h"

TEST (SENG330_A2, MachineType_Equals_Treadmill)
{
 //The user types in Treadmill when prompted for Machine type, is the machine type returned by the MachineType() function actually a Treadmill?
    EXPECT_EQ("Treadmill",MachineType() );
    

}

TEST (SENG330_A2, MachineType_Equals_Elliptical)
{
    //The user types in Elliptical when prompted for Machine type, is the machine type returned by the MachineType() function actually an Elliptical?
    EXPECT_EQ("Elliptical",MachineType() );
    
    
}

TEST (SENG330_A2, Is_Treadmill_Name_T100)
{
    //If the user types in name for Treadmill, in this case T100, does the TreadmillName() function return the correct name?
    EXPECT_EQ("T100",TreadmillName() );
    
    
}

TEST (SENG330_A2, Is_Elliptical_Name_E100)
{
    //If the user types in name for Elliptical, in this case E100, does the EllipticalName() funciton return the correct name?
    EXPECT_EQ("E100",EllipticalName() );
    
    
}

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}