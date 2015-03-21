/* @file: abstractbstree.h
 * Definition of templated class abstractbstree
 * Implementation of Binary Search Tree A.D.T.
 * @C - Galaxy Express Software
 *
 * Version 14.1.0
 */
/*  _____________________________
 * /                             \
 * | Abstract Binary Search Tree |
 * \_____________________________/
 *
 * Purpose: A template abstract class that defines a Binary Search Tree
 *
 * Preconditions: typename T MUST support the '<' operator
 *
 */

#ifndef ABSTRACTBSTREE_H
#define ABSTRACTBSTREE_H

#include <iostream>
#include <string>

template < typename T >
class AbstractBSTree
{

public:

   /*** ---- Accessor Operations ---- */

// Purpose: Accessor function for the number of elements in the tree
// Returns: number of elements in the tree
  virtual int size() const = 0;


// Purpose: Checks if a tree is empty
// Returns: 'true' if the tree is empty
//     'false' otherwise
  virtual bool isEmpty() const = 0;


// Purpose: Returns the height of the tree
// Returns: height the tree
  virtual int height() const = 0;


// Purpose: finds the maximum element in the Tree
// Returns: a const reference to the maximum element
  virtual const T& findMax() const = 0;


// Purpose: finds the minimum element in the Tree
// Returns: a const reference to the minimum element
  virtual const T& findMin() const = 0;


// Purpose: finds an element in the Tree
// Parameters: x is value to be found
// Returns:
//     If The tree contains x then
//         return N, the level of the node containing x
//         (the root is considered level 0)
//     If The tree does not contains x then
//         return -N, where N is the level of the tree
//         reached in the search + 1
  virtual int contains(const T& x) const = 0;



  /*** ---- Mutator Operations ---- */


// Purpose: Clears the Tree
// Postconditions: an empty Tree
  virtual void clear() = 0;


// Purpose: Inserts an element into a tree
// Parameters: x is value to be added to the tree
// Postconditions: The tree now contains x
//     if the tree already contains x, ignore insertion
  virtual void insert(const T& x) = 0;


// Purpose: Removes an element from the tree
// Parameters: x, the element to remove
// Postconditions: the tree does not contains x
  virtual void remove(const T& x) = 0;


  /*** ---- Output Operations ---- */

// Purpose: Prints the Tree in Pre-Order
  virtual void printPreOrder() const = 0;


// Purpose: Prints the Tree in Pre-Order
  virtual void printPostOrder() const = 0;


// Purpose: Prints the Tree In-Order with formatting
//     each level indented 4 spaces, one element per line
  virtual void print() const = 0;

};


#endif
