// DID NOT SUBMIT SUCCESSFULLY ON CODECHEF ALTHOUGH ALL CUSTOM TEST CASES WERE PASSING

/*
There's an array A consisting of N non-zero integers A1..N. A subarray of A is called alternating if any two adjacent elements in it have different signs (i.e. one of them should be negative and the other should be positive).

For each x from 1 to N, compute the length of the longest alternating subarray that starts at x - that is, a subarray Ax..y for the maximum possible y ≥ x. The length of such a subarray is y-x+1.

Input
The first line of the input contains an integer T - the number of test cases.
The first line of each test case contains N.
The following line contains N space-separated integers A1..N.
Output
For each test case, output one line with N space-separated integers - the lengths of the longest alternating subarray starting at x, for each x from 1 to N.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
-109 ≤ Ai ≤ 109
Example
Input:
3
4
1 2 3 4
4
1 -5 1 -5
6
-5 -1 -1 2 -2 -3

Output:
1 1 1 1
4 3 2 1
1 1 3 2 1 1

https://github.com/coderbond007/Codechef-Solutions-C-Language/blob/master/Alternating%20subarray%20prefix%20ALTARY.c
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
	cin>>t;
	while(t--)
	{
	    int n, e, k=0,cnt=1;
	    cin>>n;
	    vector<int> arr,res;
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>e;
	        arr.push_back(e);
	    }
	    res.push_back(1);
	    for(int i=n-2;i>=0;i--)
	    {
	        if(arr[i]*arr[i+1]<0)
	            res.push_back(++cnt);
	       else
	       {
	           res.push_back(1);cnt=1;
	       }
	    }
	    reverse(res.begin(),res.end());
	    for(int i=0;i<n;i++)
	        cout<<res[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
