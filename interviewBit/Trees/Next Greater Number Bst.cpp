/*
Given a BST node, return the node which has value just greater than the given node.

Example:

Given the tree

               100
              /   \
            98    102
           /  \
         96    99
          \
           97
           
Given 97, you should return the node corresponding to 98 as thats the value just greater than 97 in the tree.
If there are no successor in the tree ( the value is the largest in the tree, return NULL).

Using recursion is not allowed.

Assume that the value is always present in the tree.

https://www.interviewbit.com/problems/next-greater-number-bst/

Reference:

https://www.youtube.com/watch?v=5cPbNCrdotA
https://gist.github.com/mycodeschool/6515e1ec66482faf9d79

*/

TreeNode* Find(TreeNode* root, int data)
 {
     if(root==NULL) return NULL;
     else if(root->val == data)
        return root;
     else if(root->val < data) return Find(root->right, data);
     else return Find(root->left, data);
 };
 
 TreeNode* FindMin(TreeNode* root)
 {
     if(root == NULL) return NULL;
     while(root->left!=NULL)
        root=root->left;
    return root;
 };
 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    struct TreeNode* current = Find(A,B);
    if(current==NULL) return NULL;
    if(current->right!=NULL)
        return FindMin(current->right);
    else
    {
        struct TreeNode* successor = NULL;
        struct TreeNode* ancestor = A;
        while(ancestor!=current)
        {
            if(current->val < ancestor->val)
                {
                    successor = ancestor;
                    ancestor = ancestor->left;
                }
            else ancestor = ancestor->right;
        }
        return successor;
    }
}
