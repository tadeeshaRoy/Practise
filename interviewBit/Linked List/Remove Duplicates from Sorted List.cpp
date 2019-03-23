/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

References: 

https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
https://www.youtube.com/watch?v=j3Kd06VfJhw

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    struct ListNode* head = A;
    struct ListNode* current = head, *next_next;
    
    if(current == NULL)
        return A;
        
    while(current->next!=NULL)
    {
        if(current->val == current->next->val)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
            current = current->next;
    }
    return head;
}
