#ifndef BOOL_H
#define BOOL_H


template<bool b>
class Bool
{
public:
};

template<>
class Bool<true>
{
public:
    typedef bool value_type;
    //typedef True type;
    const static bool value=true;
    constexpr bool operator ()()const{return true;}
};

template<>
class Bool<false>
{
public:
    typedef bool value_type;
    //typedef False type;
    const static bool value=false;
    constexpr bool operator ()()const{return false;}
};

using True=Bool<true>;
using False=Bool<false>;


template<typename T>
class isTrue
{
public:
    static_assert(1,"isTrue did not get a bool param.");
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


template<typename T>
class isFalse
{
public:
    static_assert(1,"isFalse did not get a bool param.");
};



template<>
class isFalse<True>
{
public:
    typedef False value;
};

template<>
class isFalse<False>
{
public:
    typedef True value;
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
