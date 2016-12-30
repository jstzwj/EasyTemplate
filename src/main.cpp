#include <iostream>
#include"easympl.h"
using namespace std;

template<int num,int n>
class isPrime_in
{
public:
    static const bool value=(isPrime_in<num,n-1>::value&&num%n!=0);
};
template<int num>
class isPrime_in<num,2>
{
public:
    static const bool value=(num%2!=0);
};

template<int num>
class isPrime
{
public:
    static const bool value=isPrime_in<num,num-1>::value;
};

template<int n>
class PI_in
{
public:
    static constexpr double value=(1.0/(2*n-1))-PI_in<n-1>::value;
};
template<>
class PI_in<1>
{
public:
    static constexpr double value=1.0;
};

template<int num>
class PI
{
public:
    static constexpr double value=4*(PI_in<num>::value);
};




int main(int argc, char *argv[])
{
    cout <<list<Num<0>>::push<Num<1>>::xs::x::value<< endl;
    //cout << Add<Num<1>,Num<2> >::result<< endl;
    return 0;
}
