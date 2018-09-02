//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//Examples:
// ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
// ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

int Solution::evalRPN(vector<string> &A) {
    int a,b;
    stack<int> s;
    char c;
    for(int i=0;i<A.size();i++)
    {
        c=A[i][0];
        if(c=='+' || A[i]=="-" || c=='*' || c=='/')        
        //A[i]=="-" is to distinguish b/w +ve and -ve numbers. Basically all the numbers and operands are separate strings
        // in the vector A.Example: ["2", "-4", "+"], here "2" or "+" are separate strings. A[i][0] extracts the first character
        // of each of these strings. Hence for "-4", '-' would be extracted as a separate operand in A[i][0] and hence we are 
        // considering a -ve operand only if the entire string is - and not just the first character.
        {
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            switch(c)
            {
                case '+':
                    s.push(a+b);
                    break;
                case '-':
                    s.push(b-a);
                    break;
                case '*':
                    s.push(b*a);
                    break;
                case '/':
                    s.push(b/a);
                    break;
            }
        }
        else
            s.push(atoi(A[i].c_str()));  //atoi is a function to convert a convertible string to integer. c_str converts a 
        //string in a format where c functions can understand since Strings in C and C++ are different.
    }
        
    return s.top();
}
