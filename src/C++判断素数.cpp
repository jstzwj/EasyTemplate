#include <iostream>
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

int main(int argc, char *argv[])
{
    cout << isPrime<7>::value<< endl;
    return 0;
}
