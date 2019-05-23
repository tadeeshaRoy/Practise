/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Reference: https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/
*/

void floodfilluntil(vector<vector<char>> &A, int row, int col, int M, int N, char prevV, char newV)
{
    if(row<0 || row>=M || col<0 || col>=N)
        return;
        
    else if(A[row][col]!=prevV)
        return;
        
    A[row][col] = newV;
    
    floodfilluntil(A, row-1, col, M, N, prevV, newV);
    floodfilluntil(A, row+1, col, M, N, prevV, newV);
    floodfilluntil(A, row, col-1, M, N, prevV, newV);
    floodfilluntil(A, row, col+1, M, N, prevV, newV);
}


void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int row = A.size();
    int col = A[0].size();
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(A[i][j]=='O')
                A[i][j] = '-';
        }
    }
    
    for(int i=0;i<row;i++) // Left border
    {
        if(A[i][0]=='-')
            floodfilluntil(A,i,0,row,col,'-','O');
    }
    for(int i=0;i<row;i++) // Right border
    {
        if(A[i][col-1]=='-')
            floodfilluntil(A,i,col-1,row,col,'-','O');
    }
    for(int j=0;j<col;j++) // Top border
    {
        if(A[0][j]=='-')
            floodfilluntil(A,0,j,row,col,'-','O');
    }
    for(int j=0;j<col;j++) // Bottom border
    {
        if(A[row-1][j]=='-')
            floodfilluntil(A,row-1,j,row,col,'-','O');
    }
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(A[i][j]=='-')
                A[i][j] = 'X';
        }
    }
    
}
