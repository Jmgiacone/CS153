/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 5/12/14
 */

#ifndef BSTREE_H
#define BSTREE_H
#include "abstractbstree.h"
#include "BSTreeNode.h"

template <typename T>
class MyBSTree: public AbstractBSTree<T>
{
  private:
    BSTreeNode<T>* root;
    int size(BSTreeNode<T>* t) const;
    bool isEmpty(BSTreeNode<T>* t) const;
    int height(BSTreeNode<T>* t) const;
    const T& findMax(BSTreeNode<T>* t) const;
    const T& findMin(BSTreeNode<T>* t) const;
    int contains(BSTreeNode<T>* t, const T& x) const;
    void clear(BSTreeNode<T>* &t);
    void insert(BSTreeNode<T>* &t, const T& x);
    void remove(BSTreeNode<T>* &t, const T& x);
    void printPreOrder(BSTreeNode<T>* t) const;
    void printPostOrder(BSTreeNode<T>* t) const;
    void print(BSTreeNode<T>* t) const;
  public:
    MyBSTree();
    ~MyBSTree();
    MyBSTree(const BSTreeNode<T>* t) : root(t){}
    MyBSTree(const MyBSTree& rhs);
  /*** ---- Accessor Operations ---- */

 // Purpose: Accessor function for the number of elements in the tree
 // Returns: number of elements in the tree
   virtual int size() const;


 // Purpose: Checks if a tree is empty
 // Returns: 'true' if the tree is empty
 //     'false' otherwise
   virtual bool isEmpty() const;


 // Purpose: Returns the height of the tree
 // Returns: height the tree
   virtual int height() const;


 // Purpose: finds the maximum element in the Tree
 // Returns: a const reference to the maximum element
   virtual const T& findMax() const;


 // Purpose: finds the minimum element in the Tree
 // Returns: a const reference to the minimum element
   virtual const T& findMin() const;


 // Purpose: finds an element in the Tree
 // Parameters: x is value to be found
 // Returns:
 //     If The tree contains x then
 //         return N, the level of the node containing x
 //         (the root is considered level 0)
 //     If The tree does not contains x then
 //         return -N, where N is the level of the tree
 //         reached in the search + 1
   virtual int contains(const T& x) const;



   /*** ---- Mutator Operations ---- */


 // Purpose: Clears the Tree
 // Postconditions: an empty Tree
   virtual void clear();


 // Purpose: Inserts an element into a tree
 // Parameters: x is value to be added to the tree
 // Postconditions: The tree now contains x
 //     if the tree already contains x, ignore insertion
   virtual void insert(const T& x);


 // Purpose: Removes an element from the tree
 // Parameters: x, the element to remove
 // Postconditions: the tree does not contains x
   virtual void remove(const T& x);


   /*** ---- Output Operations ---- */

 // Purpose: Prints the Tree in Pre-Order
   virtual void printPreOrder() const;


 // Purpose: Prints the Tree in Pre-Order
   virtual void printPostOrder() const;


 // Purpose: Prints the Tree In-Order with formatting
 //     each level indented 4 spaces, one element per line
   virtual void print() const;

   MyBSTree& operator = (const MyBSTree& rhs);

};
#include "MyBSTree.hpp"
#endif // BSTREE_H
