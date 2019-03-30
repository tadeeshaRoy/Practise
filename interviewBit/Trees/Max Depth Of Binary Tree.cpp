/* https://www.interviewbit.com/problems/max-depth-of-binary-tree/

Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
max depth = 2.

Reference: https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
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
int Solution::maxDepth(TreeNode* A) {
    if(!A)
        return 0;
        
    TreeNode* node = A;
        
    int ldepth = maxDepth(node->left);
    int rdepth = maxDepth(node->right);
    
    if(ldepth > rdepth)
        return ldepth+1;
    else return rdepth+1;
        
}
