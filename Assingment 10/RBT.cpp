#include<iostream>
using namespace std;

enum Color { RED, BLACK };
struct Node
{
    int data;
    Color color;
    Node *left, *right, *parent;
};

class RedBlackTree
{
    private:
        Node *root;
    protected:
        // Rotation functions
        void rotateLeft(Node *&p)
        {
            if(p->right == NULL)
                return;
            else
            {
                Node* y = p->right;
                if(y->left != NULL)
                {
                    p->right = y->left;
                    y->left->parent = p;
                }
                else
                    p->right = NULL;
                if(p->parent != NULL)
                    y->parent = p->parent;
                if(p->parent == NULL)
                    root = y;
                else
                {
                    if(p == p->parent->left)
                        p->parent->left = y;
                    else
                        p->parent->right = y;
                }
                y->left = p;
                p->parent = y;
             }
        }

        void rotateRight(Node *&p)
        {
            if(p->left == NULL)
                return;
            else
            {
                Node* y = p->left;
                if(y->right != NULL)
                {
                    p->left = y->right;
                    y->right->parent = p;
                }
                else
                    p->left = NULL;
                if(p->parent != NULL)
                    y->parent = p->parent;
                if(p->parent == NULL)
                    root = y;
                else
                {
                    if(p == p->parent->left)
                        p->parent->left = y;
                    else
                        p->parent->right = y;
                }
                y->right = p;
                p->parent = y;
            }
        }

    public:
        // Default constructor (tree initially empty)
        RedBlackTree()
        {
            root = NULL;
        }
        void insert(int);
        // Helping function for insert
        void insertFixUp(Node *&);
        void deleteNode(Node *&);
        // Helping function for delete
        void deleteFixUp(Node *&);
        Node * predecessor(Node *&);
        Node * successor(Node *&);
        Node * getMinimum();
        Node * getMaximum();
        Node * search(int);
};

// Insert functions (similar to the pseudocodes in the slides)
// with some minor changes
void RedBlackTree::insert(int newelem)
{
     Node *p, *q;
     // Create a node to store the element we want to insert
     Node *t;
     t = new Node;
     t->data = newelem;
     t->left = NULL;
     t->right = NULL;
     t->color = RED;

     p = root;
     q = NULL;

     if(root == NULL)
     {
         root = t;
         t->parent = NULL;
     }
     else
     {
         while(p != NULL)
         {
              q = p;
              if(p->data < t->data)
                  p = p->right;
              else
                  p = p->left;
         }
         t->parent = q;
         if(q->data < t->data)
              q->right = t;
         else
              q->left = t;
     }
     insertFixUp(t);
}

void RedBlackTree::insertFixUp(Node *&t)
{
     Node *u;
     if(root == t)
     {
         t->color = BLACK;
         return;
     }
     while(t->parent != NULL && t->parent->color == RED)
     {
        Node *g = t->parent->parent;
        if(g->left == t->parent){
            if(g->right != NULL){
                  u = g->right;
                  if(u->color == RED){
                       t->parent->color = BLACK;
                       u->color = BLACK;
                       g->color = RED;
                       t = g;
                  }
            } else {
                if(t->parent->right == t){
                     t = t->parent;
                     rotateLeft(t);
                }
                t->parent->color = BLACK;
                g->color = RED;
                rotateRight(g);
            }
        } else {
            if(g->left != NULL){
                 u = g->left;
                 if(u->color == RED){
                      t->parent->color = BLACK;
                      u->color = BLACK;
                      g->color = RED;
                      t = g;
                 }
            } else {
                if(t->parent->left == t)
                {
                       t = t->parent;
                       rotateRight(t);
                }
                t->parent->color = BLACK;
                g->color = RED;
                rotateLeft(g);
            }
        }
        root->color = BLACK;
     }
}

// Delete functions
void RedBlackTree::deleteNode(Node *& x)
{
     if(root == NULL)
     {
        // Printing error messages when tree is empty
        cout << "Empty Tree!" << endl;
        return ;
     }
     Node* p;
     p = root;
     Node* y = NULL;
     Node* q = NULL;
     int found = 0;
     while(p != NULL && found == 0)
     {
            if(p->data == x->data)
                found = 1;
            if(found == 0){
                if(p->data < x->data)
                    p = p->right;
                else
                    p = p->left;
            }
     }
     if(found == 0){
            // Error message when element is not found
            cout << "Element Not Found!" << endl;
            return ;
     } else {
        if(p->left == NULL || p->right == NULL)
              y = p;
         else
              y = successor(p);
         if(y->left != NULL)
              q = y->left;
         else
         {
              if(y->right != NULL)
                   q = y->right;
              else
                   q = NULL;
         }
         if(q != NULL)
              q->parent = y->parent;
         if(y->parent == NULL)
              root = q;
         else
         {
             if(y == y->parent->left)
                y->parent->left = q;
             else
                y->parent->right = q;
         }
         if(y != p)
         {
             p->color = y->color;
             p->data = y->data;
         }
         if(y->color == BLACK)
             deleteFixUp(q);
     }
}

void RedBlackTree::deleteFixUp(Node *&p)
{
    Node *s;
    while(p != root && p->color == BLACK)
    {
          if(p->parent->left == p)
          {
              s = p->parent->right;
              if(s->color == RED)
              {
                     s->color = BLACK;
                     p->parent->color = RED;
                     rotateLeft(p->parent);
                     s = p->parent->right;
              }
              if(s->right->color == BLACK && s->left->color == BLACK)
              {
                     s->color = RED;
                     p = p->parent;
              }
              else
              {
                  if(s->right->color == BLACK)
                  {
                     s->left->color == BLACK;
                     s->color = RED;
                     rotateRight(s);
                     s = p->parent->right;
                  }
                  s->color = p->parent->color;
                  p->parent->color = BLACK;
                  s->right->color = BLACK;
                  rotateLeft(p->parent);
                  p = root;
              }
          }
          else
          {
              s = p->parent->left;
              if(s->color == RED)
              {
                s->color = BLACK;
                p->parent->color = RED;
                rotateRight(p->parent);
                s=p->parent->left;
              }
              if(s->left->color == BLACK && s->right->color == BLACK)
              {
                    s->color = RED;
                    p = p->parent;
              }
              else
              {
                    if(s->left->color == BLACK)
                    {
                          s->right->color = BLACK;
                          s->color = RED;
                          rotateLeft(s);
                          s = p->parent->left;
                    }
                    s->color = p->parent->color;
                    p->parent->color = BLACK;
                    s->left->color = BLACK;
                    rotateRight(p->parent);
                    p = root;
              }
          }
          p->color = BLACK;
          root->color = BLACK;
    }
}

Node* RedBlackTree::search(int x)
{
     if(root == NULL)
     {
           cout << "Empty Tree!" << endl;
           return  0;
     }
     Node* p = root;
     int found = 0;
     while(p != NULL && found == 0)
     {
            if(p->data == x) {
                found = 1;
            }
            if(found == 0)
            {
                 if(p->data < x)
                    p = p->right;
                 else
                    p = p->left;
            }
     }
     if(found == 0){
          cout << "Element Not Found!" << endl;
          return 0;
     }
     else
     {
        return p;
     }
}

Node * RedBlackTree::predecessor(Node *& x)
{
	Node* y = new Node;
	if(x->left) {
        while(x->left->right)
            x->left = x->left->right;
		return x->left;
	}
	y = x->parent;
	while(y != NULL && x == y->left)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

Node * RedBlackTree::successor(Node *& x)
{
	Node* y = new Node;
	if(x->right){
        while(x->right->left)
            x->right = x->right->left;
        return x->right;
	}
	y = x->parent;
	while(y != NULL && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

Node * RedBlackTree::getMinimum()
{
	Node* x;
	x = new Node;
    x = root;
	while(x->left)
		x = x->left;
	return x;
}

Node * RedBlackTree::getMaximum()
{
	Node* x;
	x = new Node;
	x = root;
	while(x->right)
		x = x->right;
	return x;
}

void printnode(Node *n)
{
    cout << n->data << " - ";
	if(n->color == BLACK)
		cout << "BLACK" << endl;
	else
		cout << "RED" << endl;
}

int main()
{
    RedBlackTree tree;

    Node* elem;
	elem = new Node;
	elem->data = 1;
	cout << "Check if node is deleted: (case when tree is empty)" << endl;
	tree.deleteNode(elem);

	cout << "\nCheck if searched element is in the tree: (case when tree is empty)" << endl;
	tree.search(4);

	// The example below is the tree from the first exercise point a:
	cout << "\nInserting elements:" << endl;
	tree.insert(13);
	tree.insert(44);
	tree.insert(37);
	tree.insert(7);
	tree.insert(22);
	tree.insert(16);

	Node* max;
	max = tree.getMaximum();
	cout << "\nMaximum: ";
	printnode(max);

	Node* min;
	min = tree.getMinimum();
	cout << "Minimum: ";
	printnode(min);

	Node* succ;
    succ = tree.successor(min);
	cout << "Successor of minimum: ";
	printnode(succ);

	Node* dec;
    dec = tree.predecessor(max);
	cout << "Predecessor of maximum: ";
	printnode(dec);

	Node* n;
	n = tree.search(succ->data);
	cout << "Searched node: ";
	printnode(n);

	tree.deleteNode(n);
	cout << "We see if searched node is deleted" << endl;
	n = tree.successor(min);
	cout << "New successor of min: ";
	printnode(n);


	Node* del;
	del = new Node;
	del->data = 10;
	cout << "\nCheck if node is deleted: (case when node is not in the tree)" << endl;
	tree.deleteNode(del);


	cout << "\nCheck if searched element is in the tree: (case when it is not)" << endl;
	tree.search(5);

	cout << endl;

    return 0;
}