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

template<typename lhs,typename rhs>
class Add
{
public:
    const static int result=lhs::value+rhs::value;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};


template<typename n,typename... left>
class ContinuationAdd
{
public:
    const static int result=n::value+Add<left...>::result;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n>
class ContinuationAdd<n>
{
public:
    const static int result=n::value;
    constexpr int operator ()()const{return result;}
};

template<typename lhs,typename rhs>
class Min
{
public:
    const static int result=lhs::value-rhs::value;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n,typename... left>
class ContinuationMin
{
public:
    const static int result=n::value-Min<left...>::result;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n>
class ContinuationMin<n>
{
public:
    const static int result=n::value;
    constexpr int operator ()()const{return result;}
};


template<typename lhs,typename rhs>
class Mul
{
public:
    const static int result=lhs::value*rhs::value;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n,typename... left>
class ContinuationMul
{
public:
    const static int result=n::value*Mul<left...>::result;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n>
class ContinuationMul<n>
{
public:
    const static int result=n::value;
    constexpr int operator ()()const{return result;}
};

template<typename lhs,typename rhs>
class Div
{
public:
    const static int result=lhs::value/rhs::value;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n,typename... left>
class ContinuationDiv
{
public:
    const static int result=n::value/Div<left...>::result;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n>
class ContinuationDiv<n>
{
public:
    const static int result=n::value;
    constexpr int operator ()()const{return result;}
};

template<typename n,typename m>
class Pow
{
public:
    const static int result=n::value*Pow<n,Num<m::value-1> >::value::value;
    using value=Num<result>;
};
template<typename n>
class Pow<n,Num<0> >
{
public:
    const static int result=n::value;
    using value=Num<result>;
};

template<typename n>
class Square
{
public:
    const static int result=n::value*n::value;
    using value=Num<result>;
};


template<typename n>
class Succ
{
public:
    const static int result=n::value+1;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n>
class Pred
{
public:
    const static int result=n::value-1;
    typedef Num<result> value;
    constexpr int operator ()()const{return result;}
};
#endif // NUM_H
