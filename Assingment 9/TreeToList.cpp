#include <iostream>
using namespace std;

struct list
{
    int info;
    struct list* next;
};

// Add element to the end of the list
struct list* push_back(struct list* my_list, int value)
{
    struct list* cursor, *newel;
    cursor = my_list;
    newel = new struct list();
    if(newel == NULL)
    {
        return my_list;
    }
    newel->info = value;
    newel->next = NULL;
    if(my_list == NULL)
        return newel;
    while ( cursor -> next != NULL )
        cursor = cursor -> next ;
    cursor -> next = newel ;
    return my_list ;
}

void print_list(struct list *my_list)
{
    struct list * p ;
    for ( p = my_list ; p ; p = p -> next )
    {
        cout << p -> info << " -> " ;
    }
    cout << "NULL\n";
}

// Binary search tree
class BST {
private:
    typedef struct node {
        node *left;
        node *right;
        int data;
    } node;
public:
    node *root;

    // Constructor
    BST() { root = NULL; }

    // Creates a new node with the given int
    node* create_node(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    bool isEmpty() const { return root==NULL; }

    // Calculates the depth of a given node
    int node_depth(node *to, node *from)
    {
        if (to == from)
            return 0;
        else if (to->data < from->data)
            return node_depth(to, from->left) + 1;
        else
            return node_depth(to, from->right) + 1;
    }

    // Insert a node into the tree
    void insert(int elem)
    {
        node* newnode = create_node(elem);
        node* parent;
        parent = NULL;

        // First insertion will be the root:
        if(isEmpty())
            root = newnode;
        else {
            node* current;
            current = root;
            while(current)
            {
                parent = current;
                if (newnode->data > current->data)
                    current = current->right;
                else
                    current = current->left;
            }
            if ((newnode->data) < (parent->data))
                parent->left = newnode;
            else
                parent->right = newnode;
        }
        // The above function is the implementation of the
        // pseudocode given in the lecture notes
    }

    // This function prints the tree in the following form:
    // it prints the levels of each node (the depth) together
    // with the nodes and the stars that make more clear the
    // image of a tree
    void printTree(node *node)
    {
        if (node == NULL)
            return;
        printTree(node->left);
        cout << node_depth(node, root) << "-> ";
        for (int i=0; i<node_depth(node, root); i++)
            cout << "**";
        cout << node->data << endl;
        printTree(node->right);
    }

    // Convert BST to linked list
    struct list* to_list(node *node, struct list *my_list)
    {
        if (node == NULL)
            return my_list;
        my_list = to_list(node->left, my_list);
        my_list = push_back(my_list, node->data);
        my_list = to_list(node->right, my_list);
        return my_list;
    }
};

int main()
{
    BST tree;
    struct list *my_list = NULL;

    // Construct the BST
    tree.insert(5);
    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(3);
    tree.insert(9);
    tree.insert(8);

    cout << "Binary Search Tree:" << endl << endl;
    tree.printTree(tree.root);
    cout << endl;
    // Convert BST to linked list
    my_list=tree.to_list(tree.root, my_list);
    cout << "Sorted Linked List:" << endl << endl;
    print_list(my_list);

    return 0;
}