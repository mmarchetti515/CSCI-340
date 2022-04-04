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

#include "wordscanner.h"

/**
 * @brief main function, executes all helper functions 
 * 
 * @return int returns 0 on success
 */
int main()
{
    // declare myscanner object of scanner class
    scanner myscanner;

    // initialize map struct map1 where key is string
    // and value is int
    map<string, int> map1;

    // call get words through myscanner object with map1 param
    // to retrieve words from input file (cin)
    myscanner.get_words(map1);

    // call print words through myscanner object with map1 param
    // to print words after they have been retrieved and cleaned
    myscanner.print_words(map1);

    // successful return
    return 0;
}


/**
 * @brief This function discerns words from whitespace and 
 * pulls those words from the input stream. It calls clean_entry
 * to remove uppercase letters and punctuation and also tracks 
 * number of words in the input stream.
 * 
 * @param map1 map data structure declared in scanner class
 */
void scanner::get_words(map<string, int>&map1)
{
    // declare string is for instream
    string is;

    // check for input stream
    while (cin >> is)
    {
        // call clean entry with the instream as 
        // arguments
        clean_entry(is, is);

        // check for whitespace
        if(is.length() == 0)
        {
            continue;
            track++;
        }
        // check for words
        else if(is.length() > 0)
        {
            map1[is]++;
            track++;
        }
    }
};

/**
 * @brief This function cleans the alphanumeric character
 * obtained from the input stream by making every character 
 * lowercase, and removing all punctuation
 * 
 * @param intial_string the original word from the input stream
 * @param cleaned_string the same word after cleaning
 */
void scanner::clean_entry(const string& intial_string, string& cleaned_string)
{
    string::const_iterator itr1;

    string::const_iterator itr2;

    // uses itr1 to iterate through the initial string, and find all alphanumeric
    // characters
    itr1 = std::find_if(intial_string.begin(), intial_string.end(), [](char x)
        {
            return isalnum(x);
        });

    // uses itr2 to iterate through the results of itr1 and returns non-
    // alphanumeric characters as false
    itr2 = std::find_if(itr1, intial_string.end(), [](char y)
        {
            return !isalnum(y);
        });

    // declare new_string with param itr1, itr2 to prepare 
    // for post for_each function
    string new_string(itr1, itr2);

    /**
     * @brief This will convert all capital letters in the cleaned word
     * to lowercase letters using a lambda expression as the third 
     * argument. This allows for more consice code.
     */
    for_each(new_string.begin(), new_string.end(), [](char &z)
        {
            // c library function islower() checks for lowercase letters
            // to prepare for switching to lowercase
            if (islower(z) == false)
            {
                // when false/ uppercase, perform tolower c library 
                // function to make k lowercase
                z = tolower(z);
            }
        });
    // this is the reference to the second string being set 
    // to the new_string created earlier
    cleaned_string = new_string;
};

/**
 * @brief Prints the final list of words and their frequencies, the number
 * of nonempty words, and the number of distinct words in the input stream
 * 
 * @param map1 reference to map data structure declared in class scanner
 */
void scanner::print_words(const map<string, int>&map1)
{    
    size_t key = 0;

    const int ITEM_COUNT_WIDTH = 3, NO_ITEMS = 4, ITEM_WORD_WIDTH = 14;

    // formatting for output, iterator moves through beginning of map1 to end of map 1
    // itr points to first and second to indicate print target
    for (map<string, int>::const_iterator itr = map1.begin(); itr != map1.end(); ++itr)
    {
        // formatting to left justify, and set width to ITEM_WORD_WIDTH, 
        // with itr pointing to first
        cout << std::left << std::setw(ITEM_WORD_WIDTH) << itr->first;
        // formatting to left justify, and set width to ITEM_COUNT_WIDTH, 
        // with itr pointing to second
        cout << ":" << std::left << std::setw(ITEM_COUNT_WIDTH) << itr->second;

        // every 4 words printed, print a newline
        if(((key + 1)) % NO_ITEMS == 0)
        {
            cout << "\n";
        }
        // increment key
        key++;
    }

    // output shown here
    cout << "\n" << "number of words in input stream   :" << track << "\n";

    cout << "number of words in output stream  :" << map1.size() << "\n";
};