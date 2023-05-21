#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        int height;
};

class Tree 
{
public:

    int height(Node* root)
    {
        if (root == NULL) return 0;
        return root->height;
    }

    Node* newNode(int data)
    {
        Node* node  = new Node();
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;

        return node;
    }

    Node* rightrotate(Node* y)
    {
        Node* x = y->left;
        Node* tmp = x->right;

        x->right = y;
        y->left = tmp;

        y->height = max(height(y->left), height(y->right)) + 1;

        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftrorate(Node* x)
    {
        Node* y = x->right;
        Node* tmp = y->left;

        y->left = x;
        x->right = tmp;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }


    int balance(Node* root)
    {
        if(root == NULL) return 0;
        return height(root->left) - height(root->right);
    }


    Node* insert(Node* node, int data)
    {
        if (node == NULL) return newNode(data);

        if (data < node->data) node->left = insert(node->left, data);
        else if (data > node->data) node->right = insert(node->right, data);
        else return node;

        node->height = max(height(node->left), height(node->right)) + 1;

        int bl = balance(node);

        if (bl > 1 && data < node->left->data) {return rightrotate(node);}

        if (bl < -1 && data > node->right->data) {return leftrorate(node);}

        if (bl > 1 && data < node->left->data)
        {
            node->left = leftrorate(node->left);
            return rightrotate(node);
        }

        if (bl < -1 && data < node->right->data)
        {
            node->right = rightrotate(node->right);
            return leftrorate(node);
        }

        return node;
    }


    void inOrder(Node *root) {


        stack<Node*> s;
        Node* cur = root;


        while (cur != NULL || !(s.empty()))
        {

            while (cur != NULL)
            {
                s.push(cur);
                cur = cur->left;
            }


            cur = s.top();
            s.pop();

            cout << cur->data << " ";

            cur = cur->right;
            
        }

    }

};



const int MAXN = 1e6+1000;

int main()
{
    /*
    Tree AVL;

    Node* root = NULL;

    int t;
    int data;

    cin >> t;
    while (t--)
    {
        cin >> data;
        root = AVL.insert(root, data);
    }

    root = AVL.insert(root, 45);

    AVL.inOrder(root);

    return 0;
    */

    Tree mytree;
    FILE* current_file;
    char filename[0x40];
    unsigned int n;
    int *arr = new int[MAXN];
    for (int i=0;i<10;i++)
    {
        Node* root = NULL;
        sprintf(filename, "testcase%d", i);
        current_file = fopen(filename, "r");
        fscanf(current_file,"%d",&n);
        for (unsigned int entry=0;entry<n;entry++)
        {
            fscanf(current_file,"%d",&arr[entry]);
            root = mytree.insert(root, arr[entry]);
            //puts("bruh");
        }

        printf("Testcase %d has %u entries with height of %zu.\n",
                        i, n, root->height
        );
        

    }

    return 0;

}