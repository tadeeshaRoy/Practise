/*

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

https://www.geeksforgeeks.org/find-excel-column-name-given-number/
*/

string Solution::convertToTitle(int A) {
    
    char str[256];
    
    long int rem=0,i=0;
    while(A>0)
    {
        rem=A%26;
        //cout<<"rem: "<<rem<<" ";
        if(rem==0)
        {
            str[i++] = 'Z';
            A = (A/26) - 1;
            //cout<<"str: "<<str[i];
            //cout<<"A: "<<A;
        }
        else
        {
            str[i++] = (rem - 1) + 'A';
            A = A/26;
            //cout<<"str: "<<str[i];
            //cout<<"A: "<<A;
        }
        //cout<<" A: "<<A<<endl;
        str[i] = '\0';
        //cout<<"str: "<<str[i];
    }
    int l = strlen(str);
    reverse(str,str+l);
    return str;
}
