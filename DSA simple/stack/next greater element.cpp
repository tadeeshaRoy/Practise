/*
Reference: https://www.hackerrank.com/contests/second/challenges/next-greater-element/forum
https://www.geeksforgeeks.org/next-greater-element/
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	vector<long long> arr;
	stack<long long> s;
	long long n;
	cin>>n;
	
	vector<long long> ans (n, -1);
	int e;
	for(int i=0;i<n;i++)
	{
	    cin>>e;
	    arr.push_back(e);
	}
	
	for(int i=0;i<n;i++)
	{
	   while(!s.empty() && arr[i] > arr[s.top()])
	   {
	       int a = s.top();
	       s.pop();
	       ans[a] = arr[i];
	   }
	   s.push(i);
	}
	 
    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
	}
	return 0;
}
