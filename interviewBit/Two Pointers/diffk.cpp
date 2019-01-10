/*
Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

    Example:

    Input : 

    A : [1 3 5] 
    k : 4

    Output : YES

    as 5 - 1 = 4 

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.

https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/
*/

int Solution::diffPossible(vector<int> &A, int B) {
    int i = 0, j = 1, l = A.size();
    while(i<l && j<l)
    {
        if(i!=j && A[j]-A[i]==B)          // don't forget to check if i==j, you made that mistake! else for 0 it'll return true always
            return 1;
        else if(A[j]-A[i]<B)
            j++;
        else i++;
    }
    return 0;
}
