/*
The following code implements heap data structure in C++

Reference: https://www.geeksforgeeks.org/binary-heap/
*/


#include<bits/stdc++.h>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap
{
    int *harr;
    int heap_size;
    int capacity;

    public:
        MinHeap(int capacity);

        void MinHeapify(int );
        int parent(int i){ return (i-1)/2;}
        int left(int i){return (2*i + 1);}
        int right(int i){return (2*i + 2);}

        int extractMin();

        int getMin(){ return harr[0];}

        void decreaseKey(int i, int new_val);

        void deleteKey(int i);

        void insertKey(int i);
};

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
    if(heap_size==capacity)
    {
        cout<<"Heap OverFlow";
        return;
    }
    
    int i = heap_size;
    heap_size++;
    harr[i] = k;

    while(i!=0 && harr[parent(i)]>harr[i])
    {
        swap(harr[parent(i)], harr[i]);
        i=parent(i);
    }
}

int MinHeap::extractMin()
{
    if(heap_size<0)
        return INT_MAX;

    if(heap_size==1)
    {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;

    MinHeapify(0);

    return root;
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l<heap_size && harr[l]<harr[i])
        smallest = l;
    if(r<heap_size && harr[r]<harr[smallest])
        smallest = r;

    if(i!=smallest)
    {
        swap(&harr[i],&harr[smallest]);
        MinHeapify(smallest);
    }
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::decreaseKey(int i, int new_value)
{
    harr[i] = new_value;
    while(i!=0 && harr[parent(i)]>harr[i])
    {
        swap(harr[parent(i)],harr[i]);
        i = parent(i);
    }
}

int main()
{
    MinHeap h(10);
    h.insertKey(4);
    h.insertKey(2);
    h.insertKey(1);
    h.deleteKey(1);
    h.deleteKey(0);
    h.decreaseKey(0,2);
    cout<<h.getMin()<<endl;
    return 0;
}
