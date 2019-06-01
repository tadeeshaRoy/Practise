int row,col;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

void bfs(int i, int j, vector<vector<char>> &A)
{
    queue<pair<int, int>> que;
    que.push(make_pair(i,j));
    
    while(!que.empty())
    {
        pair<int, int> p = que.front();
        que.pop();
        
        A[p.first][p.second] = 'O';
        
        for(int i=0;i<4;i++)
        {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            
            if((x>=0) && (x<row) && (y>=0) && (y<col) && A[x][y]=='-')
                que.push(make_pair(x,y));
        }
    }
}


void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    row = A.size();
    col = A[0].size();
    
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
            bfs(i,0,A);
    }
    for(int i=0;i<row;i++) // Right border
    {
        if(A[i][col-1]=='-')
            bfs(i,col-1,A);
    }
    for(int j=0;j<col;j++) // Top border
    {
        if(A[0][j]=='-')
            bfs(0,j,A);
    }
    for(int j=0;j<col;j++) // Bottom border
    {
        if(A[row-1][j]=='-')
            bfs(row-1,j,A);
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

*/
