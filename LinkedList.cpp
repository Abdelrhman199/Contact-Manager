#include <iostream>
#include "LinkedList.h"

using namespace std;

template<typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
}

template<typename T>
typename LinkedList<T>::MyNode* LinkedList<T>::addSorted(T value)
{
    MyNode* temp = new MyNode(value);
    temp->next = head;
    head = temp;
    insertionSort(&head);
    return head;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    //free(head);
}

template<typename T>
void LinkedList<T>::sortedInsert(LinkedList::MyNode** head_ref, LinkedList::MyNode* new_node)
{
    MyNode* current;

    if (*head_ref==NULL || (*head_ref)->value>=new_node->value) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        current = *head_ref;
        while (current->next!=NULL &&
                current->next->value<new_node->value) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

template<typename T>
void LinkedList<T>::insertionSort(LinkedList<T>::MyNode** head_ref)
{
    MyNode* sorted = NULL;
    MyNode* current = *head_ref;
    while (current!=NULL) {
        MyNode* next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}

template<typename T>
typename LinkedList<T>::MyNode* LinkedList<T>::get(T value)
{
    MyNode* temp = NULL;
    temp = head;
    while (temp!=NULL) {
        if (temp->value==value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

template<typename U>
ostream& operator<<(ostream& o, LinkedList<U>& c)
{
    typename LinkedList<U>::MyNode* temp;
    temp = c.head;
    while (temp!=NULL) {

        o << temp->value << endl;
        temp = temp->next;
    }
    return o;
}


