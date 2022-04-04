/*	
 *  Michael Marchetti
 *	z1860574
 *	CSCI 340 Data Struct Algorithm Analysis
 *	Class # 1737-Section 0002-Component LEC
 *
 *	I certify that this is my own work and where appropriate an extension
 *	of the starter code provided for the assignment.
 *
 *  Assignment 4
 */

#ifndef STACK_H
#define STACK_H
#include <queue>

template<typename T>
class Stack
{
private:
    std::queue<T> q1;	// These queues are where the stack's elements 
    std::queue<T> q2;	// are to be saved.

public:
    bool empty() const;
    int size() const;
    const T& top();
    void push(const T &val);
    void pop();

};


// Note that the members of a template go into a .h file since 
// they are not compiled directly into a .o file like the members 
// of regular/non-template classes.


// Place your Stack class member implementations here.

/**
 * @brief empty method checks if the queue is empty by calling 
 * the stl empty and returns true if the queue "q1"is empty, false
 * if the opposite is the case
 * 
 * @return true 
 * @return false 
 */
template <typename T>
bool Stack<T>::empty() const
{
    if(q1.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief checks the size of the queue by calling the empty stl
 * method. 
 * 
 * @return T template type 
 */
template <typename T>
int Stack<T>::size() const
{
    return q1.size();
}

/**
 * @brief top function returns the value of the first value in
 * the queue by calling the front stl function for q1
 * 
 * @return const T& 
 */
template <typename T>
const T& Stack<T>::top()
{
    return q1.front();
}

/**
 * @brief push function adds an element to the top of the queue
 * code heavily borrowed with edits to overall execution
 * https://www.geeksforgeeks.org/implement-stack-using-queue/
 * 
 * @param val 
 */
template <typename T>
void Stack<T>::push(const T& val)
{
    // Push val first in empty q2
    q2.push(val);

    // Push all the remaining
    // elements in q1 to q2.
    while (!q1.empty()) 
    {
        q2.push(q1.front());
        q1.pop();
    }

    // swap the names of two queues
    std::queue<T> q = q1;
    q1 = q2;
    q2 = q;

}

/**
 * @brief pop function removes the front or newest element
 * from the queue
 * 
 */
template <typename T>
void Stack<T>::pop()
{
    // if no elements are there in q1
    if (q1.empty())
        return;
    q1.pop();
}

#endif // STACK_H
