#include "LinkedList.h"
#include <iostream>
using namespace std;

//main function instances testing
int main(){
    doublel <int> my_list;
    my_list.pushf(1);
    my_list.pushf(3);
    my_list.pushb(5);
    my_list.pushb(2);
    cout<<"Num of ele: "<<my_list.elements()<<endl;
    cout<<"Front and rear: "<<my_list.frontt()<<", "<<my_list.backk()<<endl;
    my_list.printele();
    cout<<"pop in front: "<<my_list.popf()<<endl;
    cout<<"Print the change";
    my_list.printele();
    cout<<"pop in back: "<<my_list.popb()<<endl;
    cout<<"print the change: ";
    my_list.printele();
    cout<<"after changes, number is: "<<my_list.elements()<<endl;
    return 0;
}
