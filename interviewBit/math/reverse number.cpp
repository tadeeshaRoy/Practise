/*
Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer
*/

int Solution::reverse(int A) {
    
    int rev = 0, num = abs(A), digit;
    /*cout<<INT_MAX<<endl;
    if(A>= INT_MAX || A<=INT_MIN)
           return 0;*/
    while(num>0)
    {
        digit=num%10;
        if(rev > (INT_MAX/10) || rev==(INT_MAX/10) && digit>(INT_MAX%10))
            return 0;
        rev = rev*10 + digit;
        //cout<<" rev: "<<rev;
        num/=10;
        //cout<<" num: "<<num<<endl;
    }
    //cout<<endl;
    if(A<0)
        return -rev;
    else return rev;
    
}

/*
Check point here is validating overflow:

if(rev > (INT_MAX/10) || rev==(INT_MAX/10) && digit>(INT_MAX%10))
            return 0;
            
*/

// easier one, to test

int Solution::reverse(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

     long long int rev=0,rem;
   
    while(A)
    {
        rem=1LL*(A%10);
        rev=rev*10+rem;
        A=A/10;
        if(rev>INT_MAX || rev<INT_MIN)
        return 0;
    }
    return rev;
    
}

//we need to check rev does not exceed limits after multiplied by 10
