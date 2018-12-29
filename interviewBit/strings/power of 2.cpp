/*

Find if Given number is power of 2 or not.
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input: number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output: return 1 if the number is a power of 2 else return 0

Sample:

Input : 128
Output : 1

*/

int Solution::power(string A) {
    
    int num = 0, n = A.length(), i = 0, j = 0;
    
    if(n==1 && A[n-1]=='1')
        return 0;
        
    while(n!=1 || A[n-1]!='1')
    {
        if((A[n-1]-'0')%2==1)
            return 0;
            
        for(i=0, j = 0; i<n;i++)
        {
            num = num*10 + A[i] - '0';        //num here puts the remainder before A[i], like 12 in 126 for i =1 
            
            if(num<2)
            {
                if(i!=0)
                    A[j++]='0';
                continue;
            }
            
            A[j++] = (int)(num/2) + '0';
            num = num - (num/2)*2;          //num here stores the remainder
        }
        A[j] = '\0';
        n = j;
    }
    return 1;
}
