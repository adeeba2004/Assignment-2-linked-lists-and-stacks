#include "Stack.h"

/*
 * Push an integer onto the stack.
 * Adds the value to the end of the vector.
 */
void Stack::push(int value) {
    data.push_back(value);
    cout << value << " pushed onto the stack." << endl;
}

/*
 * Pop an element from the top of the stack.
 * Removes the last element if stack is not empty.
 */
void Stack::pop() {
    if (!data.empty()) {
        cout << data.back() << " popped from the stack." << endl;
        data.pop_back();
    }
    else {
        cout << "Stack is empty. Cannot pop!" << endl;
    }
}

/*
 * Return the top element of the stack.
 * Shows error message if stack is empty.
 */
int Stack::top() const {
    if (!data.empty()) {
        return data.back();
    }
    else {
        cout << "Stack is empty. No top element!" << endl;
        return -1; // Sentinel value
    }
}

/*
 * Check whether the stack is empty.
 * Returns true if empty, false otherwise.
 */
bool Stack::empty() const {
    return data.empty();
}

/*
 * Calculate the average value of the elements in the stack.
 * Returns 0 if stack is empty.
 */
double Stack::average() const {
    if (data.empty()) return 0.0;

    int sum = 0;
    for (int val : data)
        sum += val;

    return static_cast<double>(sum) / data.size();
}

/*
 * Display all elements of the stack.
 * Prints from bottom to top.
 */
void Stack::display() const {
    cout << "Stack elements (bottom to top): ";
    for (int val : data) {
        cout << val << " ";
    }
    cout << endl;
}
