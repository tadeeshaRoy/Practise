/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.

Example :

Input : 
   1
  /  \
 2    3

Output : 0 or False


Input : 
  2
 / \
1   3

Output : 1 or True 

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Reference: https://www.youtube.com/watch?v=yEwSGhSsT0U

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
 bool IsBstUtil(TreeNode* A, int minValue, int maxValue)
 {
     if(A==NULL) return true;
     if(A->val > minValue && A->val < maxValue && 
     IsBstUtil(A->left, minValue,A->val) &&
     IsBstUtil(A->right,A->val,maxValue))
        return true;
    else return false;
 };
 
int Solution::isValidBST(TreeNode* A) {
    
    return IsBstUtil(A,INT_MIN,INT_MAX);
}

//We can also use in-order here, keeping track of the previous node visited
