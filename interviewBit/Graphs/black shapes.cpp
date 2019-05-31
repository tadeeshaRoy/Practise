/*

Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

Example:

OOOXOOO
OOXXOXO
OXOOOXO

answer is 3 shapes are  :
(i)    X
     X X
(ii)
      X
 (iii)
      X
      X

Note that we are looking for connected shapes here.

For example,

XXX
XXX
XXX

is just one single connected black shape.

*/

int N,M;

int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

bool isValid(int x, int y)
{
    if(x<0 || x>=N || y<0 || y>=M)
        return false;
        
    return true;
}

void bfs(int i, int j, vector<string> &A)
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
            
            if(isValid(x,y) && A[x][y]=='X')
                bfs(x,y,A);
        }
        
    }
}

int Solution::black(vector<string> &A) {
    
    N = A.size();
    M = A[0].size();
    
    int cnt = 0;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i][j]=='X')
            {
                cnt++;
                bfs(i,j,A);
            }
        }
    }
    
    return cnt;
}
