/* CH08-320211
 (lanuage-Cpp)
 Valdrin Smakaj
Vsmakaj@jacobs-university.de
*/

#include <iostream>
using namespace std;

//class stack
template <typename T>
class Stack{
    private:
        struct StackNode {  // linked list
            T data;
            StackNode *next;
        };
        StackNode *top;     // top of stack
        int size;           // -1 if not set, value otherwise
        int current_size;   // unused if size = -1
    public:
        void push(T x);     // if size set, check for overflow
        T pop();            //return element if not in underflow
        bool isEmpty();     // true if empty, false otherwise
        bool isFull();      //true if full, false otherwise
        Stack(int new_size);
        Stack();            //constructor
        ~Stack();           //destructor
};

//class queue
template <typename T>
class Queue{
    private:
    Stack<T> s1,s2; //two stacks to monitor the behaviour
    public:
    //put these two only because they are its behaviour
    void Enqueue(T x);
    T Dequeue();
};

//func to add elements in queue
template <typename T>
void Queue<T>::Enqueue(T x){
    if (this->s1.isFull()){
        cout<<"First Stack Overflow"<<endl;
        cout<<"Using stack 2"<<endl;
        this->s2.push(x);
    }
    else if((this->s1.isFull()) && (this->s2.isFull())){
        cout<<"Queue is full"<<endl;
    }
    else{
    cout<<"Using stack 1"<<endl;
    this->s1.push(x);
    }
}

//func to delete elements in queue
template <typename T>
T Queue<T>::Dequeue(){
    if((this->s1.isEmpty()) && (this->s2.isEmpty())){
        cout<<"Queue is empty"<<endl;
        return {};
    }
    else{
        while(!this->s1.isEmpty()){
            T remove1 = this-> s1.pop();
            return remove1;
         }
         if(!this->s2.isEmpty()){
             while(!this->s2.isEmpty()){
                T remove2 = this->s2.pop();
                return remove2; 
            }
         }
    }
}

//function to add elements in stack
template <typename T>
void Stack<T>:: push(T x){
    if (this->current_size == this->size){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        this->current_size++;
        if(this->current_size == 0){
            StackNode *newele = new StackNode();
            newele->data = x;
            newele->next = NULL;
            this->top = newele;
            cout<<"Pushed "<<newele->data<<" in stack"<<endl;
        }
        else{
            StackNode *newele = new StackNode();
            newele->data = x;
            newele->next = top;
            this->top = newele;
            cout<<"Pushed "<<newele->data<<" in stack"<<endl;
        }
    }
} 

//func to remove elements from stack
template <typename T>
T Stack<T>::pop(){
    if(this->current_size == 0){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else{
        StackNode *ele = this->top;
        T data = this->top->data;
        this->top = this->top->next;
        this->current_size--;
        cout<<"Popped "<<data<<" from stack"<<endl;
        delete ele;
        return data;
    }
}

//functions to check if stack is full or mt
template <typename T>
bool Stack<T>::isEmpty(){
    if (current_size == 0){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
bool Stack<T>::isFull(){
    if (this->current_size == this->size){
        return true;
    }
    else{
        return false;
    }
}

//func to set size
template <typename T>
Stack<T>::Stack(int new_size){
    this->size = new_size;
    this->current_size = 0;
    this->top = NULL;
}

//constructor and destructor functions
template <typename T>
Stack<T>::Stack(){
    this->size = -1;
    this->current_size = 0;
    this->top = NULL;
}

template <typename T>
Stack<T>::~Stack(){
    cout<<"Destructor called"<<endl;
    while(!this->isEmpty()){
        StackNode *x = this->top;
        this->top = this->top->next;
        delete x;
    }
}

//main function
int main() {

    Stack<int> s(5);
    s.push(7);
    s.push(5);
    s.pop();
    s.pop();
    s.pop();

    cout<<endl<<endl;
    
    Queue <int> q;
    q.Enqueue(5);
    q.Enqueue(7);
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    return 0;
}