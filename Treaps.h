#ifndef TREAP_H_
#define TREAP_H_

#include <iostream>
#include <stdlib.h>

using namespace std;

template<typename T, typename V>
class Treaps {
public:
    class Node {
    public:
        Node* left, * right;
        T key;
        V value;
        int h;
        int priority;

        Node(T k, V v)
        {
            key = k;
            value = v;
            h = 0;
            priority = rand();
            left = nullptr;
            right = nullptr;
        }

        friend ostream& operator<<(ostream& o, Treaps<T, V>::Node* tempRoot)
        {
            tempRoot->printAll(tempRoot);
            return o;
        }

    private:
        void printAll(Treaps<T, V>::Node* tempRoot)
        {
            if (tempRoot==nullptr) {
                return;
            }
            printAll(tempRoot->left);
            cout << *(tempRoot->value) << endl;
            printAll(tempRoot->right);
        }
    };

private:
    Node* root = nullptr;

    Node* rotateRight(Node* Q);

    Node* rotateLeft(Node* P);

    int height(Node* n);

    int balance(Node* n);

    Node* insert(Node* tempRoot, T k, V v);

    V findNode(Node* roote, T k);

public:
    Treaps();

    void insert(T k, V v);

    V find(T k);

    template<typename X, typename Y>
    friend ostream& operator<<(ostream& o, Treaps<X, Y> tree);
};

#endif /* TREAP_H_ */
