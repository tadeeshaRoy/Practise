/* https://www.interviewbit.com/problems/edit-distance/
Given two words A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example : 
edit distance between
"Anshuman" and "Antihuman" is 2.

Operation 1: Replace s with t.
Operation 2: Insert i.

References: https://www.youtube.com/watch?v=Thv3TfsZVpw
https://www.geeksforgeeks.org/edit-distance-dp-5/

*/

int min(int x, int y, int z)
{
    return min(min(x,y),z);
}

int editDistance(string A, string B, int m, int n)
{
    int dist_arr[m+1][n+1];
    
    for(int i=0;i<=m;i++) //NOT i<m
    {
        for(int j=0;j<=n;j++) // NOT j<n
        {
            if(i==0)
                dist_arr[i][j]=j;
                
            else if(j==0) //NOT ELSE, you made that mistake
                dist_arr[i][j]=i;
                
            else if(A[i-1]==B[j-1]) 
                dist_arr[i][j]=dist_arr[i-1][j-1];
                
            else
             dist_arr[i][j] = 1 + min(dist_arr[i][j-1], //Insert
                            dist_arr[i-1][j], //Delete
                            dist_arr[i-1][j-1]); //Replace
        }
    }
    return dist_arr[m][n];
}

int Solution::minDistance(string A, string B) {
    
    return editDistance(A,B,A.length(),B.length());
    
}
