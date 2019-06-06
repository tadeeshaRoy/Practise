/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 
The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.

*/

int n,m,k;

bool isExist(int a, int b, int index, vector<string> &A, string B)
{
    if(index == B.size())
        return true;
        
    if(a<0 || b<0 || a>=n || b>=m)
        return false;
        
    if(A[a][b]!=B[index])
        return false;
        
    return (isExist(a,b+1,index+1,A,B) || isExist(a,b-1,index+1,A,B) || 
            isExist(a+1,b,index+1,A,B) || isExist(a-1,b,index+1,A,B));
}

int Solution::exist(vector<string> &A, string B) {
    n = A.size();
    if(n==0)
        return 0;
    m = A[0].size();
    if(m==0)
        return 0;
    k = B.size();
    if(k==0)
        return 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==B[0])
            {
                bool temp = isExist(i,j,0,A,B);
                if(temp)
                    return 1;
            }
        }
    }
    return 0;
}
