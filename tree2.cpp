#include <iostream>
using namespace std;

//store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

//a given node is present in a binary tree or not
bool isNodePresent(Node* root, Node* node)
{
    // base case
    if (root == nullptr)
    {
        return false;
    }

    // if the node is found, return true
    if (root == node)
    {
        return true;
    }

    // return true if a given node is found in the left or right subtree
    return isNodePresent(root->left, node) || isNodePresent(root->right, node);
}

// Function to find the lowest common ancestor of given nodes `x` and `y`, where
// both `x` and `y` are present in a binary tree.
// The function returns true if `x` or `y` is found in a subtree rooted at the root.
// `lca` ?> stores `LCA(x, y)`, and it is passed by reference to the function
bool findLCA(Node* root, Node* &lca, Node* x, Node* y)
{
    // base case 1: return false if the tree is empty
    if (root == nullptr)
    {
        return false;
    }

    // base case 2: return true if either `x` or `y` is found
    if (root == x || root == y)
    {
        // set lca to the current node
        lca = root;
        return true;
    }

    // recursively check if `x` or `y` exists in the left subtree
    bool left = findLCA(root->left, lca, x, y);

    // recursively check if `x` or `y` exists in the right subtree
    bool right = findLCA(root->right, lca, x, y);

    // if `x` is found in one subtree and `y` is found in the other subtree,
    // update lca to the current node
    if (left && right)
    {
        lca = root;
    }

    // return true if `x` or `y` is found in either left or right subtree
    return left || right;
}

// Function to find the lowest common ancestor of nodes `x` and `y`
void findLCA(Node* root, Node* x, Node* y)
{
    // `lca` stores the lowest common ancestor
    Node* lca = nullptr;

    // call LCA procedure only if both `x` and `y` are present in the tree
    if (isNodePresent(root, y) && isNodePresent(root, x))
    {
        findLCA(root, lca, x, y);
    }

    // if LCA exists, print it
    if (lca != nullptr)
    {
        cout << "PARENT is " << lca->data << endl;
    }
    else
    {
        cout << "PARENT does not exist\n";
    }
}

int main()
{

    Node* root = new Node(8);

    root->left = new Node(3);
    root->left->right = new Node(6);
    root->left->right->left=new Node(4);
    root->left->right->right=new Node(7);
    root->left->left = new Node(1);

    root->right=new Node(10);
    root->right->right=new Node(14);
    root->right->right->left=new Node(13);


    findLCA(root, root->left, root->left->right);
    findLCA(root, root->right, root->right->left);
    findLCA(root, root->right, root->right->right);

    return 0;
}
