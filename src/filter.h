#ifndef FILTER_H
#define FILTER_H

#include"if.h"
#include"list.h"
template<template<class a>class step,class lst>
class Filter
{
public:
    using value=
    typename TypeIf<
        typename step<typename lst::x>::value,
        list_item<typename lst::x,typename Filter<step,typename lst::xs>::value >,
        typename Filter<step,typename lst::xs>::value
    >::value;
};

template<template<class a>class step>
class Filter<step,list_end>
{
public:
    using value=list_end;
};

#endif // FILTER_H
