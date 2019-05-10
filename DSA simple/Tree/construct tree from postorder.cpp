/*
Reference: https://www.geeksforgeeks.org/construct-a-binary-search-tree-from-given-postorder/
*/

#include<iostream>
#include<climits>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(int data)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = data;
    temp->left = temp->right=NULL;
    return temp;
}

TreeNode* createTreeUntil(int post[], int* postIndex, int key, int min, int max);

TreeNode* buildTree(int post[], int size)
{
    int postIndex = size - 1;
    return createTreeUntil(post, &postIndex, post[postIndex], INT_MIN, INT_MAX);
}

TreeNode* createTreeUntil(int post[], int* postIndex, int key, int min, int max)
{
    if(*postIndex<0)
        return NULL;
    
    TreeNode* root = NULL;

    if(key>min && key<max)
    {
        root = newNode(key);
        (*postIndex)--;

        if(*postIndex>0)
        {
            root->right = createTreeUntil(post, postIndex, post[*postIndex], key, max);
            root->left = createTreeUntil(post, postIndex, post[*postIndex], min, key);
        }
    }
    return root;

}

void printInorder(TreeNode* root)
{
    if(root==NULL)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main()
{
    int post[] = {1, 7, 5, 50, 70, 10};
    int size = sizeof(post)/sizeof(post[0]);

    TreeNode* root = buildTree(post, size);

    printInorder(root);

    return 0;
}
