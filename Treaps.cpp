#include <iostream>
#include <string.h>
#include "Treaps.h"

using namespace std;

template<typename T, typename V>
Treaps<T, V>::Treaps()
{

}

template<typename T, typename V>
typename Treaps<T, V>::Node* Treaps<T, V>::rotateRight(Treaps::Node* Q)
{
    typename Treaps<T, V>::Node* x = Q->left;
    if (x==nullptr) {
        return Q;
    }
    typename Treaps<T, V>::Node* rightOfX = x->right;
    x->right = Q;
    Q->left = rightOfX;
    Q->h = max(height(Q->left), height(Q->right))+1;
    x->h = max(height(x->left), height(x->right))+1;
    return x;

}

template<typename T, typename V>
typename Treaps<T, V>::Node* Treaps<T, V>::rotateLeft(Treaps::Node* P)
{
    typename Treaps<T, V>::Node* x = P->right;
    if (x==nullptr) {
        return P;
    }
    typename Treaps<T, V>::Node* leftOfX = x->left;
    x->left = P;
    P->right = leftOfX;
    P->h = max(height(P->left), height(P->right))+1;
    x->h = max(height(x->left), height(x->right))+1;
    return x;

}

template<typename T, typename V>
typename Treaps<T, V>::Node* Treaps<T, V>::insert(Treaps<T, V>::Node* tempRoot, T k, V v)
{

    if (tempRoot==nullptr) {
        return new Treaps<T, V>::Node(k, v);
    }
    if (k<tempRoot->key) {
        tempRoot->left = insert(tempRoot->left, k, v);
        if (tempRoot->left->priority<tempRoot->priority) {
            tempRoot = rotateRight(tempRoot);
        }
    }
    else if (k>tempRoot->key) {
        tempRoot->right = insert(tempRoot->right, k, v);
        if (tempRoot->right->priority<tempRoot->priority) {
            tempRoot = rotateLeft(tempRoot);
        }
    }
    else {
        return tempRoot;
    }
    tempRoot->h = max(height(tempRoot->left),height(tempRoot->right))+1;
    int balance2 = balance(tempRoot);
    if (balance2>1 && k<tempRoot->left->key) { return rotateRight(tempRoot); }
    if (balance2<-1 && k>tempRoot->right->key) { return rotateLeft(tempRoot); }
    if (balance2>1 && k>tempRoot->left->key) {
        tempRoot->left = rotateLeft(tempRoot->left);
        return rotateRight(tempRoot);
    }
    if (balance2<-1 && k<tempRoot->right->key) {
        tempRoot->right = rotateRight(tempRoot->right);
        return rotateLeft(tempRoot);
    }
    return tempRoot;
}

template<typename T, typename V>
V Treaps<T, V>::findNode(Treaps::Node* roote, T k)
{
    if (roote==nullptr || roote->key==k) {
        if (roote==nullptr) {
            return 0;
        }
        return (roote->value);
    }
    if (roote->key<k) {

        return findNode(roote->right, k);
    }
    return findNode(roote->left, k);
}

template<typename T, typename V>
void Treaps<T, V>::insert(T k, V v)
{
    root = insert(root, k, v);
}

template<typename T, typename V>
V Treaps<T, V>::find(T k)
{
    return findNode(root, k);
}

template<typename X, typename Y>
ostream& operator<<(ostream& o, Treaps<X, Y> tree)
{
    o << tree.root << endl;
    return o;
}

template<typename T, typename V>
int Treaps<T, V>::height(Treaps::Node* n)
{

    if (n==nullptr) {
        return -1;
    }
    return n->h;

}

template<typename T, typename V>
int Treaps<T, V>::balance(Treaps::Node* n)
{
    if (n==nullptr) {
        return 0;
    }
    return height(n->left)-height(n->right);
}