#ifndef MAP_H
#define MAP_H

#include"num.h"
template<template<typename a> class m,template<typename b> class n>
class Map
{
public:
    template<class T> using value= typename m<typename n<T>::value >::value;
    //typedef m<n<n_left...>::value>::value value;
};

#endif // MAP_H
