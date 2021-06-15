#include <iostream>
#include "WindGauge.h"
using namespace std;

int main()
{
    WindGauge win;
    win.currentW1`indSpeed(15);
    win.currentWindSpeed(16);
    win.currentWindSpeed(12);
    win.currentWindSpeed(15);
    win.currentWindSpeed(15);

    win.print();

    win.currentWindSpeed(16);
    win.currentWindSpeed(17);
    win.currentWindSpeed(16);
    win.currentWindSpeed(16);
    win.currentWindSpeed(20);
    win.currentWindSpeed(17);
    win.currentWindSpeed(16);
    win.currentWindSpeed(15);
    win.currentWindSpeed(16);
    win.currentWindSpeed(20);

    win.print();
    return 0;
}
