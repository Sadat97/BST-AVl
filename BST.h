//
// Created by Sadat on 5/9/2018.
//

#include <iostream>


#ifndef FILESA3P1_BST_H
#define FILESA3P1_BST_H


using namespace std;

class BST {
private:



    struct node {
        int data;
        node * left;
        node * right;
        int height;
    };

    node * root ;

    void makeEmpty(node* t) ;

    node * insert(int d, node * t);
    node * remove(int d, node * t);

    node* singleRightRotate(node* &t);
    node* singleLeftRotate(node* &t);

    node* doubleLeftRotate(node* &t);
    node* doubleRightRotate(node* &t);

    node* findMin(node * &t);
    node* findMax(node* t);

    int height(node * t);
    int getBalance(node * t);

    void inorder(node* t);
    void preorder(node *t);
    void postorder(node *t);


public:
    BST();
    void insert (int data);
    void remove (int data);
    void display (int);


};


#endif //FILESA3P1_BST_H
