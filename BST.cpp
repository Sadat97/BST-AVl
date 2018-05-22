//
// Created by Sadat on 5/9/2018.
//


#include "BST.h"



BST::BST(){
    root = NULL;
}


void BST::makeEmpty(node * t ){
    if(t == NULL)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

BST::node * BST::insert(int data, node * t){

    if(t == NULL)
    {
        t = new node;
        t->data = data;
        t->height = 0;
        t->left = t->right = NULL;
    }

    else if(data < t->data)
    {
        t->left = insert(data, t->left);
        if(height(t->left) - height(t->right) == 2)
        {
            if(data < t->left->data)
                t = singleRightRotate(t);
            else
                t = doubleRightRotate(t);
        }
    }
    else if(data > t->data)
    {
        t->right = insert(data, t->right);
        if(height(t->right) - height(t->left) == 2)
        {
            if(data > t->right->data)
                t = singleLeftRotate(t);
            else
                t = doubleLeftRotate(t);
        }
    }

    t->height = max(height(t->left), height(t->right))+1;
    return t;
}

BST::node * BST::remove(int d, node *t) {
    node* temp;

    // Element not found
    if(t == NULL)
        return NULL;

        // Searching for element
    else if(d < t->data)
        t->left = remove(d, t->left);
    else if(d > t->data)
        t->right = remove(d, t->right);

        // Element found
        // With 2 children
    else if(t->left && t->right)
    {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    }
        // With one or zero child
    else
    {
        temp = t;
        if(t->left == NULL)
            t = t->right;
        else if(t->right == NULL)
            t = t->left;
        delete temp;
    }
    if(t == NULL)
        return t;

    t->height = max(height(t->left), height(t->right))+1;

    // If node is unbalanced
    // If left node is deleted, right case
    if(height(t->left) - height(t->right) == 2)
    {
        // right right case
        if(height(t->left->left) - height(t->left->right) == 1)
            return singleLeftRotate(t);
            // right left case
        else
            return doubleLeftRotate(t);
    }
        // If right node is deleted, left case
    else if(height(t->right) - height(t->left) == 2)
    {
            // left left case
        if(height(t->right->right) - height(t->right->left) == 1)
            return singleRightRotate(t);
            // left right case
        else
            return doubleRightRotate(t);
    }
    return t;
}


BST::node * BST::singleRightRotate(node *&t) {
    node* u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = max(height(t->left), height(t->right))+1;
    u->height = max(height(u->left), t->height)+1;
    return u;
}


BST::node * BST::singleLeftRotate(node *&t) {
    node* u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = max(height(t->left), height(t->right))+1;
    u->height = max(height(t->right), t->height)+1 ;
    return u;
}

BST::node * BST::doubleLeftRotate(node *&t) {
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}

BST::node * BST::doubleRightRotate(node *&t) {
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}


BST::node * BST::findMin(node *&t)  {
    if(t == NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

BST::node * BST::findMax(node *t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);

    }

int BST::height(node *t) {
    return (t == NULL ? -1 : t->height);
}

int BST::getBalance(node *t) {
    return (t == NULL ? 0 : (height(t->left) - height(t->right)) );
}

void BST::inorder(node *t) {

    if(t == NULL)
        return;
   // cout << "In the function " << t -> left -> data << endl;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}

void BST::preorder(node *t) {
    if (t == NULL)
        return;

    cout << t->data <<' ';
    preorder(t->left);
    preorder(t->right);
}

void BST::postorder(node *t){
    if (t == NULL)
        return;

    postorder(t->left);
    postorder(t->right);

    cout << t->data << " ";

}

void BST::insert(int data) {
    root = insert(data,root);
}

void BST::remove(int data) {
    root = remove(data,root);
}

void BST::display(int mode = 0) {

    if (mode == 0)
        inorder(root);
    else if (mode == 1)
       preorder(root);
    else
        postorder(root);

    cout << endl;

}

