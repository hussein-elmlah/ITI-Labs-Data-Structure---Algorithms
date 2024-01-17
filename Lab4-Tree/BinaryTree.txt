#include <iostream>

using namespace std;

// Node structure for the Binary Search Tree
struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int data;

    // Constructors
    TreeNode()
    {
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Search Tree class
class BinarySearchTree
{
public:
    TreeNode *root;

    // Constructor initializes an empty tree
    BinarySearchTree()
    {
        root = nullptr;
    }

    // Function to insert a value into the BST
    void insert(int value)
    {
        TreeNode *newNode = new TreeNode(value);

        // If the tree is empty, the new node becomes the root
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            TreeNode *currentNode = root;
            // Traverse the tree to find the correct position for the new node
            while (true)
            {
                if (currentNode->data > newNode->data)
                {
                    if (currentNode->left == nullptr)
                    {
                        currentNode->left = newNode;
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }
                }
                else
                {
                    if (currentNode->right == nullptr)
                    {
                        currentNode->right = newNode;
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
            }
        }
    }

    // Function to count the number of nodes in the tree
    int countNodes(TreeNode *node)
    {
        if (node != nullptr)
        {
            return 1 + countNodes(node->left) + countNodes(node->right);
        }
        else
        {
            return 0;
        }
    }

    // Function to print the tree in different traversal orders
    void printTree()
    {
        cout << "InOrder: ";
        inOrder(root);
        cout << endl;
        cout << "PreOrder: ";
        preOrder(root);
        cout << endl;
        cout << "PostOrder: ";
        postOrder(root);
        cout << endl;
    }

    // In-order traversal
    void inOrder(TreeNode *node)
    {
        if (node != nullptr)
        {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    // Pre-order traversal
    void preOrder(TreeNode *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // Post-order traversal
    void postOrder(TreeNode *node)
    {
        if (node != nullptr)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }

    // Function to delete a node with a given value from the tree
    void deleteValue(int value)
    {
        root = deleteRecursive(root, value);
    }

    // Recursive helper function for node deletion
    TreeNode *deleteRecursive(TreeNode *node, int value)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (node->data < value)
        {
            node->right = deleteRecursive(node->right, value);
            return node;
        }

        if (node->data > value)
        {
            node->left = deleteRecursive(node->left, value);
            return node;
        }

        if (node->left == nullptr)
        {
            TreeNode *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            TreeNode *temp = node->left;
            delete node;
            return temp;
        }
        else
        {
            TreeNode *parentOfValueNode = node;

            TreeNode *nodeToDelete = root->right;
            while (nodeToDelete->left != nullptr)
            {
                parentOfValueNode = nodeToDelete;
                nodeToDelete = nodeToDelete->left;
            }

            if (parentOfValueNode != node)
                parentOfValueNode->left = nodeToDelete->right;
            else
                parentOfValueNode->right = nodeToDelete->right;

            node->data = nodeToDelete->data;

            delete nodeToDelete;
            return node;
        }
    }
};

// Function to initialize and populate the tree
void initializeTree(BinarySearchTree &initialTree)
{
    // Insert values into the tree
    initialTree.insert(4);
    initialTree.insert(8);
    initialTree.insert(20);
    initialTree.insert(3);
    initialTree.insert(14);
    initialTree.insert(25);
    initialTree.insert(7);
    initialTree.insert(9);
    initialTree.insert(11);
    initialTree.insert(23);
    initialTree.insert(2);
}

// Function to print tree information
void printTreeInfo(BinarySearchTree &treeInfo)
{
    // Print the tree
    cout << "Tree Traversals:" << endl;
    treeInfo.printTree();

    // Display the number of nodes in the tree
    cout << "The Number of nodes in tree = " << treeInfo.countNodes(treeInfo.root) << endl;
}

int main()
{
    // Create a binary tree object
    BinarySearchTree myTree;

    // Initialize and populate the tree
    initializeTree(myTree);

    // Print initial tree information
    cout << "Before Deletion:" << endl;
    printTreeInfo(myTree);

    // Delete a node with the value 7
    int n = 7;

    myTree.deleteValue(n);
    cout << "Node value to delete is "<< n << endl;
    // Display a message indicating node deletion
    cout << "Node Deleted" << endl;

    // Print tree information after deletion
    cout << "After Deletion:" << endl;
    printTreeInfo(myTree);

    return 0;
}
