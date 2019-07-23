/*

Check this for priority queue: https://stackoverflow.com/questions/19535644/how-to-use-the-priority-queue-stl-for-objects/33161479#answer-33161479

Merge k sorted linked lists and return it as one sorted list

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9

will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20

In the solution below, at a time, min heap will contain only k elements, not (number of elements in each k lists)*k 
So memory overflow is avoided ;)

reference: https://github.com/p4thakur/100DaysOfDataStructureAlgorithm/blob/master/Heap/Merge%20k%20sorted%20linked%20lists
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct compare
 {
     bool operator()(ListNode* a, ListNode* b)
     {
        return a->val > b->val;
     }
 };
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    priority_queue<ListNode*,vector<ListNode*>, compare> pq;
    
    for(int i=0;i<A.size();i++)
        pq.push(A[i]);
        
    ListNode* headNew = new ListNode(0);
    ListNode* iterator = headNew;
    while(!pq.empty())
    {
        ListNode* top = pq.top();
        pq.pop();
        
        iterator->next = top;
        iterator = iterator->next;
        
        if(top->next!=NULL)
            pq.push(top->next);
    }
    return (headNew->next);
    
}
