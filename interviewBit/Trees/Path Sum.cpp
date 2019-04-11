/* https://www.interviewbit.com/problems/path-sum/

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

References: https://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/ , https://www.youtube.com/watch?v=Jg4E4KZstFE&t=206s
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
 
 bool check_sum(TreeNode* A,int sum)
 {
     if(A==NULL)
        return (sum==0);
    
    else
    {
        bool ans = 0;
        int subsum = sum - A->val;
        if(!A->left && !A->right && subsum == 0)
            return 1;
            
        if(A->left)
            ans = ans || check_sum(A->left,subsum);
            
        if(A->right)
            ans = ans || check_sum(A->right,subsum);
            
        return ans;
    }
 }
 
int Solution::hasPathSum(TreeNode* A, int B) {
    
    return (check_sum(A,B));
}
