/*
Given N and M find all stepping numbers in range N to M

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.
e.g 123 is stepping number, but 358 is not a stepping number

Example:

N = 10, M = 20
all stepping numbers are 10 , 12 
Return the numbers in sorted order.

Reference: https://www.geeksforgeeks.org/stepping-numbers/
*/

void bfs(int A,int B, int num, vector<int> &result)
{
    queue<int> q;
    q.push(num);
    
    while(!q.empty())
    {
        int stepNum = q.front();
        q.pop();
        
        if(stepNum>=A && stepNum<=B)
            result.push_back(stepNum);
            
        if (num == 0 || stepNum > B) 
            continue;
            
        int LastDigit = stepNum%10;
        
        int stepNumA = stepNum*10 + (LastDigit - 1);
        int stepNumB = stepNum*10 + (LastDigit + 1);
        
        if(LastDigit==0)
            q.push(stepNumB);
            
        else if(LastDigit == 9)
            q.push(stepNumA);
            
        else
        {
            q.push(stepNumA);
            q.push(stepNumB);
        }
    }
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> result;
    for(int i=0;i<=9;i++)
        bfs(A,B,i,result);
        
    sort(result.begin(),result.end());
    return result;
}
