/* Given a 2D array, print it in spiral form. See the following examples.
Examples:

Input:
        1    2   3   4
        5    6   7   8
        9   10  11  12
        13  14  15  16
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 


Input:
        1   2   3   4  5   6
        7   8   9  10  11  12
        13  14  15 16  17  18
Output: 
1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11 

Reference: https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/ */

#include<iostream>

using namespace std;

void spiralView(int arr[3][3], int m, int n)
{
    if(m==0)
        return;
    if(m==1 && n==1)
    {
        cout<<arr[0][0];
        return;
    }

    int x = 0, y = 0;

    while(x<m && y<n)
    {
        for(int j = y; j<n; j++)
            cout<<arr[x][j]<<" ";
        x++;

        for(int i = x; i<m; i++)
            cout<<arr[i][n-1]<<" ";
        n--;

        for(int j = n - 1; j>=y; j--)
            cout<<arr[m-1][j]<<" ";
        m--;

        for(int i = m - 1; i>=x; i--)
            cout<<arr[i][y]<<" ";
        y++;
    }
}

void printArray(int arr[][3], int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int arr[3][3] = { {1, 2, 3},
                      {8, 9, 4},
                      {7, 6, 5}};
    
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = sizeof(arr[0])/sizeof(arr[0][0]);

    printArray(arr, m, n);

    spiralView(arr, m, n);

    return 0;
}
