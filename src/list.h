#ifndef LIST_H
#define LIST_H

#include"num.h"

class list_end{};

template <typename T,typename left=list_end>
class list_item
{
public:
    using x=T;
    using xs=left;
    using value=list_item<T,left>;
    template<typename val>
    using push=list_item<val,value>;
};
template <typename T>
class list_item<T,list_end>
{
public:
    using x=T;
    using xs=list_end;
    using value=list_item<T>;
    template<typename val>
    using push=list_item<val,value>;
};
template<typename T>
using list=list_item<T,list_end>;

template<typename lst>
class list_size
{
public:
    using value=typename Succ<typename list_size<typename lst::xs>::value>::value;
};
template<>
class list_size<list_end>
{
public:
    using value=Num<0>;
};

#endif // LIST_H
