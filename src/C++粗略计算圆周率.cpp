#include <iostream>

using namespace std;

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

class PI
{
public:
    static constexpr double value=4*(PI_in<899>::value);
};




int main(int argc, char *argv[])
{
    cout << PI::value<< endl;
    return 0;
}
