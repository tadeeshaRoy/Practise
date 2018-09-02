int Solution::evalRPN(vector<string> &A) {
    int a,b;
    stack<int> s;
    char c;
    for(int i=0;i<A.size();i++)
    {
        c=A[i][0];
        if(c=='+' || A[i]=="-" || c=='*' || c=='/')
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
            s.push(atoi(A[i].c_str()));
    }
        
    return s.top();
}
