/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :
 5 -> 8 -> 20 
 4 -> 11 -> 15
 
 The merged list should be :
 4 -> 5 -> 8 -> 11 -> 15 -> 20
*/

//InterviewBit solution:

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    struct ListNode *head = NULL;
    
    if(A==NULL)
        return B;
    else if(B==NULL)
        return A;
    else if(A->val <= B->val)
    {
        head = A;
        A = A->next;
    }
    else 
    {
        head = B;
        B = B->next;
    }
    
    struct ListNode *p = head;
    
    while(A && B)
    {
        if(A->val <= B->val)
        {
            p->next = A;
            A = A->next;
        }
        else 
        {
            p->next = B;
            B = B->next;
        }
        p = p->next;
    }
    
    if(A)
        p->next = A;
    
    else if(B)
        p->next = B;
        
    return head;
}

//Using recursion. Remember result->next in recursion to add links to nodes returned by each call

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    struct ListNode *result = NULL;
    
    if(A==NULL)
        return (B);
    else if(B==NULL)
        return (A);
        
    if(A->val < B->val)
    {
        result = A;
        result->next = mergeTwoLists(A->next,B);
    }
    else
    {
        result = B;
        result->next = mergeTwoLists(A,B->next);
    }
    
    return result;
}


//Using references -> Not recommended because can cause maximum confusion:

 void MoveNode(struct ListNode **destNode, struct ListNode **sourceNode)
 {
     struct ListNode *newNode = *sourceNode;
     assert(newNode !=NULL);
     *sourceNode = newNode->next;
     newNode->next = *destNode;
     *destNode = newNode;
 }
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    struct ListNode *result = NULL;
    struct ListNode **tail = &result;
    
    while(1)
    {
        if(A==NULL)
        {
            *tail = B;
            break;
        }
            
        if(B==NULL)
        {
            *tail = A;
            break;
        }
            
        if(A->val <= B->val)
            MoveNode(tail,&A);
            
        else
            MoveNode(tail,&B);

        tail = &((*tail)->next);
    }
    return (result);
}
