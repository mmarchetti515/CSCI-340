
#include "josephus.h"

#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <getopt.h>


// void print_underlined_string(const string &message);
// void print_list(const list<string> &collection, const unsigned &eliminations, int num_cols);


/**
* Print a 'Usage' message and exit(1).
*
* @param a0 The name of the command to include in the usage message.
*****************************************************************************/
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-n number of people] [-m modulus] [-p print frequency] [-c print columns]" << std::endl;
    exit(1);
}


/**
* Create a std::list of prople with generated ID/names and reduce the
* list as per the Josephus problem algorithm.
*****************************************************************************/
int main(int argc, char **argv)
{
    unsigned num_people = 41;       // The number of people to start with
    unsigned modulus = 3;           // The count used to determine the elimination
    unsigned print_frequency = 13;  // How often to print the state of the system
    unsigned num_cols = 12;         // Number of colums to print per line

    int opt;
    while ((opt = getopt(argc, argv, "n:m:p:c:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            std::istringstream(optarg) >> num_people;
            break;
        case 'm':
            std::istringstream(optarg) >> modulus;
            break;
        case 'p':
            std::istringstream(optarg) >> print_frequency;
            break;
        case 'c':
            std::istringstream(optarg) >> num_cols;
            break;
        default:
            usage(argv[0]);
        }
    }

    if (optind < argc)
        usage(argv[0]); // If we get here, there was extra junk on command line






  return 0;
}
