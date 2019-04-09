/* https://www.interviewbit.com/problems/min-sum-path-in-matrix/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time. 
Example :

Input : 

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output : 8
     1 -> 3 -> 2 -> 1 -> 1
     
References: https://www.geeksforgeeks.org/min-cost-path-dp-6/

How to define 2D vector: 
    
    int m=A.size();
    int n=A[0].size();
    
    vector<vector<int> > dp(m, vector<int>(n,0));

*/

/*
In case diagonal is allowed as well
int min(int x,int y, int z)
{
    if(x<y)
        return (x<z)?x:z;
    else return (y<z)?y:z;
}*/

int Solution::minPathSum(vector<vector<int> > &A) {
    
    int m=A.size(), n=A[0].size(); 
    vector<vector<int>> temp(m);
    
    for(int i=0;i<m;i++)
        temp[i]=vector<int>(n);
    
    temp[0][0] = A[0][0];
    
    for(int i=1;i<m;i++)
        temp[i][0] = temp[i-1][0] + A[i][0];
        
    for(int j=1;j<n;j++)
        temp[0][j] = temp[0][j-1] + A[0][j];
    
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
            temp[i][j] = min(temp[i][j-1],temp[i-1][j])+A[i][j];
    }
    
    return temp[m-1][n-1];
}


//interviewBit solution

int Solution::minPathSum(vector<vector<int> > &A) {
       if(A.size() == 0){
        return 0;
    }
    
    int rows = A.size();
    int cols = A[0].size();
    
    vector<vector<int> > temp(rows, vector<int>(cols));
    
    int sum = 0;
    
    for(int i = 0; i < cols; i++){
        temp[0][i] = sum + A[0][i];
        sum = temp[0][i];
    }
    
    sum = 0;
    
    for(int i = 0; i < rows; i++){
        temp[i][0] = sum + A[i][0];
        sum = temp[i][0];
    }
    
    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            temp[i][j] = A[i][j] + min(temp[i-1][j], temp[i][j-1]);
        }
    }
    
    return temp[rows-1][cols-1];
}

