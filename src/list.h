#ifndef LIST_H
#define LIST_H

class list_end{};

template <typename T,typename ...left>
class list_item
{
public:
    typedef T value;
    typedef list_item value_type;
    typedef list_item<left...> next;
};
template <typename T>
class list_item<T>
{
    typedef T value;
    typedef list_item value_type;
    typedef list_end next;
};

class list
{
    typedef list_end first;
};
template<typename n,typename lst>
class list_push_front
{
public:
    typedef list_item<n,lst::first> value;
};



#endif // LIST_H
