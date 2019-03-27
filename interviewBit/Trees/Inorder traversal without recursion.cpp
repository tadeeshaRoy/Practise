/*
https://www.interviewbit.com/problems/inorder-traversal/

Given a binary tree, return the inorder traversal of its nodes’ values. Using recursion is not allowed.

Example :
Given binary tree

   1
    \
     2
    /
   3
   
 return [1,3,2].
 
 Reference: https://www.youtube.com/watch?v=VsxLHGUqAKs (https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/)
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
vector<int> Solution::inorderTraversal(TreeNode* A) {

    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* current = A;
    
    while(current!=NULL || !s.empty())
    {
        while(current!=NULL)
        {
            s.push(current);
            current=current->left;
        }
        current=s.top();
        s.pop();
        result.push_back(current->val);
        current=current->right;
    }
    return result;
}
