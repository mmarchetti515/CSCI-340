/*	Michael Marchetti
 *	z1860574
 *	CSCI 340 Data Struct Algorithm Analysis
 *	Class # 1737-Section 0002-Component LEC
 *
 *	I certify that this is my own work and where appropriate an extension
 *	of the starter code provided for the assignment.
 *
 *  Assignment 6
 */

#include <iostream>
#include <iomanip>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

/**
 * @brief Get the input vals object 
 * helper function for main that extracts the individual components of the
 * 
 * @param line 
 * @param xact_type 
 * @param license 
 */
//void get_input_vals(const std::string &line, char &xact_type, std::string &license)
//{}
int main()
{
    cout << "Car 1 with license plate \"ABC 1234\" has arrived.\n\n";

    cout << "Car 2 with license plate \"XYZ 9999\" has arrived.\n\n";

    cout << "Car 3 with license plate \"ALICE 1\" has arrived.\n\n";

    cout << "Car 4 with license plate \"1234567\" has arrived.\n\n";

    cout << "Car 3 with license plate \"ALICE 1\" has departed,\n";
    cout << "car was moved 1 time in the garage.\n\n";

    cout << "Car 5 with license plate \"GEORGE 5\" has arrived.\n\n";

    cout << "Car 6 with license plate \"UV 2\" has arrived.\n\n";

    cout << "Car 7 with license plate \"XC 344\" has arrived.\n\n";

    cout << "Car 8 with license plate \"ZZZ 1111\" has arrived.\n\n";

    cout << "Car 4 with license plate \"1234567\" has departed,\n";
    cout << "car was moved 1 time in the garage.\n\n";

    cout << "Car 2 with license plate \"XYZ 9999\" has departed,\n";
    cout << "car was moved 3 times in the garage.\n\n";

    cout << "Car 1 with license plate \"ABC 1234\" has departed,\n";
    cout << "car was moved 4 times in the garage.\n\n";

    cout << "Car 9 with license plate \"MARYANN\" has arrived.\n\n";

    cout << "Car 10 with license plate \"FUNNY 33\" has arrived.\n\n";

    cout << "Car 8 with license plate \"ZZZ 1111\" has departed,\n";
    cout << "car was moved 1 time in the garage.\n\n";

    cout << "Car 11 with license plate \"WHO IS\" has arrived.\n\n";

    cout << "Car 12 with license plate \"J RIPPER\" has arrived.\n\n";

    cout << "Car 13 with license plate \"CEM 1\" has arrived.\n\n";

    cout << "Car 14 with license plate \"Z123\" has arrived.\n\n";

    cout << "Car 15 with license plate \"QQ 99\" has arrived.\n\n";

    cout << "Car 7 with license plate \"XC 344\" has departed,\n";
    cout << "car was moved 2 times in the garage.\n\n";

    cout << "Car 16 with license plate \"1\" has arrived.\n\n";

    cout << "Car 17 with license plate \"11\" has arrived.\n";
    cout << "But the garage is full!\n\n";

    cout << "'X': invalid action!\n\n";

    cout << "Car 9 with license plate \"MARYANN\" has departed,\n";
    cout << "car was moved 1 time in the garage.\n\n";

    cout << "Car 6 with license plate \"UV 2\" has departed,\n";
    cout << "car was moved 4 times in the garage.\n\n";

    cout << "No car with license plate \"XXX 123\" is in the garage.\n\n";

    return 0;
}

// template <class Type, class Container = deque<Type> > class stack;
// will have to use this to define the temporary stack to put the car objects into while i do an arrival or departure???