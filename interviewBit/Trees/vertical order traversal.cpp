//Given a binary tree, print a vertical order traversal of it.

// https://www.youtube.com/watch?v=5u7n4jWx5r0      //https://www.geeksforgeeks.org/print-a-binary-tree-in-vertical-order-set-3-using-level-order-traversal/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    
    vector<vector<int>> result;
    
    if(A==NULL)
        return result;
        
    map <int,vector<int>> m;
    int hd = 0;
    
    queue<pair<TreeNode*,int>> que;
    que.push(make_pair(A,hd));
    
    while(!que.empty())
    {
        pair<TreeNode*, int> temp = que.front();
        que.pop();
        hd = temp.second;
        TreeNode* node = temp.first;
        
        m[hd].push_back(node->val);
        
        if(node->left!=NULL)
            que.push(make_pair(node->left,hd-1));
            
        if(node->right!=NULL)
            que.push(make_pair(node->right,hd+1));
    }
    
    map<int,vector<int>> :: iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        vector<int> temp;
        for(int i=0;i<it->second.size();++i)
            temp.push_back(it->second[i]);
        sort(temp.begin(),temp.end());
        result.push_back(temp);
    }
    return result;
}
