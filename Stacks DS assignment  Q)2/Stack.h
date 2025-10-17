#ifndef STACK_H
#define STACK_H

#include <vector>
#include <iostream>
using namespace std;

/*
 * Stack class that uses a vector to store integers.
 * Provides push, pop, top, empty, and average operations.
 */
class Stack {
private:
    vector<int> data;  // vector container to hold stack elements

public:
    // Push an element onto the stack
    void push(int value);

    // Pop an element from the stack
    void pop();

    // Return the top element of the stack
    int top() const;

    // Check if the stack is empty
    bool empty() const;

    // Find the average value of stack elements
    double average() const;

    // Display all stack elements (for testing/debugging)
    void display() const;
};

#endif
#pragma once
