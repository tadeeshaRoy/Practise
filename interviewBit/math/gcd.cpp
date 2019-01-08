/*
Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.

Example

m : 6
n : 9

GCD(m, n) : 3 

https://www.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/
https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
https://www.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/?fbclid=IwAR2bFW6CguRTJ2e1buFdLAgp2yvJLMtymD7E3iELVqAgPbboUXP6yTRgXoI
*/


//One line code:
// return B ? gcd(B,A%B) : A;

int Solution::gcd(int A, int B) {
    
    if(A==0) return B;
    if(B==0) return A;
    if(A==B) return A;
    
    if(A>B)
        return gcd(A-B,B);    //continuously dividing one number with another
    else return gcd(A,B-A);
}
