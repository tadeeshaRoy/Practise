    int Solution::isValid(string A) {
        
        stack<int>S; char x;
        int checkpair(char a, char b);
        for(int i=0;i<A.size();i++)
        {
            if(A[i]=='(' || A[i]=='{' || A[i]=='[')
              S.push(A[i]);
            else if(A[i]==')' || A[i]=='}' || A[i]==']')
                {
                    if(S.empty())
                        return 0;
                    switch (A[i])
                    {
                        case ')':
                            x=S.top();
                            S.pop();
                            if(x=='{' || x=='[')
                                return 0;
                            break;
                            
                        case '}':
                            x=S.top();
                            S.pop();
                            if(x=='(' || x=='[')
                                return 0;
                            break;
                            
                        case ']':
                            x=S.top();
                            S.pop();
                            if(x=='(' || x=='{')
                                return 0;
                            break;
                    }
                }
        }
        return (S.empty());
    }
