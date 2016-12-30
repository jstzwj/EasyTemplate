#include <iostream>
#include"easympl.h"
using namespace std;


mpl_fun_begin(xxx)
mpl_fun_return(Num<1>)
mpl_fun_end

int main(int argc, char *argv[])
{
    cout <<xxx::value::value<< endl;
    //cout << Add<Num<1>,Num<2> >::result<< endl;
    return 0;
}
