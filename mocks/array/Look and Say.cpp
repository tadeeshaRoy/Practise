/*
Program for Look and Say. This can be illustrated by the example below:

for n=1 : 1
for n=2 : 11
for n=3 : 21
for n=4 : 1211
 and so on ..
 
 The code is just a basic walkthrough of the process. No special algorithm used. 
 
Reference: https://www.geeksforgeeks.org/look-and-say-sequence/
*/

#include<iostream>
#include<string>
using namespace std;

string lookAndSay(int n)
{
    if(n==1)
        return "1";

    if(n==2)
        return "11";

    string str="11";
    int cnt = 1;
    for(int i=3;i<=n;i++)
    {
        // For next loop, previous character is processed in current iteration. That is why a dummy character '$' is added 
        // to make sure that loop runs one extra iteration.
        str+='$';
        int len = str.length();
        string temp = ""; 
        for(int j=1;j<len;j++)
        {
            if(str[j]!=str[j-1])
            {
                temp+=cnt + '0';
                temp+= str[j-1];
                cnt=1;
            }
            else cnt++;
        }
        str = temp;
    }
    return str;
}

int main()
{
    int n=5;
    cout<<lookAndSay(n);
    
    return 0;
}
