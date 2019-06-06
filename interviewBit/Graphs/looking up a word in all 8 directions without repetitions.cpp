/*

Given a 2D grid of characters and a word, find all occurrences of given word in grid. 
A word can be matched in all 8 directions at any point. 
Word is said be found in a direction if all characters match in this direction (not in zig-zag form).
Reference: https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/
*/

// C++ program to count number of distinct 
// subsequences of a given string. 
#include <vector> 
#include<string>
#include<iostream>
#define R 3
#define C 14
using namespace std; 
int dx[8] = {1, 0, 0, 1, 1, -1, -1, -1};
int dy[8] = {0, 1, -1, 1, -1, 1, 0, -1};

bool search2D(int r,int c, int index, char grid[R][C], string word)
{
    if(grid[r][c]!=word[0])
        return false;

    int len = word.length();

    for(int dir = 0; dir<8; dir++)
    {
        int rd = r + dx[dir], cd = c + dy[dir], k;

        for(k=1;k<len;k++)
        {
            if(rd<0 || cd<0 || rd>=R || cd>=C)
                break;

            if(grid[rd][cd]!=word[k])
                break;

            rd += dx[dir], cd+= dy[dir];
        }
        if(k==len)
            return true;
    }
    return false;
}

void patternSearch(char grid[R][C], string word)
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
                if(search2D(i,j,0,grid,word))
                    cout<<"pattern found at row: "<<i+1<<" col: "<<j+1<<endl;
        }
    }
}

int main() 
{ 

char grid[R][C] = {"GEEKSFORGEEKS", 
                  "GEEKSQUIZGEEK", 
                  "IDEQAPRACTICE"
                }; 

patternSearch(grid, "GEEKS"); 

cout<<"\n------------------------------------------\n";

patternSearch(grid, "EEE"); 

return 0; 
} 
