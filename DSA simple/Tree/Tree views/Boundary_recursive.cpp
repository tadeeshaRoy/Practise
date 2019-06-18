//Boundary traversal without using extra data structures like queue: https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/

#include<iostream>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* node = new Node();
    node->val = data;
    node->left = node->right = NULL;
    return node;
}

void printLeftBoundary(Node* node)
{
    if(node)
    {
        if(node->left)
        {
            cout<<" "<<node->val;
            printLeftBoundary(node->left);
        }
        else if(node->right)
        {
            cout<<" "<<node->val;
            printLeftBoundary(node->right);
        }
    }
}

void printRightBoundary(Node* node)
{
    if(node)
    {
        if(node->right)
        {
            printRightBoundary(node->right);
            cout<<" "<<node->val;
        }
        else if(node->left)
        {
            printRightBoundary(node->left);
            cout<<" "<<node->val;
        }
    }
}

void printLeafNodes(Node* node)
{
    if(node)
    {
        printLeafNodes(node->left);

        if(!node->left && !node->right)
            cout<<" "<<node->val;

        printLeafNodes(node->right);
    }
}

void printBoundary(Node* root)
{
    if(root)
    {
        cout<<"Bounday view:\n"<<root->val;
        printLeftBoundary(root->left);
        printLeafNodes(root->left);
        printLeafNodes(root->right);
        printRightBoundary(root->right);
    }
}

int main()
{
    Node* root = newNode(20);
    root->left = newNode(8); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    root->right = newNode(22); 
    root->right->right = newNode(25); 

    printBoundary(root);
   
    return 0;
}
