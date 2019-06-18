//Reference: https://www.geeksforgeeks.org/iterative-boundary-traversal-of-complete-binary-tree/

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* node = new Node();
    node->val = data;
    node->left = node->right = NULL;
    return node;
}

void printBoundary(Node* root)
{
    if(root)
    {
        if(!root->left && !root->right)
        {
            cout<<root->val;
            return;
        }
        cout<<root->val;

        Node* L = root->left;
        while(!L->left)
        {
            cout<<L->val;
            L=L->left;
        }

        queue<Node*> que;
        que.push(root);
        while(!que.empty())
        {
            Node* temp = que.front();
            que.pop();

            if(!temp->left && !temp->right)
                cout<<temp->val;

            if(temp->left)
                que.push(temp->left);

            if(temp->right)
                que.push(temp->right);
        }

        stack<int> s;

        Node* R = root->right;
        while(!R->right)
        {
            s.push(R->val);
            R = R->right;
        }

        while(!s.empty())
        {
            cout<<s.top();
            s.pop();
        }
    }
}

int main()
{
    Node* root = newNode(20);
    root->left = newNode(8); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    root->right = newNode(22); 
    root->right->right = newNode(25); 

    printBoundary(root);
   
    return 0;
}
