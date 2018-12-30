/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isValid(string A) {
    
    stack<int> B; char x;
    
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='(' || A[i]=='[' || A[i] == '{')
            B.push(A[i]);
        else if(B.empty())
            return 0;
        switch(A[i])
        {
            case ')':
               x=B.top();
               B.pop();
               if(x=='{' || x=='[')
                return 0;
            break;
            
            case '}':
               x=B.top();
               B.pop();
               if(x=='(' || x=='[')
                return 0;
            break;
            
            case ']':
               x=B.top();
               B.pop();
               if(x=='{' || x=='(')
                return 0;
            break;
        }
    }
    return (B.empty());
}
