#ifndef MPL_MAP_H
#define MPL_MAP_H

#include"list.h"

template<template<typename a> class m,class lst>
class Map
{
public:
    using value=list_item<typename m<typename lst::x>::value,typename Map<m,typename lst::xs>::value >;
};

template<template<typename a> class m>
class Map<m,list_end>
{
public:
    using value=list_end;
};


/*
template<template<typename a> class m>
class Map<m,list>
{
public:
    using value=list_item<m<typename lst::x>,list_end>;
};
*/
#endif // MAP_H
