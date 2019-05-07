/*
Check whether a tree A is a subtree of tree B
*/

#include<iostream>

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
    std::cout<<root->val;
    printInorder(root->right);
}

bool check(TreeNode* M, TreeNode* sub)
{
    if(M==NULL && sub==NULL)
        return true;
    else if(M==NULL)
        return false;
    else if(M->val == sub->val && check(M->left,sub->left) && check(M->right,sub->right))
        return true;
    else return (check(M->left,sub)||check(M->right,sub));
}

int main()
{
    TreeNode* head1 = NULL;
    head1 = insert(head1, 10);
    head1 = insert(head1, 2);
    head1 = insert(head1, 1);
    head1 = insert(head1, 14);
    head1 = insert(head1, 13);
    head1 = insert(head1, 12);
    head1 = insert(head1, 15);
    head1 = insert(head1, 16);

    TreeNode* head2 = NULL;
    head2 = insert(head2, 14);
    head2 = insert(head2, 13);
    head2 = insert(head2, 12);
    head2 = insert(head2, 15);
    head2 = insert(head2, 17);

    bool isSubTree = check(head1,head2);

    if(isSubTree)
        std::cout<<"Yes it is a subtree";
    else std::cout<<"Nope!";
}
