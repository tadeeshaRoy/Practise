/*
Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.

Recursive solution: https://www.youtube.com/watch?v=KYH83T4q6Vs
Iterative solution: https://www.youtube.com/watch?v=sYcOK51hl-A
*/

ListNode * head;
 ListNode * reverseUtil(ListNode* p){
     
      if(p==NULL)
        return NULL;
    if(p->next==NULL)
    {
        head=p;
        
        return p;
    }
    struct ListNode* q = reverseUtil(p->next);
    q->next=p;
    return p;
 }
 
 
 ListNode* Solution::reverseList(ListNode* A) {
    
    ListNode* node=reverseUtil(A);
     if(node!=NULL) node->next=NULL;
   return head;
}
