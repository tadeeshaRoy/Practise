// https://www.interviewbit.com/problems/valid-path/


bool check(int x,int y,int r,vector<int> E, vector<int> F)
{
    int R = r*r;
    
    for(int i=0;i<E.size();i++)
    {
        int dx = x - E[i];
        int dy = y - F[i];
        
        dx = dx*dx;
        dy = dy*dy;
        
        if(dx+dy<=R)
            return true;
    }
    return false;
}

bool safe(int a, int b, int x, int y)
{
    if(x>=0 && y>=0 && x<=a && y<=b)
        return true;
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    
    queue<pair<int,int>> que;
    
    bool visited[A+1][B+1];
    
    memset(visited,false, sizeof(visited));
    
    visited[0][0] = true;
    
    que.push(make_pair(0,0));
    
    while(!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        
        que.pop();
        
        if(x==A && y==B)
            return "YES";
            
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                if(i==0&&j==0)
                    continue;
                    
                if(!check(x+i,y+j,D,E,F) && safe(A,B,x+i,y+j) && !visited[x+i][y+j])
                {
                    que.push(make_pair(x+i,y+j));
                    visited[x+i][y+j]=true;
                }
            }
        }
    }
    
    return "NO";
    
}



/*

There is a rectangle with left bottom as (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.
Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.


Input Format

1st argument given is an Integer x.
2nd argument given is an Integer y.
3rd argument given is an Integer N, number of circles.
4th argument given is an Integer R, radius of each circle.
5th argument given is an Array A of size N, where A[i] = x cordinate of ith circle
6th argument given is an Array B of size N, where B[i] = y cordinate of ith circle

Output Format

Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).

Constraints

0 <= x, y, R <= 100
1 <= N <= 1000
Center of each circle would lie within the grid

For Example

Input:
    x = 2
    y = 3
    N = 1
    R = 1
    A = [2]
    B = [3]
Output:
    NO
   
Explanation:
    There is NO valid path in this case

*/
