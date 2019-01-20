/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.

https://www.geeksforgeeks.org/noble-integers-in-an-array-count-of-greater-elements-is-equal-to-value/
*/

int Solution::solve(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    int l = A.size();
    /*cout<<"length: "<<l;
    cout<<"sorted array: ";
    for(int i=0;i<l;i++)
        cout<<A[i]<<" ";
    cout<<endl;*/
    
    for(int i=0;i<l;i++)
    {
        if(A[i]==A[i+1]) //catch here for inputs like 11111112
            continue;
        if(A[i]==l-i-1)
            return 1;
    }
    if(A[l-1]==0) 
        return 1;
    return -1;
}
