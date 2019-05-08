/*
Reference: https://www.geeksforgeeks.org/print-path-root-given-node-binary-tree/
*/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* getNewNode(int data)
{
    TreeNode* newNode = new TreeNode();
    newNode->val = data;
    newNode->left=newNode->right= NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int data)
{
    TreeNode* temp = getNewNode(data);
    if(root==NULL)
        return temp;
    else if(root->val > data)
        return insert(root->left, data);
    else return insert(root->right, data);
}

void printInorder(TreeNode* root)
{
    if(root == NULL)
        return;
    printInorder(root->left);
    cout<<root->val;
    printInorder(root->right);
}

bool hasPath(TreeNode* root, vector<int>& arr, int n)
{
    if(root==NULL)
        return false;
    
    arr.push_back(root->val);

    if(root->val == n)
        return true;

    if(hasPath(root->left,arr,n) || hasPath(root->right,arr,n))
        return true;

    arr.pop_back();
    return false;
}

void printpath(TreeNode* root, int x)
{
    vector<int> arr;

    if(hasPath(root,arr,x))
    {
        cout<<"\nThe path found: ";
        for(int i=0;i<arr.size()-1;i++)
            cout<<arr[i]<<"->";
        cout<<arr[arr.size()-1];
    }
    else cout<<"\nNo path found";
}

int main()
{
    struct TreeNode *root = getNewNode(1); 
    root->left = getNewNode(2); 
    root->right = getNewNode(3); 
    root->left->left = getNewNode(4); 
    root->left->right = getNewNode(5); 
    root->right->left = getNewNode(6); 
    root->right->right = getNewNode(7);
    printInorder(root);
    printpath(root, 7);
}
