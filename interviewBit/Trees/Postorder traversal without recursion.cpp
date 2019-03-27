/*
https://www.interviewbit.com/problems/postorder-traversal/

Given a binary tree, return the postorder traversal of its nodes’ values. Using recursion is not allowed.

Example :

Given binary tree

   1
    \
     2
    /
   3
   
 return [3,2,1].
 
 References:
 
using 2 stacks:

https://www.youtube.com/watch?v=G7tvjUGMBJ4
https://www.geeksforgeeks.org/iterative-postorder-traversal/


*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    vector<int> result;
    stack<TreeNode*> s1,s2;
    
    s1.push(A);
    
    while(!s1.empty())
    {
        TreeNode* node = s1.top();
        s1.pop();
        
        s2.push(node);
        
        if(node->left)
            s1.push(node->left);
            
        if(node->right)
            s1.push(node->right);
    }
    
    while(!s2.empty())
    {
        TreeNode* node = s2.top();
        result.push_back(node->val);
        s2.pop();
    }
    return result;
}
