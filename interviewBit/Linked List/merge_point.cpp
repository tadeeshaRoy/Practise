/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

https://www.youtube.com/watch?v=gE0GopCq378 

https://gist.github.com/mycodeschool/5bc53cb87905f95e12b3

** always confirm whether it is A!= NULL or A->next!= NULL ** 

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int length(struct ListNode* A)
 {
     int len=0;
     while(A!=NULL)
     {
        len++;
        A = A->next;
     }
    return len;
 }
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int m=length(A), n=length(B);
    int d=n-m;
    if(m>n)
    {
        struct ListNode* temp = A;
        A=B;
        B=temp;
        d=m-n;
    }
    for(int i=0;i<d;i++)
        B = B->next;
        
    while(A!=NULL && B!=NULL)
    {
        if(A==B)
            return A;
        A = A->next;
        B = B->next;
    }
    return NULL;
}
