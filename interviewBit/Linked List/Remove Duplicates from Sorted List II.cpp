/*

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

Reference: https://www.geeksforgeeks.org/remove-occurrences-duplicates-sorted-linked-list/

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
    
    struct ListNode *dummy = new ListNode(0);
    dummy->next = A;
    struct ListNode *prev = dummy;
    struct ListNode* current = A;
    
    while(current!=NULL)
    {
        while(current->next!=NULL && prev->next->val == current->next->val)
            current = current->next;
            
        if(prev->next==current)
            prev = prev->next;
            
        else
            prev->next = current->next;
            
        current = current->next;
    }
    return (dummy->next);
}
