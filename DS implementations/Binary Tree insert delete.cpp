#include<iostream>

class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
};

TreeNode* getNewNode(int data)
{
    TreeNode* temp = new TreeNode();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insertNode(TreeNode* root, int data)
{
    if(root==NULL)
        root = getNewNode(data);
        
    else if(root->data < data)
            root->right = insertNode(root->right,data);
    else root->left = insertNode(root->left,data);
    return root;
}

void printInorder(TreeNode* root)
{
    if(root==NULL)
        return;
    printInorder(root->left);
    std::cout<<root->data<<" ";
    printInorder(root->right);
}

bool SearchNode(TreeNode* root, int val)
{
    if(root==NULL)
        return false;
    if(root->data==val)
        return true;
    else if(root->data < val)
        return SearchNode(root->right,val);
    else return SearchNode(root->left,val);
}

TreeNode* FindMin(TreeNode* root, int val)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int val)
{
    if(root==NULL)
        return root;
    else if(root->data > val)
        root->left = deleteNode(root->left,val);
    else if(root->data < val)
        root->right = deleteNode(root->right,val);
    //next steps after value is found, need to check for leaf nodes/subtree before we can delete the node
    else
    {
        if(!root->left && !root->right) //when the value is found in a leaf node
        {
            delete root;
            root = NULL; //whichever root is calling this recursively will now point to NULL in place of this node
        }
        //when the node with value to be deleted has one child
        else if(!root->left)
        {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }

        else if(!root->right)
        {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }

        //if the node has left and right children
        else
        {
            TreeNode* temp = FindMin(root->right,val); //not directly root->data = minimum value because need to pass this node for deletion
            root->data = temp->data;
            root->right = deleteNode(root->right,val);
        }
    }
    return root;
}

int main()
{
    TreeNode *root = NULL;
    root = insertNode(root,1);
    root = insertNode(root,2);
    root = insertNode(root,4);
    root = insertNode(root,5);
    root = insertNode(root,7);
    root = insertNode(root,10);
    printInorder(root);
    if(SearchNode(root,1))
        std::cout<<"Element is present!";
    else std::cout<<"Not found";
    root = deleteNode(root,5);
    std::cout<<"\nafter deleting\n";
    printInorder(root);
    return 0;
}

/*
References:

https://gist.github.com/mycodeschool/44e1a9183ab0e931f729

https://www.youtube.com/watch?v=COZK7NATh4k

https://gist.github.com/mycodeschool/9465a188248b624afdbf

https://www.youtube.com/watch?v=gcULXE7ViZw
*/
