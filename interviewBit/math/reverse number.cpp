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
