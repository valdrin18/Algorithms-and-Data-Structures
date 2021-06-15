/* CH-231-A
  A1.3(Cpp)
 Valdrin Smakaj
Vsmakaj@jacobs-university.de
*/

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <iostream>
using namespace std;

//template and classes for node and list
//could also made node as a struct
template <class T>
class Node {
    public:
        T data;
        Node *n;
        Node *p;
        Node();
        Node(const T& el, Node *n = NULL, Node *p = NULL);
};

template <class T>
class doublel {
    public:
        Node <T> *head;
        Node <T> *tail;
        int items;
        doublel();
        doublel(Node <T> *, Node <T> *, int);
        ~doublel();

        // service methods
        void pushf(const T&);
        void pushb(const T&);
        T popf();
        T popb();
        T frontt() const;
        T backk() const;
        int elements() const;
        void printele() const;
};

//node implement
template <class T>
Node <T> :: Node() {
    n = p = NULL;
}
//parametric
template <class T>
Node <T> :: Node(const T& el, Node *next, Node *prev) {
    data = el;
    n = next;
    p = prev;
}

//double linked list create
template <class T>
doublel <T> :: doublel() {
    tail = head = NULL;
    items = 0;
}

// constructor
template <class T>
doublel <T> :: doublel(Node <T> *front, Node <T> *rear, int items) {
    head = front;
    tail = rear;
    this->items = items;
}

// destructor
template <class T>
doublel <T> :: ~doublel() {
    Node <T> *navigator;
    while (head != NULL) {
        navigator = head->n;
        delete head;
        head = navigator;
    }
}

//front section

// push the number to the front
template <class T>
void doublel <T> :: pushf(const T& val) {
    if (items != 0) {
        head = new Node <T> (val, head, NULL);
        head->n->p = head;
    }
    else {
        head = tail = new Node <T> (val);
    }
    items++;
}


//front number pop and return
template <class T>
T doublel <T> :: popf() {
    if (items == 1) {
        T num;
        num = head->data;

        delete head;
        head = tail = NULL;
        items--;

        return num;
    }
    else if (items != 0) {
        T num;
        num = head->data;

        Node <T> *navigator;
        navigator = head->n;
        delete head;
        head = navigator;
        items--;

        return num;
    }
    else {
        cerr << "error, no elements" << endl;
        return -1;
    }
}

//the back section

// push the number to the back
template <class T>
void doublel <T> :: pushb(const T& val) {
    if (items != 0) {
        tail = new Node <T> (val, NULL, tail);
        tail->p->n = tail;
    }
    else {
        head = tail = new Node <T> (val);
    }
    items++;
}


//pop number at back
template <class T>
T doublel <T> :: popb() {
    if (items == 1) {
        T num;
        num = tail->data;

        delete tail;
        head = tail = NULL;
        items--;

        return num;
    }
    else if (items != 0) {
        T num;
        num = tail->data;

        tail = tail->p;
        delete tail->n;
        tail->n = NULL;
        items--;

        return num;
    }
    else {
        cerr << "error, no elements" << endl;
        return -1;
    }
}


//print
template <class T>
void doublel <T> :: printele() const {
    Node <T> *navigator;
    cout << "All elements: ";
    for (navigator = head; navigator; navigator = navigator->n) {
        cout << navigator->data << " ";
    }
    cout << endl;
}


//front and back element getters
template <class T>
T doublel <T> :: backk() const {
    return tail->data;
}
template <class T>
T doublel <T> :: frontt() const {
    return head->data;
}


//number of elements function
template <class T>
int doublel <T> :: elements() const {
    return items;
}

#endif
