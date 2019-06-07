#include <iostream>
#include "matriz.h"
using namespace std;
int main() {

    matriz<int> b(3,3,2);
    b.change(0,0,10);

    matriz<int> c(3,3,1);
    c.change(0,0,20);

    auto a=c+b;

    c.verify(b);

    c.print();

    b.print();


    a.print();





    return 0;
}