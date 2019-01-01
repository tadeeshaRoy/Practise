/*

Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is much greater than number of nodes on a level.

https://www.geeksforgeeks.org/print-level-order-traversal-line-line/
https://www.youtube.com/watch?v=86g8jAQug04
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
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    vector<vector<int>> res;
    
    if(A==NULL) return res;
    
    queue<TreeNode* > q;
    
    q.push(A);
    
    while(!q.empty())
    {
        int nodeCount = q.size();
        vector<int> temp;
        while(nodeCount)
        {
            TreeNode *node = q.front();
            temp.push_back(node->val);
            q.pop();
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
            nodeCount--;
        }
        res.push_back(temp);
    }
    return res;
}
