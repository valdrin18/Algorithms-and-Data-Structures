#include <iostream>
#include <iomanip>
using namespace std;

//class Node with its constructor
class Node {
    public:
    int key;
    int value;
    Node(int key, int value);
};

Node::Node(int key,int value){
    this->key = key;
    this->value = value;
}

//class HashTable with its properties and functions
class HashTable {
    private:
        Node **arr;
        int maxSize;
        int currentSize;
    public:
        HashTable();
        int hashCode(int key);
        void insertNode(int key, int value);
        int get(int key);
        bool isEmpty();
        void print();
};

//constructor
HashTable::HashTable(){
    this->maxSize = 11;
    this->currentSize = 0;
    this->arr = new Node*[this->maxSize];
    for(int i=0; i< this->maxSize; i++){
        arr[i] = NULL;
    }
}

//function to calculate the HashKey
int HashTable::hashCode(int key){
    return (key % this->maxSize);
}

//function to insert elements
void HashTable::insertNode(int key, int value){
    if(this->currentSize >= this->maxSize){
        cout<<"Hash table full"<<endl;
    }
    else{
        Node *x = new Node(key,value);
        int HashKey = this->hashCode(key);
        if(this->arr[HashKey] == NULL){
            cout<<"Inserted "<<HashKey<<endl;
            this->arr[HashKey] = x;
        }
        else{
            int i = 0;
            while((i <= this->maxSize) && arr[(HashKey + i) % this->maxSize] != NULL){
                i++;
            }
            cout<<"Inserted "<<(HashKey + i) % this->maxSize<<endl;
            this->arr[(HashKey + i) % this->maxSize] = x;
        }
        this->currentSize++;
    }
}

//function to find elements
int HashTable::get(int key){
    int HashKey = this->hashCode(key);
    if(this->arr[HashKey] == NULL){
        cout<<"Could not find element in key: "<<key<<endl;
        return {};
    }
    else{
        int i = 0;
        while((i<= this->maxSize) && (this->arr[(HashKey + i) % this->maxSize]->key != key)){
            i++;
        }
        if(this->arr[(HashKey + i) % this->maxSize]->key == key){
            cout<<"Element found with key: "<<key<<" in pos: "<<(HashKey  + i) % this->maxSize<<" with value: "<<(this->arr[(HashKey+i) % this->maxSize]->value)<<endl;;
            return this->arr[(HashKey+i) % this->maxSize]->value;
            
        }
        else{
            cout<<"Could not find element in key: "<<key<<endl;
            return {};
        }
    }
}

//function to check if empty
bool HashTable::isEmpty(){
    return !this->currentSize;
}

//function to print
void HashTable::print(){
    cout<<"Hash table with size: "<<this->maxSize<<endl;
    for (int i = 0; i < this->maxSize; ++i) {
		if (this->arr[i] != NULL){
			std::cout << "Position "<< i << ": ("<< this->arr[i]->key<< ", "<<this->arr[i]->value<<")"<<endl;
        }
	}
}

//main function
int main(){
    
	HashTable h;

	h.insertNode(0,47);
	h.insertNode(14,91);
	h.insertNode(15,92);
	h.insertNode(4,25);
	h.insertNode(28,19);
	h.insertNode(29,24);
	h.insertNode(24,11);
	h.insertNode(49,25);
    h.insertNode(2,12);
	h.insertNode(12,5);
    h.insertNode(1,9);

	cout<<endl;
	h.print();
	cout<<endl;

	h.get(4);
	h.get(29);
	h.get(49);
	h.get(24);
	h.get(33);

    //to show when hash table is full
    h.insertNode(13,21);

    return 0;
}

/*
    Explanation on my h' function

    I choose my h' function based on divison of key mod m
    choosing the m as followed by lectures, a unique one (prime)
    so I chose m as 11 which is not close to a power of 2 or 10.

*/