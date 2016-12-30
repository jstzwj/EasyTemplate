#ifndef LIST_H
#define LIST_H

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




#endif // LIST_H
