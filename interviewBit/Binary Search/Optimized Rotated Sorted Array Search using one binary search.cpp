/*

InterviewBit solution



Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

        NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*


*/

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size(), low = 0; int high = n; int mid;
   while(low<=high)
   {
       mid=(high-low)/2 + low;
       //cout<<low<<" "<<high<<" "<<mid<<"A="<<A[mid]<<endl;
       if(A[mid]==B)
            return mid;
        if(A[low]<=A[mid])
        {
            if(B>=A[low] && B<=A[mid])
                high = mid - 1;
            else low = mid + 1;
        }
        else                              
        {   //understand the bracket here, u missed it once!
            if(B>=A[mid] && B<=A[high])
                low = mid + 1;
            else high = mid - 1;
        }
   }
   return -1;
}
