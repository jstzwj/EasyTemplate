#ifndef FOLD_H
#define FOLD_H
#include"list.h"

template<template<class lhs,class rhs>class step,class acc,class lst>
class Foldl
{
public:
    using value=typename Foldl<step,typename step<acc,typename lst::x>::value,typename lst::xs>::value;
};
template<template<class lhs,class rhs>class step,class acc>
class Foldl<step,acc,list_end>
{
public:
    using value=acc;
};



template<template<class lhs,class rhs>class step,class acc,class lst>
class Foldr
{
public:
    using value=typename step<typename lst::x,typename Foldr<step,acc,typename lst::xs>::value>::value;
};
template<template<class lhs,class rhs>class step,class acc>
class Foldr<step,acc,list_end>
{
public:
    using value=acc;
};


#endif // FOLD_H
