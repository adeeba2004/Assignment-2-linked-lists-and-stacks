#include "Single_Linked_List.h"
#include <iostream>
using namespace std;

int main() {
    Single_Linked_List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.print_list();

    list.insert(2, 15);
    list.print_list();

    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;

    cout << "Find(15): " << list.find(15) << endl;
    list.remove(1);
    list.print_list();

    list.pop_back();
    list.pop_front();
    list.print_list();

    cout << "Empty? " << (list.empty() ? "Yes" : "No") << endl;

    return 0;
}
