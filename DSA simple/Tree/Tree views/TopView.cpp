#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

struct Node
{
    int val;
    Node *left,*right;
};

Node *newNode(int n)
{
    Node *node = new Node();
    node->val = n;
    node->left = node->right = NULL;
    return node;
}

void topView(Node* root)
{
    if(root==NULL)
        return;
    
    queue<pair< int, Node* > > que;
    unordered_map<int,int>  m;

    int hd = 0;

    que.push(make_pair(hd,root));

    while(!que.empty())
    {
        pair<int,Node*> temp_pair = que.front();
        hd = temp_pair.first;
        Node* temp_node = temp_pair.second;
        que.pop();
        if(m.find(hd)==m.end())
        {
            m[hd] = temp_node->val;
            cout<<temp_node->val<<" ";
        }

        if(temp_node->left!=NULL)
            que.push(make_pair(hd-1,temp_node->left));

        if(temp_node->right!=NULL)
            que.push(make_pair(hd+1,temp_node->right));

    }
}

void printInorder(Node* root)
{
    if(root==NULL)
        return;

    printInorder(root->left);
    cout<<root->val<<" ";
    printInorder(root->right);
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    cout<<"Inorder: \n";
    printInorder(root);
    cout<<"\n Topview: \n";
    topView(root);
    return 0;
}
