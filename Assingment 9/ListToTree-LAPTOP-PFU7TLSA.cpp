#include <iostream>
using namespace std;

// Doubly linked list implementation
class node
{
    public:
    int info;
    node* next;
    node* prev;
};

// Add an element in the front of the list
void push_front(node** my_list, int elem)
{
    node* newnode = new node();
    newnode->info = elem;
    newnode->prev = NULL;
    newnode->next = (*my_list);

    if((*my_list) != NULL)
        (*my_list)->prev = newnode ;
    (*my_list) = newnode;
}

// Count the nodes of the list
int count_nodes(node *my_list)
{
    int count = 0;
    node *temp = my_list;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// Convert list to BST recursive function
node* list_to_tree_recursion(node **my_list, int n)
{
    if (n <= 0){
        return NULL;
    }

    // Left subtree construction
    node *left = list_to_tree_recursion(my_list, n/2);

    // Make middle node the root of BST
    node *root = *my_list;

    root->prev = left;
    *my_list = (*my_list)->next;

    // Right subtree construction
    root->next = list_to_tree_recursion(my_list, n-n/2-1);

    return root;
}

// Final conversion
node* list_to_tree(node *my_list)
{
    int n = count_nodes(my_list);

    // Construct BST
    return list_to_tree_recursion(&my_list, n);
}

// Function to print list
void print_list(node *node)
{
    while (node != NULL)
    {
        cout << node->info << " -> ";
        node = node->next;
    }
    cout << "NULL\n";
}

// Print preorder traversal of BST
void print_tree(node* node)
{
    if (node == NULL)
        return;
    cout << node->info << " ";
    print_tree(node->prev);
    print_tree(node->next);
}

int main()
{
    node* my_list = NULL;
    int i = 7;
    // Create a sorted linked list:
    while(i >= 1)
    {
        push_front(&my_list, (2*i));
        i--;
    }

    cout << "Sorted linked list:" << endl;
    print_list(my_list);
    cout << endl;
    node *bst = list_to_tree(my_list);
    cout << "Binary tree (starting from the root -> left, ->right):" << endl;
    print_tree(bst);
    cout << endl;
    return 0;
}