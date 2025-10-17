#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cstddef>  // for size_t
#include <iostream>
using namespace std;

/*
 * Node structure for a singly linked list
 * Each node contains:
 *   - data: the value stored in this node
 *   - next: pointer to the next node in the list
 */
template <typename Item_Type>
struct Node {
    Item_Type data;
    Node* next;

    Node(const Item_Type& item, Node* next_ptr = nullptr)
        : data(item), next(next_ptr) {
    }
};

/*
 * Class: Single_Linked_List
 * --------------------------
 * A basic implementation of a singly linked list.
 * This list supports common operations similar to std::list:
 * push_front, push_back, pop_front, pop_back, insert, remove, etc.
 */
template <typename Item_Type>
class Single_Linked_List {
private:
    Node<Item_Type>* head;     // Pointer to the first node
    Node<Item_Type>* tail;     // Pointer to the last node
    size_t num_items;          // Number of elements currently in the list

public:
    // --- Constructor and Destructor ---
    Single_Linked_List();      // Initializes an empty list
    ~Single_Linked_List();     // Frees all dynamically allocated memory

    // --- Basic list operations ---
    void push_front(const Item_Type& item);  // Insert at the beginning
    void push_back(const Item_Type& item);   // Insert at the end
    void pop_front();                        // Remove from the beginning
    void pop_back();                         // Remove from the end
    Item_Type front() const;                 // Access first element
    Item_Type back() const;                  // Access last element
    bool empty() const;                      // Check if list is empty

    // --- Extended list operations ---
    void insert(size_t index, const Item_Type& item); // Insert at index
    bool remove(size_t index);                        // Remove by index
    size_t find(const Item_Type& item) const;         // Find position of an item

    // --- Utility function ---
    void print_list() const;                // Print list contents (for testing)
};

#endif
