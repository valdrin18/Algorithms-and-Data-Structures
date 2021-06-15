#include "WindGauge.h"
#include <iostream>
#include <deque>
using namespace std;


WindGauge::WindGauge(int period){
    this->period=period;
}

void WindGauge::currentWindSpeed(int speed){
    int l=x.size();
    if(l>period){
        x.pop_front();
    }
    x.push_back(speed);
}

int WindGauge::highest()const{
    deque <int>::const_iterator i1=x.begin();
    int ele=*i1;
    while(i1!=x.end()){
        if(*i1>ele){
            ele=*i1;
        }
        i1++;
    }
    return ele;
}

int WindGauge::lowest()const{
    deque <int>::const_iterator i1=x.begin();
    int ele=*i1;
    while(i1!=x.end()){
        if(*i1<ele){
            ele=*i1;
        }
        i1++;
    }
    return ele;
}

int WindGauge::average()const{
    deque <int>::const_iterator i1=x.begin();
    int sum=0,l=x.size();
    while(i1!=x.end()){
        sum+=*i1;
        i1++;
    }
    return (sum/l);
}

void WindGauge::print(){
    cout<<"Highest: "<<highest()<<endl;
    cout<<"Lowest: "<<lowest()<<endl;
    cout<<"Average: "<<average()<<endl;
}


