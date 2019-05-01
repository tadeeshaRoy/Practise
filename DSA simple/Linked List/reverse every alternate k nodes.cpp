#include<iostream>
/*Reverse alternate k elements with 2 methods
1. Recursion operates on 2k elements at a time. 
2. Recursion operates on k elements at a time.
Reference: https://www.geeksforgeeks.org/reverse-alternate-k-nodes-in-a-singly-linked-list/
*/
struct Node
{
    int val;
    Node* next;
};

Node* addNode(Node* head, int data)
{
    Node* newNode = new Node();
    newNode->val = data;
    newNode->next=head;
    head = newNode;
    return head;
}

void printNode(Node* head)
{
    while(head!=NULL)
    {
        std::cout<<head->val<<"->";
        head=head->next;
    }
    std::cout<<"NULL";
}

Node* reverse(Node* head, int k)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    int count = 0;

    while(curr!=NULL && count<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(head!=NULL)
        head->next = curr;

    count = 0;

    while(curr!=NULL && count<k-1)
    {    
        curr = curr->next;
        count++;
    }
    
    if(curr!=NULL)
        curr->next = reverse(curr->next, k);

    return prev;
}

Node* _reverse(Node* head, int k, bool b)
{
    if(head == NULL)
        return NULL;
    
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    int count = 1;

    while(curr!=NULL && count<=k)
    {
        next = curr->next;
        if(b==true)
            curr->next=prev;

        prev = curr;
        curr = next;
        count++;
    }

    if(b==true)
    {    
        head->next = _reverse(curr, k, !b);
        return prev;
    }

    else
    {
        prev->next= _reverse(curr,k,!b);
        return head;
    }

}

int main()
{
    Node* head = NULL;
    for(int i=10;i>0;i--)
        head=addNode(head,i);
    std::cout<<"Original list: ";
    printNode(head);
    //head = reverse(head,3);
    //std::cout<<"\nlist after 1st type of reverse: ";
    //printNode(head);
    std::cout<<"\nlist after 2nd type of reverse: ";
    head = _reverse(head, 3, true);
    printNode(head);
    return 0;
}
