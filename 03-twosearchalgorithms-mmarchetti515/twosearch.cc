/*	
 *  Michael Marchetti
 *	z1860574
 *	CSCI 340 Data Struct Algorithm Analysis
 *	Class # 1737-Section 0002-Component LEC
 *
 *	I certify that this is my own work and where appropriate an extension
 *	of the starter code provided for the assignment.
 *
 *  Assignment 3
 */

#include "twosearch.h"

#include <getopt.h>
#include <vector>
#include <iterator>
#include <random>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>


/**
* see: 
* https://en.wikipedia.org/wiki/Usage_message
* https://www.ibm.com/docs/en/aix/7.2?topic=commands-usage-statements
*
* @param a0 The value of argv[0] (the name of the command) so that it 
*   can be printed.
*
* @note This function will terminate the application via exit(1).
******************************************************************************/
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-l rand_low] [-h rand_high] [-a a_size] [-b b_size] [-x a_seed] [-y b_seed] [-c print_cols] [-w col_width]" << std::endl;
    std::cerr << "    rand_low   = rand() low bound (default=1)" << std::endl;
    std::cerr << "    rand_high  = rand() high bound (default=1000)" << std::endl;
    std::cerr << "    a_size     = size of vector A (default=200)" << std::endl;
    std::cerr << "    b_size     = size of vector B (default=100)" << std::endl;
    std::cerr << "    a_seed     = random seed for vector A (default=1)" << std::endl;
    std::cerr << "    b_seed     = random seed for vector B (default=3)" << std::endl;
    std::cerr << "    print_cols = number of colums per line (default=16)" << std::endl;
    std::cerr << "    col_width  = printed column value width (default=4)" << std::endl;
    exit(1);
} // End of usage()

/**
* Parse the command-line args, create and sort vector A, create vector B,
* search vector A for those elements appearing in vector B using both
* a linear and binary search, and print the hit-rate (the percentage of 
* items in B that have been located in A.)
*
* If an invalid command-line arg is encountered, print a Usage statement 
* and terminte with an exit-status of 1.
*
* @return zero
******************************************************************************/
int main(int argc, char **argv)
{
    // Demonstrate the use of getopt() to override default config parameters 
    int rand_low = 1;
    int rand_high = 1000;
    int a_size = 200;
    int b_size = 100;
    int a_seed = 1;
    int b_seed = 3;
    int print_cols = 16;
    int col_width = 4;

    int opt;
    // see: http://faculty.cs.niu.edu/~winans/CS340/2022-sp/#getopt
    while ((opt = getopt(argc, argv, "a:b:c:h:l:w:x:y:")) != -1)
    {
        switch(opt)
        {
        case 'a':
            // see https://en.cppreference.com/w/cpp/string/basic_string/stol
            a_size = std::stoi(optarg); // override the default for a_size
            break;

        case 'b':
            b_size = std::stoi(optarg);
            break;
        case 'c':
            print_cols = std::stoi(optarg);
            break;
        case 'h':
            rand_high = std::stoi(optarg);
            break;
        case 'l':
            rand_low = std::stoi(optarg);
            break;
        case 'w':
            col_width = std::stoi(optarg);
            break;
        case 'x':
            a_seed = std::stoi(optarg);
            break;
        case 'y':
            b_seed = std::stoi(optarg);
            break;
            
        default:
            // got an arg that is not recognized...
            usage(argv[0]);     // pass the name of the program so it can print it
        }
    }

    // Make sure there are not any more arguments (after the optional ones)
    if (optind < argc)
        usage(argv[0]);

    // Add application logic here...


// beginning of student code below

/**
 * @brief Initialize the vector by assiging random values using the seed value. 
 * Generate a random a value between lo and hi by calling srand with seed as param.
 * 
 * Assign random values to the elements in vec by using the seed value. 
 * Initialize the random number generator by calling srand(seed) and then generate
 * a random number between lo and hi by using rand()%(hi-lo+1)+lo.
 *
 * @param vec 
 * @param seed 
 * @param lo 
 * @param hi 
 */
void init_vector(std::vector<int> &vec, int seed, int lo, int hi)
{
    int seed;
    srand(seed);
    vector<int> vec;
}

/**
 * @brief 
 * 
 * @param v 
 * @param print_cols 
 * @param col_width 
 */
void print_vector(const std::vector<int> &v, int print_cols, int col_width)
{

}

/**
 * @brief 
 * 
 * @param v 
 */
void sort_vector(std::vector<int> &v)
{

}

/**
 * @brief 
 * 
 * @param v1 
 * @param v2 
 * @param p 
 * @return int 
 */
int search_vector(const std::vector<int> &v1, const std::vector<int> &v2, bool (*p)(const std::vector<int> &, int))
{

}

/**
 * @brief 
 * 
 * @param found 
 * @param total 
 */
void print_stat(int found, int total)
{

}

/**
 * @brief 
 * 
 * @param v 
 * @param x 
 * @return true 
 * @return false 
 */
bool linear_search(const std::vector<int> &v, int x):
{
    bool found = false;

    

}

/**
 * @brief 
 * 
 * @param v 
 * @param x 
 * @return true 
 * @return false 
 */

bool binary_search(const std::vector<int> &v, int x)
{
    std::vector<int> &v;
    int low = 0;
    int high = v - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(x == array[mid])
        {
            return mid;
        }
        
        if(x < array[mid])
        {
            high = mid - 1;
        
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}



    return 0;

} // End of main()

