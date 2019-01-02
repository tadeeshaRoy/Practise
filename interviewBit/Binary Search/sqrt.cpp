/*

Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY

*/

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A==0 || A==1)
        return A;
    long int start = 1, end = A, mid, ans; // because 'int' led to overflow
    
    while(start<=end)
        {
            mid = (start+end)/2;
            
            if(mid*mid == A)
                return mid;
            
            else if(mid*mid<A)
            {
                start = mid + 1;
                ans = mid;
            }
            
            else end = mid - 1;
        }
    return ans;
}
