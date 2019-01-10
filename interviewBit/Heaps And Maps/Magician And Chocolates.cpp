/*
Given N bags, each bag contains Ai chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Ai chocolates, then the magician fills the ith bag with floor(Ai/2) chocolates.

Given Ai for 1 <= i <= N, find the maximum number of chocolates kid can eat in K units of time.

For example,

K = 3
N = 2
A = 6 5

Return: 14

At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates
At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates
At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate
so, total number of chocolates eaten: 6 + 5 + 3 = 14

Note: Return your answer modulo 10^9+7


Priority queue : https://www.youtube.com/watch?v=vc7i0bBuQEM&fbclid=IwAR0vVrYU2W8hY37XY_ng84Zyqp0MByEMLV79zvMCj9hZaSFRYWPayYyUGhc
*/

int Solution::nchoc(int A, vector<int> &B) {
    
    int mod = 1000000007, k = A; long long int ans = 0;
    priority_queue<int> heap(B.begin(),B.end());
    while(k--)
    {
       long long int max = heap.top();
       ans += max;
       ans%=mod;
       heap.pop();
       heap.push((int)max/2);
    }
    return ans;
}
