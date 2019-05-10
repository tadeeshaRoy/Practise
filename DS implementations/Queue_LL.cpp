#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

class Queue
{
    Node* front;
    Node* rear;

    public:
        Queue()
        {
            front=rear=NULL;
        }

        void enqueue(int data)
        {
            Node* temp = new Node();
            temp->val = data;
            temp->next = NULL;

            if(front == NULL)
                front = rear = temp;

            else
            {
                rear->next = temp;
                rear = temp;
            }
            
        }

        void dequeue()
        {
            if(front == NULL)
                cout<<"Queue empty";

            else
            {
                Node* temp = front;

                if(front == rear)
                    front = rear = NULL;

                else
                    front = front->next;

                free(temp);
            }
            
        }

        int Front()
        {
            if(front == NULL)
            {
                cout<<"empty queue";
                return -1;
            }
            else return front->val;
        }

        void print()
        {
            if(front==NULL)
                cout<<"Cannot print empty queue";
            else
            {
                Node* temp = front;
                while(temp!=NULL)
                {
                    cout<<temp->val<<"->";
                    temp = temp->next;
                }
                cout<<"NULL";
            }
        }
};

int main()
{
    Queue Q;
    Q.enqueue(1);
    Q.enqueue(2);
    cout<<"Front of the queue is: "<<Q.Front()<<endl;
    Q.enqueue(4);
    Q.enqueue(11);
    Q.print();
    cout<<endl;
    Q.dequeue();
    Q.dequeue();
    Q.print();
    cout<<endl;
    Q.dequeue();
    Q.dequeue();
    Q.print();
    return 0;
}
