#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

Node* create(int x)
{
  Node* temp=new Node;
  temp->data=x;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

int find(Node* root,int t,int l)
{
    if(!root)
        return 0;
    if(root->data==t)
        return l;
    int x=find(root->left,t,l+1);
    if(x!=0)
        return x;
    x=find(root->right,t,l+1);
        return x;
}

int getLevel(struct Node *node, int target)
{
    if(!node)
        return 0;
    int l=1;
        return find(node,target,l);
}

int main(){
  Node* root=create(8);
  //left side
  root->left=create(3);
  root->left->left=create(1);
  root->left->right=create(6);
  root->left->right->left=create(4);
  root->left->right->right=create(7);
  //right side
  root->right=create(10);
  root->right->right=create(14);
  root->right->right->left=create(13);

    cout<<"14 is in "<<"level: ";
    cout<<getLevel(root,14);
    return 0;
}
