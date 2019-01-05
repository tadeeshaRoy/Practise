/*
Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 
*/

//My solution:

int Solution::titleToNumber(string A) {
    //char c = 'A';
    //cout<<int(c);
    
    int n = A.length(), p = n - 1, col_num = 0; char c;
    
    for(int i=0;i<n;i++)
    {
        c = A[i] - 64;
        col_num += pow(26,p)*c;
        p--;
    }
    
    return col_num;
}

// http://www.ascii-code.net/

// https://www.programiz.com/cpp-programming/examples/ASCII-value-character

// https://spreadsheeto.com/columns-numbers/

//InterviewBit solution:



class Solution {
public:
    int titleToNumber(string s) {
       int result = 0;
       for (int i = 0; i < s.size(); i++) {
               result = result * 26 + (s[i] - 'A' + 1);
       }
       return result;
    }
};

