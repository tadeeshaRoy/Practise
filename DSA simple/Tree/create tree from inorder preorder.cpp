/*
Program to create a tree from given inorder and preorder traversals

Reference: https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
*/

#include<iostream>

struct Node
{
    char val;
    Node* left;
    Node* right;
};

Node* getNewNode(char data)
{
    Node* newNode = new Node();
    newNode->val = data;
    newNode->left = newNode->right=NULL;
    return newNode;
}

int searchIndex(char in[], int start, int end, char value)
{
    int i;
    for(i=start;i<=end;i++)
    {
        if(in[i]==value)
            return i;
    }
}

Node* buildTree(char in[],char pre[], int inStart, int inEnd)
{
    static int preIndex = 0;

    if(inStart > inEnd)
        return NULL;    //mistake: don't return tNode after checking start==end -> goes in segmentation fault since even number of elements are not handled where start won't be equal to end and in one loop will be greater than end;

    Node* tNode = getNewNode(pre[preIndex++]);

    int inIndex = searchIndex(in,inStart,inEnd,tNode->val);

    tNode->left = buildTree(in, pre, inStart, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

void printInorder(Node* head)
{
    if(head == NULL)
        return;

    printInorder(head->left);
    std::cout<<head->val<<"->";
    printInorder(head->right);
}

int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };  
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 

    int len = sizeof(in)/sizeof(in[0]);

    Node* root = buildTree(in,pre,0,len-1);

    printInorder(root);
    std::cout<<"NULL";
    return 0;
}
