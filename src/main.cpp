#include <iostream>
#include"easympl.h"
using namespace std;



int main(int argc, char *argv[])
{

    using lst=list<Num<1>>::push<Num<4>>::push<Num<5>>::push<Num<7>>;
    using lstbool=list<Bool<true>>::push<Bool<true>>::push<Bool<false>>::push<Bool<true>>;
    /*
    cout <<Map<Succ,lst>::value::x::value<< endl;
    cout <<Map<Succ,lst>::value::xs::x::value<< endl;
    cout <<Map<Succ,lst>::value::xs::xs::x::value<< endl;
    cout <<Map<Succ,lst>::value::xs::xs::xs::x::value<< endl;
    */



    cout<<list_size<Filter<isTrue,lstbool>::value>::value::value<<endl;
    cout<<Foldr<Mul,Num<1>,lst>::value::value<<endl;
    cout<<Map<Compose<Square,Succ>::value,lst>::value::x::value<<endl;
    cout<<Compose<Square,Succ>::value<Num<7>>::value::value<<endl;
    return 0;
}
