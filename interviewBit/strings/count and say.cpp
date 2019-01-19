/*

The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...

1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.

https://www.geeksforgeeks.org/look-and-say-sequence/

*/

string Solution::countAndSay(int A) {
    
    if(A==1) return "1";
    if(A==2) return "11";
    
    string str = "11";
    for(int i=3;i<=A;i++)
    {
        str+='$'; string tmp = "";
        int l = str.length(), cnt = 1;
        for(int j=1;j<l;j++)
        {
            if(str[j]!=str[j-1])
            {
                tmp+= cnt + '0';           //not tmp = cnt + '0' else it will overwrite the previous tmp chars
                tmp+=str[j-1];
                cnt = 1;    //missed this on revision
            }
            
            else cnt++;
        }
        str = tmp;
    }
    return str;
}
