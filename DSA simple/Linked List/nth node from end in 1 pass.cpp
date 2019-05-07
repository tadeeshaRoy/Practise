/*
Program to extract n element from end of list in one pass
*/

#include<iostream>

struct Node
{
    int val;
    Node* next;
};

Node* insert(Node* head, int data)
{
    Node* newNode = new Node();
    newNode->val = data;
    newNode->next = head;
    head = newNode;
    return newNode;
}

void print(Node* root)
{
    while(root!=NULL)
    {
        std::cout<<root->val<<"->";
        root=root->next;
    }
    std::cout<<"NULL";
}

Node* findNthNode(Node* head, int k)
{
    Node *slow, *fast;

    slow=fast=head;

    while(k--)
    {
        if(fast==NULL)
        {
            std::cout<<"\ninsufficient elements!";
            return NULL;
        }
        else 
            fast=fast->next;
    }

    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

int main()
{
    Node* root=NULL;
    root = insert(root,20);
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,5);
    std::cout<<"List: ";
    print(root);
    int k = 2;
    Node* res = findNthNode(root, k);
    if(res!=NULL)
        std::cout<<"\nNth Node from the end: "<<res->val;
    return 0;
}
