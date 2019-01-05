/*

GeeksForGeeksSolution: https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

        NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*

*/

int findPivot(vector<int> A, int low, int high)  // Binary search 1 to find Pivot element
{
    if(high<low)
        return -1;
    if(high == low)
        return low;
    
    int mid = (low+high)/2;
    
    if(mid<high && A[mid]>A[mid+1])
        return mid;
    if(mid>low && A[mid]<A[mid - 1])
        return mid-1;
    if(A[low]>=A[mid])
        return findPivot(A,low,mid-1);
    return findPivot(A,mid+1,high);
}
int binarySearch(vector<int> A, int low, int high, int key) //Binary Search 2 to find the key
{
    if(high<low)
        return -1;
    int mid = (low+high)/2;
    if(A[mid]==key)
        return mid;
    if(key>A[mid])
        return binarySearch(A,mid+1,high,key);
    else return binarySearch(A,low,mid-1,key);
}
int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size(), low = 0; int high = n;
    int pivot = findPivot(A, 0, n-1);
    if(pivot==-1)
        return binarySearch(A,0,n-1,B);
    if(A[pivot]==B)
        return pivot;
    if(A[0]<B)
        return binarySearch(A,0,pivot-1,B);
    else return binarySearch(A,pivot+1,n-1,B);
}
