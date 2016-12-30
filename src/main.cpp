#include <iostream>
#include"easympl.h"
using namespace std;





int main(int argc, char *argv[])
{
    using lst=list<Num<1>>::push<Num<4>>::push<Num<5>>::push<Num<7>>;
    cout <<Map<Succ,lst>::value::x::value<< endl;
    cout <<Map<Succ,lst>::value::xs::x::value<< endl;
    cout <<Map<Succ,lst>::value::xs::xs::x::value<< endl;
    cout <<Map<Succ,lst>::value::xs::xs::xs::x::value<< endl;
    return 0;
}
