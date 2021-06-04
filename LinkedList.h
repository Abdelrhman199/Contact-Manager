#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>

using namespace std;

template<typename T>
class LinkedList {
public:
    class MyNode {
    public:
        T value;
        MyNode* next;

        MyNode(T v)
        {
            value = v;

        };
    };

private:
    MyNode* head;

    void sortedInsert(MyNode** head_ref, MyNode* new_node);

    void insertionSort(struct MyNode** head_ref);

public:
    LinkedList();

    MyNode* addSorted(T value);

    MyNode* get(T value);

    MyNode* getHead(){
        return head;
    }

    ~LinkedList();

    template<typename U>
    friend ostream& operator<<(ostream& o, LinkedList<U>& c);
};

#endif
