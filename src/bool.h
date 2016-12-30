#ifndef BOOL_H
#define BOOL_H



class True
{
public:
    typedef bool value_type;
    typedef True type;
    const static bool value=true;
    constexpr bool operator ()()const{return true;}
};
class False
{
public:
    typedef bool value_type;
    typedef False type;
    const static bool value=false;
    constexpr bool operator ()()const{return false;}
};



template<bool b>
class Bool
{
public:
};

template<>
class Bool<true>
{
public:
    typedef True value;
};

template<>
class Bool<false>
{
public:
    typedef False value;
};





template<typename T>
class isTrue
{
public:
    typedef True value;
};



template<>
class isTrue<True>
{
public:
    typedef True value;
};

template<>
class isTrue<False>
{
public:
    typedef False value;
};


template<typename n,typename... left>
class InterSection
{
public:
    const static int result=n::value&&InterSection<left...>::result;
    typedef Bool<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n>
class InterSection<n>
{
public:
    const static int result=n::value;
    constexpr int operator ()()const{return result;}
};


template<typename n,typename... left>
class Union
{
public:
    const static int result=n::value||Union<left...>::result;
    typedef Bool<result> value;
    constexpr int operator ()()const{return result;}
};

template<typename n>
class Union<n>
{
public:
    const static int result=n::value;
    constexpr int operator ()()const{return result;}
};


template<typename n>
class Not
{
public:
    static_assert(1,"Not operator gets the unexpected param;");
};

template<>
class Not<True>
{
public:
    using value=False;
};

template<>
class Not<False>
{
public:
    using value=True;
};
#endif // BOOL_H
