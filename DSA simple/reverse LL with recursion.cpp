#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* addNewNode(Node* root, int data)
{
    Node* newNode = new Node();
    newNode->val = data;
    newNode->next = root;
    root = newNode;
    return root;
}

void reverse(Node** root, Node* temp)
{
    if(temp->next==NULL)
    {
        *root = temp;
        return;
    }
    reverse(root, temp->next);
    Node* q = temp->next;
    q->next = temp;
    temp->next = NULL;
}

void print(Node* root)
{
    while(root!=NULL)
    {
        cout<<root->val<<"->";
        root=root->next;
    }
    cout<<"NULL";
}

int main()
{
    Node* root = NULL;
    root = addNewNode(root, 10);
    root = addNewNode(root, 9);
    root = addNewNode(root, 7);
    root = addNewNode(root, 5);
    root = addNewNode(root, 4);
    print(root);
    cout<<endl;
    Node* temp = root;
    reverse(&root, temp);
    print(root);
    return 0;
}

//Reference: https://www.youtube.com/watch?v=KYH83T4q6Vs&t=414s
