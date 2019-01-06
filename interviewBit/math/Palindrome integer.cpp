/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False

https://www.geeksforgeeks.org/write-a-program-to-reverse-digits-of-a-number/
with recursion: https://www.geeksforgeeks.org/check-if-a-number-is-palindrome/
*/

int Solution::isPalindrome(int A) {
    int rev = 0, num = A;
    while(num>0)
    {
        rev = rev*10 + num%10;
        num/=10;
    }
    if(rev == A)
        return 1;
    else return 0;
}

//sweetest code :P
