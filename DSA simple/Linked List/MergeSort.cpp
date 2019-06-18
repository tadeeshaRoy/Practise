#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;

    slow = source;
    fast = source->next;

    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source; //single * to access the memory location in a function.
    *backRef = slow->next;
    slow->next = NULL;
}

Node* SortedMerge(Node* a, Node* b) //No change in values in the memory location so single pointer
{
    Node* result = NULL;

    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

    if(a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next,b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a,b->next);
    }
    return result;
}

void MergeSort(Node** root)
{
    Node* head = *root;
    if(head == NULL || head->next == NULL)
        return;

    Node* a; Node* b;

    FrontBackSplit(head, &a,&b); //here head won't change so head is not referenced as &head. Whenever we need to access a memory location we need to pass as &root and define as **root.

    MergeSort(&a); MergeSort(&b);

    *root = SortedMerge(a, b);
}

Node* insert(Node* head, int val)
{
    Node* node = new Node();
    node->data = val;
    node->next = head;
    head = node;
    return node;
}

void printNodes(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL ";
}

int main()
{

    Node* root = NULL;

    root = insert(root,20);
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,5);

    cout<<"before sorting: ";

    printNodes(root);

    cout<<"\n sorting: \n";

    MergeSort(&root);

    cout<<" after sorting: ";

    printNodes(root);

    return 0;
}

//Reference: https://www.geeksforgeeks.org/merge-sort-for-linked-list/
