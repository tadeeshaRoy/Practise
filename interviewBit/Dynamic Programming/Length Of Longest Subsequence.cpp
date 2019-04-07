/* https://www.interviewbit.com/problems/length-of-longest-subsequence/

Given an array of integers, find the length of longest subsequence which is first increasing then decreasing.

**Example: **

For the given array [1 11 2 10 4 5 2 1]

Longest subsequence is [1 2 10 4 2 1]

Return value 6

Reference: https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/

*/

int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    int n = A.size();
    
    if(n==0 || (n==1 && A[0] == 0))
        return 0;
    
    vector<int> inc(n,1);
    vector<int> dec(n,1);
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[i]>A[j] && inc[i] < inc[j]+1)
                inc[i] = inc[j] + 1;
        }
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(A[i]>A[j] && dec[i] < dec[j]+1)
                dec[i] = dec[j] + 1;
        }
    }
    int max = inc[0] + dec[0] - 1;
    for(int i=1;i<n;i++)
    {
        if(max < (inc[i] + dec[i] - 1))
            max = inc[i] + dec[i] - 1;
    }
    
    return max;
    
}
