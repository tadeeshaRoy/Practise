/*https://www.interviewbit.com/problems/invert-the-binary-tree/

Given a binary tree, invert the binary tree and return it. 
Look at the example for more details.

Example : 
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4

Reference: https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
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
void mirror(TreeNode* node)
 {
    if(node==NULL)
        return ;
    else
    {
        TreeNode* temp = node;
        
        mirror(node->left);
        mirror(node->right);
        
        temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        //return node;
    }
 }
 
TreeNode* Solution::invertTree(TreeNode* A) {
    
    TreeNode* node = A;
    
    if(A==NULL)
        return A;
    else
    {
        mirror(A);
        return A;
    }
}
