/*
Given a number N, find all prime numbers upto N ( N included ).

Example:

if N = 7,

all primes till 7 = {2, 3, 5, 7}

Make sure the returned array is sorted.

Problem Approach:

Complete code in the hint.

Sieve of Eratosthenes

https://www.youtube.com/watch?v=eKp56OLhoQs
*/

vector<int> Solution::sieve(int A) {
    vector<int> res;
    int *primes = new int [A+1];
    for(int i=0;i<A;i++)
        primes[i]=1;
    primes[0] = 0;
    primes[1] = 0;
    
    for(int i=2;i<sqrt(A);i++)
    {
        if(primes[i]==1)
        {
            for(int j=2;i*j<A;j++)
                primes[i*j]=0;
        }
    }
    for(int i=0;i<A;i++)
    {
        if(primes[i]==1)
            res.push_back(i);
    }
    return res;
}
