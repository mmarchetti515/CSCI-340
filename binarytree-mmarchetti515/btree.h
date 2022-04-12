/*	Michael Marchetti
 *	z1860574
 *	CSCI 340 Data Struct Algorithm Analysis
 *	Class # 1737-Section 0002-Component LEC
 *
 *	I certify that this is my own work and where appropriate an extension
 *	of the starter code provided for the assignment.
 *
 *  Assignment 8
 */

#ifndef H_BTREE
#define H_BTREE

#include "node.h"
#include <cstdlib>

template <typename T> class BinaryTree{

public:
    BinaryTree() {root = NULL;};                       // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};

typedef enum {left_side, right_side } SIDE;
// will be used to decide where nodes are randomly placed
// where if return value is even, place on the right side
// else, place on the left side
SIDE rnd(){ 
    return rand()%2 ? right_side : left_side;
}// End of rnd()

/**
 * @brief returns the private getSize function
 * 
 * @tparam T 
 * @return unsigned 
 */
template <typename T>
unsigned BinaryTree<T>::getSize() const
{
    return _getSize(root);
}

/**
 * @brief returns the getHeight private function
 * 
 * @tparam T 
 * @return unsigned 
 */
template <typename T>
unsigned BinaryTree<T>::getHeight() const
{
    return _getHeight(root);
}

/**
 * @brief returns the private Insert function
 * 
 * @tparam T 
 * @param copy 
 */
template <typename T>
void BinaryTree<T>::Insert(const T& copy)
{
    return _Insert(root, copy);
}

/**
 * @brief returns the private Inorder function
 * 
 * @tparam T 
 * @param print 
 */
template <typename T>
void BinaryTree<T>::Inorder(void (*print)(const T&))
{
    return _Inorder(root, print);
}


/**
 * @brief function used to determine the size of the 
 *      binary tree by validating the number of nodes
 *      present in the tree.
 * 
 * @tparam T 
 * @return unsigned 
 */
template <typename T>
unsigned BinaryTree<T>::_getSize(Node<T> *newNode) const
{
    // case if no newNodes are found
    if(!newNode)
    {
        return 0; // size of tree is 0, no nodes present
    }
    else
    {
        // size of tree is the num of nodes present as left child and
        // right child of the root node + 1 since the root node is
        // not initially counted. Traverses through left and right
        // by having newNode point to the left and right vars 
        // declared in the Node template
        return (1 + _getSize(newNode->left) + _getSize(newNode->right));
    }
}

/**
 * @brief function used to determine the height of the 
 *      binary tree by traversing the deepest branch 
 *      of both the left and right children of the root.
 *      then uses max stl keyword to compare those vals.
 *      returns the return value of max + 1 since root
 *      height is not included.
 *      * note * height of the root is assumed to be 1
 * 
 * @tparam T 
 * @return unsigned 
 */
template <typename T>
unsigned BinaryTree<T>::_getHeight(Node<T> *newNode) const
{
    // case if no newNodes are found
    if(!newNode)
    {  
        return 0;
    }
    // if newNodes are present in tree
    else
    {
        // traverse tree through pointing to left and right sides
        return 1 + max(_getHeight(newNode->left), _getHeight(newNode->right));
    }
}

/**
 * @brief function used to insert newNode and the key elements of
 *      it's template to the binary tree.
 * 
 * 
 * @tparam T 
 */
template <typename T>
void BinaryTree<T>::_Insert(Node<T> *&newNode, const T& value)
{
    // case if there is no root present
    if(newNode == NULL)
    {
        // creates a newNode based of the Node template
        newNode = new Node<T>();
        // define the right, left, and data vars, declared in the 
        // template by pointing to them using the newNode var
        newNode->right = NULL;
        newNode->left = NULL;
        newNode->data = value;
    }
    // if nodes are present, and the rnd() function returns
    // right_side, insert randomly generated value from SEED
    // into a newly generated node
    else if(rnd() == right_side)
    {
        _Insert(newNode->right, value);
    }
    // if nodes are present, and the rnd() function returns
    // left_side, insert randomly generated value from SEED
    // into a newly generated node
    else
    {
        _Insert(newNode->left, value);
    }
}

/**
 * @brief inorder traversal function
 * 
 * @tparam T 
 */
template <typename T>
void BinaryTree<T>::_Inorder(Node<T> *newNode, void (*visit)(const T&))
{
    // as long as nodes are present
    if(newNode != NULL)
    {
        // recursively call inorder traversal by pointing to the left
        // child, and calling the visit function
        _Inorder(newNode->left, visit);
        // visit function has newNode point to data, to allow 
        // definition
        visit(newNode->data);
        // recursively call inorder traversal by pointing to the right
        // child, and calling the visit function
        _Inorder(newNode->right, visit);
    }
}


#endif // End of H_B