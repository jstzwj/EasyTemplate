#ifndef IF_H
#define IF_H
#include"bool.h"


template<typename condition,typename then_t,typename else_t>
class TypeIf
{
public:
};

template<typename then_t,typename else_t>
class TypeIf<True,then_t,else_t>
{
public:
    typedef then_t value;
};

template<typename then_t,typename else_t>
class TypeIf<False,then_t,else_t>
{
public:
    typedef else_t value;
};


template<bool condition,typename then_t,typename else_t>
class If
{
public:
};

template<typename then_t,typename else_t>
class If<true,then_t,else_t>
{
public:
    typedef then_t value;
};

template<typename then_t,typename else_t>
class If<false,then_t,else_t>
{
public:
    typedef else_t value;
};

#endif // IF_H
