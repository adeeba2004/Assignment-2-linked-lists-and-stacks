#include "Single_Linked_List.h"

/*
 * Constructor: Single_Linked_List
 * -------------------------------
 * Initializes an empty list with head and tail set to nullptr.
 */
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() {
    head = nullptr;
    tail = nullptr;
    num_items = 0;
}

/*
 * Destructor: ~Single_Linked_List
 * -------------------------------
 * Deletes all nodes to free up allocated memory.
 */
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front(); // repeatedly remove the front element
    }
}

/*
 * Function: push_front
 * --------------------
 * Inserts a new element at the beginning of the list.
 * If the list was empty, both head and tail point to the new node.
 */
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item, head);
    head = new_node;
    if (num_items == 0)
        tail = head; // when list was empty
    num_items++;
}

/*
 * Function: push_back
 * -------------------
 * Inserts a new element at the end of the list.
 * If the list is empty, the new node becomes both head and tail.
 */
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item);
    if (empty()) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

/*
 * Function: pop_front
 * -------------------
 * Removes the first element from the list.
 * If the list becomes empty, tail is also set to nullptr.
 */
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) return;

    Node<Item_Type>* temp = head;
    head = head->next;
    delete temp;
    num_items--;

    if (num_items == 0)
        tail = nullptr;
}

/*
 * Function: pop_back
 * ------------------
 * Removes the last element of the list.
 * If there’s only one element, both head and tail become nullptr.
 */
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        // Find the node before the last node
        Node<Item_Type>* current = head;
        while (current->next != tail)
            current = current->next;

        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
}

/*
 * Function: front
 * ---------------
 * Returns the data stored in the first node.
 * Throws an exception if the list is empty.
 */
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (empty()) throw out_of_range("List is empty");
    return head->data;
}

/*
 * Function: back
 * --------------
 * Returns the data stored in the last node.
 * Throws an exception if the list is empty.
 */
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (empty()) throw out_of_range("List is empty");
    return tail->data;
}

/*
 * Function: empty
 * ---------------
 * Returns true if there are no elements in the list.
 */
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

/*
 * Function: insert
 * ----------------
 * Inserts an item at a specific index (0-based).
 * If index = 0 → insert at the front.
 * If index >= num_items → insert at the end.
 */
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index == 0) {
        push_front(item);
        return;
    }

    if (index >= num_items) {
        push_back(item);
        return;
    }

    Node<Item_Type>* prev = head;
    for (size_t i = 0; i < index - 1; ++i)
        prev = prev->next;

    Node<Item_Type>* new_node = new Node<Item_Type>(item, prev->next);
    prev->next = new_node;
    num_items++;
}

/*
 * Function: remove
 * ----------------
 * Removes the element at the given index.
 * Returns true if removal was successful, false if index is out of range.
 */
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items)
        return false;

    if (index == 0) {
        pop_front();
        return true;
    }

    Node<Item_Type>* prev = head;
    for (size_t i = 0; i < index - 1; ++i)
        prev = prev->next;

    Node<Item_Type>* to_delete = prev->next;
    prev->next = to_delete->next;

    if (to_delete == tail)
        tail = prev;

    delete to_delete;
    num_items--;
    return true;
}

/*
 * Function: find
 * --------------
 * Searches the list for the first occurrence of a given item.
 * Returns its index if found, or the size of the list if not found.
 */
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node<Item_Type>* current = head;
    size_t index = 0;

    while (current) {
        if (current->data == item)
            return index;
        current = current->next;
        index++;
    }

    return num_items; // not found
}

/*
 * Function: print_list
 * --------------------
 * Displays all elements in the list (for testing/debugging).
 */
template <typename Item_Type>
void Single_Linked_List<Item_Type>::print_list() const {
    Node<Item_Type>* current = head;
    cout << "[ ";
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "]" << endl;
}

/*
 * Explicit template instantiations
 * --------------------------------
 * These ensure that the compiler generates code for common data types.
 */
template class Single_Linked_List<int>;
template class Single_Linked_List<string>;
