/* https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

Reference: Similar question: https://www.geeksforgeeks.org/print-paths-root-specified-sum-binary-tree/

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
 
 void paths(TreeNode* node,int sum_remaining,
 vector<int> &current,vector<vector<int>> &path)
 {
     if(node==NULL)
        return;
        
    else
    {
        sum_remaining-=node->val;
        current.push_back(node->val);
        
        if(node->left==NULL && node->right==NULL)
        {
            if(sum_remaining==0)
                path.push_back(current);
            current.pop_back();
            return;
        }
        
        paths(node->left,sum_remaining,current,path);
        paths(node->right,sum_remaining,current,path);
        
        current.pop_back();
        return;
    }
 }
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    
    vector<vector<int>> path;
    vector<int> current;
    paths(A,B,current,path);
    return path;
    
}
