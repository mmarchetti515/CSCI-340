
/*	Michael Marchetti
 *	z1860574
 *	CSCI 340 Data Struct Algorithm Analysis
 *	Class # 1737-Section 0002-Component LEC
 *
 *	I certify that this is my own work and where appropriate an extension
 *	of the starter code provided for the assignment.
 *
 *  Assignment 7
 */

#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <iterator>
#include <utility>
#include <iomanip>
#include <fstream>
#include <algorithm>

using std::map;
using std::string;
using std::cout;
using std::cin;

class scanner
{
    public:

    // public function declaration
    void get_words(map<string, int>&);
    void print_words(const map<string, int>&);
    void clean_entry(const string&, string&);   

    // declare track here to allow it to be used in both main and 
    // get_words
    size_t track = 0; 

};