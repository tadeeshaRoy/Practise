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

bool isLeaf(Node* node)
{
    if(node == 0)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}

int isSumTree(Node* node)
{
    if(node == NULL || isLeaf(node))
        return 1;
    
    int ls,rs;

    if(isSumTree(node->left)&& isSumTree(node->right))
    {
        if(node->left == NULL)
            ls = 0;
        else if(isLeaf(node->left))
            ls = node->left->val;
        else ls = 2*(node->left->val);

        if(node->right == NULL)
            rs = 0;
        else if(isLeaf(node->right))
            rs = node->right->val;
        else rs = 2*(node->right->val);
        
        if(node->val == ls + rs)
            return 1;
    }
    return 0;
}

int main()
{
    Node* root = newNode(26);
    root->left = newNode(10);
    root->left->left = newNode(6);
    root->left->right = newNode(4);
    root->right = newNode(3);
    root->right->right = newNode(4);
    if(isSumTree(root))
        cout<<"Tree is a SumTree";
    else cout<<"Not a Sum Tree";
    return 0;
}

//Reference: https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/
