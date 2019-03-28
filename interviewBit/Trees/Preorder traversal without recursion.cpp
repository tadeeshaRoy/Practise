/* https://www.interviewbit.com/problems/preorder-traversal/
Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
   
 return [1,2,3].

Using recursion is not allowed.

Reference: https://www.geeksforgeeks.org/iterative-preorder-traversal/
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
vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    vector<int> result;
    
    if(A==NULL)
        return result;
        
    stack<TreeNode*> s;
    
    s.push(A);
    
    while(!s.empty())
    {
        TreeNode* node = s.top();
        s.pop();
        result.push_back(node->val);
        
        if(node->right)
            s.push(node->right);
            
        if(node->left)
            s.push(node->left);
    }
    return result;
}
