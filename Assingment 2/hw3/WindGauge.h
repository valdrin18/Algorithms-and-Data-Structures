#include <iostream>
#ifndef _WINDGAUGE_H
#define _WINDGAUGE_H
#include <deque>

using namespace std;

class WindGauge {
    private:
        deque <int> x;
        int period;
    public:
        WindGauge(int period = 12);
        void currentWindSpeed(int);
        int highest() const;
        int lowest() const;
        int average() const;
        void print();
};
#endif // _WINDGAUGE_H
