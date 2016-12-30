#ifndef NUM_H
#define NUM_H
#include"bool.h"
#include"if.h"

#define mpl_num(x) Num<x>
#define mpl_add(x,y) Add<x,y>::value

template<int n>
class Num
{
public:
    typedef int type;
    typedef Num value_type;
    const static int value=n;
    constexpr int operator ()()const{return n;}
};

template<typename n,typename m>
class Eq
{
public:
    const static bool result=(n::value==m::value);
    typedef typename If<result,True,False>::value value;
    constexpr bool operator ()()const{return result;}
};

template<typename n,typename m>
class NotEq
{
public:
    const static bool result=(n::value!=m::value);
    typedef typename If<result,True,False>::value value;
    constexpr bool operator ()()const{return result;}
};

template<typename n,typename m>
class GT
{
public:
    const static bool result=(n::value>m::value);
    typedef typename If<result,True,False>::value value;
    constexpr bool operator ()()const{return result;}
};

template<typename n,typename m>
class LT
{
public:
    const static bool result=(n::value<m::value);
    typedef typename If<result,True,False>::value value;
    constexpr bool operator ()()const{return result;}
};

template<typename n,typename m>
class NGT
{
public:
    const static bool result=(n::value<=m::value);
    typedef typename If<result,True,False>::value value;
    constexpr bool operator ()()const{return result;}
};

template<typename n,typename m>
class NLT
{
public:
    const static bool result=(n::value>=m::value);
    typedef typename If<result,True,False>::value value;
    constexpr bool operator ()()const{return result;}
};


template<typename n,typename... left>
class Add
{
public:
    const static int result=n::value+Add<left...>::result;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n>
class Add<n>
{
public:
    const static int result=n::value;
    constexpr int operator ()()const{return result;}
};


template<typename n,typename... left>
class Min
{
public:
    const static int result=n::value-Min<left...>::result;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n>
class Min<n>
{
public:
    const static int result=n::value;
    constexpr int operator ()()const{return result;}
};

template<typename n,typename... left>
class Mul
{
public:
    const static int result=n::value*Mul<left...>::result;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n>
class Mul<n>
{
public:
    const static int result=n::value;
    constexpr int operator ()()const{return result;}
};

template<typename n,typename... left>
class Div
{
public:
    const static int result=n::value/Div<left...>::result;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n>
class Div<n>
{
public:
    const static int result=n::value;
    constexpr int operator ()()const{return result;}
};


template<typename n>
class Add1
{
public:
    const static int result=n::value+1;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};
#endif // NUM_H
