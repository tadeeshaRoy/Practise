/*



Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

int Solution::isPalindrome(string A) {

    vector<char> B;
    
    for(int i=0;i<A.length();i++)
    {
        if(isalnum(A[i]))  //not isalpha because 'alphanumeric' from question.
            B.push_back(tolower(A[i])); // tolower for homogeneity
    }
    
    int n = B.size();
    
    for(int i=0;i<n;i++)
    {
        if(B[i]!=B[n-i-1])
            return 0;
    }
    return 1;
}
