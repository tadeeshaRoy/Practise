//Reference: https://gist.github.com/mycodeschool/7331785

#include<iostream>
#define MAXSIZE 10

using namespace std;

class Queue
{
    private:
        int arr[MAXSIZE];
        int front,rear;

    public:

        Queue()
        {
            front = rear = -1;
        }

        bool isEmpty()
        {    
            return (front==-1 && rear==-1);
        }

        bool isFull()
        {
            return ((rear+1)%MAXSIZE==front);
        }

        void Enqueue(int data)
        {
            cout<<"\nEnqueue initiated\n";
            if(isFull())
                cout<<"Queue Overflow!";

            else if(isEmpty())
                front = rear = 0;

            else
                rear = (rear+1)%MAXSIZE;

            arr[rear] = data;
        }

        void Dequeue()
        {
            cout<<"\nDequeue initiated\n";
            if(isEmpty())
                cout<<"Queue Underflow!";

            else if(front==0 && rear==0)
            {
                front = -1; rear = -1;
            }
            else 
                front = (front+1)%MAXSIZE;
        }

        int Front()
        {
            if(front==-1)
            {
                    cout<<"Error: No element in the queue";
                    return -1;
            }
            else return arr[front];
        }

        int Rear()
        {
            if(rear==-1)
            {
                cout<<"Error: No element in the queue";
                return -1;
            }
            else return arr[rear];
        }

        void print()
        {
            cout<<"Current state of the queue: ";
            int count = (rear+MAXSIZE-front)%MAXSIZE;
            for(int i=0;i<=count;i++)
            {
                int index = (front+i)%MAXSIZE;
                cout<<arr[index];
            }
        }
};

int main()
{
    Queue Q;

    Q.Enqueue(1); Q.print();
    Q.Enqueue(2); Q.print();
    Q.Enqueue(4); Q.print();
    Q.Enqueue(5); Q.print();
    Q.Enqueue(6); Q.print();

    Q.Dequeue(); Q.print();

    cout<<"Front of the Queue: "<<Q.Front();

    cout<<"Rear of the Queue: "<<Q.Rear();

}
