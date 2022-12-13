#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

Node* newNode(int item)
{
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(Node* root)
{
	if (root != NULL)
    {
		inorder(root->left);
		cout<<root->data<<endl;
		inorder(root->right);
	}
}


Node* insert(Node* node, int data)
{
	if (node == NULL)
		return newNode(data);

	if (data < node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	return node;
}


Node* deleteNode(Node* root, int k)
{

	if (root == NULL)
		return root;


	if (root->data > k)
    {
		root->left = deleteNode(root->left, k);
		return root;
	}
	else if (root->data < k)
	{
		root->right = deleteNode(root->right, k);
		return root;
	}


	if (root->left == NULL)
    {
		Node* temp = root->right;
		delete root;
		return temp;
	}
	else if (root->right == NULL)
	{
		Node* temp = root->left;
		delete root;
		return temp;
	}

	else
        {

            Node* successorParent = root;

            Node* successor = root->right;
            while (successor->left != NULL)
            {
                successorParent = successor;
                successor = successor->left;
            }


            if (successorParent != root)
                successorParent->left = successor->right;
            else
                successorParent->right = successor->right;

            root->data = successor->data;

            delete successor;
            return root;
        }
}

int main()
{

	Node* root = NULL;
	root = insert(root, 8);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 4);
	root = insert(root, 7);
    root = insert(root, 10);
	root = insert(root, 14);
	root = insert(root, 13);


	cout<<"Inorder traversal of the given tree"<<endl;
	inorder(root);

	cout<<"\n\nDelete 20\n\n";
	root = deleteNode(root, 10);
	cout<<"Inorder traversal of the modified tree"<<endl;
	inorder(root);

	return 0;
}
