/* https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.

Reference: https://leetcode.com/problems/remove-nth-node-from-end-of-list/solution/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    ListNode* dummy = new ListNode(0);
    dummy->next = A;
    
    struct ListNode* iterate = A;
    
    int len = 0;
    
    while(iterate!=NULL)
    {
        iterate=iterate->next;
        len++;
    }

    ListNode* iterate2 = A;
    
    if(B>=len)
        dummy->next=dummy->next->next;
    
    else
    {
        int m=len-B-1;
        while(m--)
            iterate2 = iterate2->next;
        
        iterate2->next = iterate2->next->next;
    }
    return dummy->next;
}
