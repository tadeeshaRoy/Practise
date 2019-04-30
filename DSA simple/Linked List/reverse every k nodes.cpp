//reverse linked list in groups of given size: https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

#include<iostream>

struct Node
{
   int data;
   Node* next; 
};

Node* addNode(Node* head,int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next=head;
    head = newNode;
    return head;
}

void printList(Node* head)
{
    while(head!=NULL)
    {
        std::cout<<head->data<<"->";
        head=head->next;
    }
    std::cout<<"NULL";
}

Node* reverse(Node* head, int k)
{
    Node* current = head;
    Node* prev=NULL, *next=NULL;

    int count=0;

    while(current!=NULL && count<k)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }

    if(next!=NULL)
        head->next = reverse(next,k); //it is head->next because it needs to link the list to the next recursion

    return prev;
}

int main()
{
    Node* head = NULL;
    head = addNode(head, 9);
    head = addNode(head, 8);
    head = addNode(head, 7);
    head = addNode(head, 6);
    head = addNode(head, 5);
    head = addNode(head, 4);
    head = addNode(head, 3);
    head = addNode(head, 2);
    head = addNode(head, 1);
    std::cout<<"Original list: ";
    printList(head);
    head = reverse(head,5);
    std::cout<<"\nReversed list: ";
    printList(head);
    return 0;
}

/*

Output:
=======

[Running] cd "/Users/tadeeroy/Downloads/TreeCodes/practise/" && g++ reverse.cpp -o reverse && "/Users/tadeeroy/Downloads/TreeCodes/practise/"reverse
Original list: 1->2->3->4->5->6->7->8->9->NULL
Reversed list: 3->2->1->6->5->4->9->8->7->NULL
[Done] exited with code=0 in 0.591 seconds

[Running] cd "/Users/tadeeroy/Downloads/TreeCodes/practise/" && g++ reverse.cpp -o reverse && "/Users/tadeeroy/Downloads/TreeCodes/practise/"reverse
Original list: 1->2->3->4->5->6->7->8->9->NULL
Reversed list: 2->1->4->3->6->5->8->7->9->NULL
[Done] exited with code=0 in 0.365 seconds

[Running] cd "/Users/tadeeroy/Downloads/TreeCodes/practise/" && g++ reverse.cpp -o reverse && "/Users/tadeeroy/Downloads/TreeCodes/practise/"reverse
Original list: 1->2->3->4->5->6->7->8->9->NULL
Reversed list: 5->4->3->2->1->9->8->7->6->NULL
[Done] exited with code=0 in 0.367 seconds

*/

//Another approach using stacks: https://www.geeksforgeeks.org/reverse-linked-list-groups-given-size-set-2/
