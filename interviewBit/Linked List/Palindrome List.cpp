/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.

For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 void reverse(struct ListNode** head_ref)
 {
     struct ListNode *prev = NULL;
     struct ListNode *curr = *head_ref;
     struct ListNode *nextNode;
     
     while(curr!=NULL)
     {
         nextNode = curr->next;
         curr->next = prev;
         prev = curr;
         curr = nextNode;
     }
     *head_ref = prev;
 }
 bool compareLists(struct ListNode* head1, struct ListNode* head2)
 {
     struct ListNode* temp1 = head1;
     struct ListNode* temp2 = head2;
     
     while(temp1 && temp2)
     {
         if(temp1->val == temp2->val)
         {
             temp1 = temp1->next;
             temp2 = temp2->next;
         }
         else return 0;
     }
     if(temp1 == NULL && temp2 == NULL)
        return 1;
        
    return 0;
 }
 int Solution::lPalin(ListNode* A) {
    
    struct ListNode *slow_ptr = A, *fast_ptr = A, *midNode = NULL;
    struct ListNode *second_half, *prev_of_slow = A;
    int res = true;
    
    if(A!=NULL && A->next!=NULL)
    {
    while(fast_ptr!=NULL && fast_ptr->next!=NULL)
    {
        fast_ptr = fast_ptr->next->next;
        prev_of_slow = slow_ptr;
        slow_ptr = slow_ptr->next;
    }
    
    if(fast_ptr != NULL)
    {
        midNode = slow_ptr;
        slow_ptr = slow_ptr->next;
    }
    
    second_half = slow_ptr;
    prev_of_slow->next = NULL;
    
    reverse(&second_half);
    res = compareLists(A,second_half);
    }
    return res;
}
