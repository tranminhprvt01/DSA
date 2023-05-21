#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* parent;
        Node* left;
        Node* right;
        int color;
};

class Tree {
private:

    void rotateLeft(Node* node) {
        Node* rightChild = node->right;
        node->right = rightChild->left;

        if (rightChild->left != NULL)
            rightChild->left->parent = node;

        rightChild->parent = node->parent;

        if (node->parent == NULL)
            root = rightChild;
        else if (node == node->parent->left)
            node->parent->left = rightChild;
        else
            node->parent->right = rightChild;

        rightChild->left = node;
        node->parent = rightChild;
    }


    void rotateRight(Node* node) {
        Node* leftChild = node->left;
        node->left = leftChild->right;

        if (leftChild->right != NULL)
            leftChild->right->parent = node;

        leftChild->parent = node->parent;

        if (node->parent == NULL)
            root = leftChild;
        else if (node == node->parent->left)
            node->parent->left = leftChild;
        else
            node->parent->right = leftChild;

        leftChild->right = node;
        node->parent = leftChild;
    }

    
    void fixInsert(Node* node) {
        while (node != root && node->parent->color == 1) {
            if (node->parent == node->parent->parent->left) {
                Node* uncle = node->parent->parent->right;

                if (uncle != NULL && uncle->color == 1) {
                    node->parent->color = 0;
                    uncle->color = 0;
                    node->parent->parent->color = 1;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        rotateLeft(node);
                    }

                    node->parent->color = 0;
                    node->parent->parent->color = 1;
                    rotateRight(node->parent->parent);
                }
            } else {
                Node* uncle = node->parent->parent->left;

                if (uncle != NULL && uncle->color == 1) {
                    node->parent->color = 0;
                    uncle->color = 0;
                    node->parent->parent->color = 1;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        rotateRight(node);
                    }

                    node->parent->color = 0;
                    node->parent->parent->color = 1;
                    rotateLeft(node->parent->parent);
                }
            }
        }

        root->color = 0;
    }

    void insertNode(Node* newNode) {
        Node* current = root;
        Node* parent = NULL;

        while (current != NULL) {
            parent = current;

            if (newNode->data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        newNode->parent = parent;

        if (parent == NULL)
            root = newNode;
        else if (newNode->data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        fixInsert(newNode);
    }

public:
    Node* root;
    Tree() : root(NULL) {}

    Node* newNode(int data)
    {
        Node* node  = new Node();
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
        node->color = 1;
        return node;
    }

    void insert(int data) {
        Node* node = newNode(data);
        insertNode(node);
    }
};
size_t height(Node *node){
        if(node == NULL)
            return 0;
        else
            return std::max(height(node->right),height(node->left))+1;
}

const int MAXN = 1e6+1000;

int main()
{
    Tree mytree;
    FILE* current_file;
    char filename[0x40];
    unsigned int n;
    int *arr = new int[MAXN];
    for (int i=0;i<10;i++)
    {
        sprintf(filename, "testcase%d", i);
        current_file = fopen(filename, "r");
        fscanf(current_file,"%d",&n);
        for (unsigned int entry=0;entry<n;entry++)
        {
            fscanf(current_file,"%d",&arr[entry]);
            mytree.insert(arr[entry]);
        }

        printf("Testcase %d has %u entries with height of %zu.\n",
                        i,n,height(mytree.root)
        );
        

    }

    return 0;
}