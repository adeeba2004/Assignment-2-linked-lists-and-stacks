#include "Stack.h"

int main() {
    Stack s;

    cout << "Checking if stack is empty initially..." << endl;
    if (s.empty())
        cout << "✅ Stack is empty.\n";
    else
        cout << "❌ Stack is not empty.\n";

    // Push some integers
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.display();

    // Pop an element
    s.pop();

    // Show top element
    cout << "Top of stack: " << s.top() << endl;

    // Show average value
    cout << "Average value of stack elements: " << s.average() << endl;

    // Final state of stack
    s.display();

    return 0;
}
