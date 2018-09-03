// Given an array, find the nearest smaller element G[i] for every element A[i] in the array 
// such that the element has an index smaller than i.
// More formally,

// G[i] for an element A[i] = an element A[j] such that 
//    j is maximum possible AND 
//    j < i AND
//    A[j] < A[i]

// Elements for which no smaller element exist, consider next smaller element as -1.

//Example:

// Input : A : [4, 5, 2, 10, 8]
// Return : [-1, 4, -1, 2, 2]

// https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/

vector<int> Solution::prevSmaller(vector<int> &A) {
    
    int n=A.size();
    vector<int> ans(n,-1);
    stack<int> st;
    
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top()>=A[i])
            st.pop();
        if(!st.empty()) ans[i]=st.top();
        st.push(A[i]);
    }
    return ans;
}

Algorithm:

// Let input sequence be 'arr[]' and size of array be 'n'

// 1) Create a new empty stack S

// 2) For every element 'arr[i]' in the input sequence 'arr[]', where 'i' goes from 0 to n-1.
    
//    a) while S is nonempty and the top element of S is greater than or equal to 'arr[i]':
           // pop S
    
//    b) if S is empty:
           // 'arr[i]' has no preceding smaller value
//    c) else:
           // the nearest smaller value to 'arr[i]' is the top element of S

//    d) push 'arr[i]' onto S
