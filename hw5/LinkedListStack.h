/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS153, Section C
 * Date: 4-17-14
 */

#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include "abstractstack.h"
#include "LinkedList.h"

template <typename T>
class LinkedListStack : public AbstractStack<T>
{
public:
    LinkedList<T>* next;
    int size;
    LinkedListStack() : next(NULL), size(0) {}
    ~LinkedListStack();
    // Purpose: clears the stack
    // Postconditions: the stack is now empty
    void clear();

    // Purpose: push an element into the stack
    // Parameters: x is the value to push into the stack
    // Postconditions: x is now the element at the top of the stack,
    void push(const T& x);

    // Purpose: pop the stack
    // Postconditions: the element formerly at the top of the stack has
    // been removed
    // Note: Poping an empty stack results in an empty stack.
    void pop();


    // Purpose: looks at the top of the stack
    // Returns: a const reference to the element currently on top of the stack
    // Exception: if the stack is empty, THROW a 'Oops' object with an error message!!!
    const T& top() const throw ( Oops );

    // Purpose: Checks if a stack is empty
    // Returns: 'true' if the stack is empty
    //     'false' otherwise
    bool isEmpty() const;
};
#include "LinkedListStack.hpp"
#endif // LINKEDLISTSTACK_H
