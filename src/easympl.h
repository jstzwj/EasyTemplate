#ifndef EASYMPL_H
#define EASYMPL_H
#include"num.h"
#include"bool.h"
#include"char.h"
#include"if.h"
#include"chararray.h"
#include"map.h"
#include"list.h"

#define mpl_print(x) x()()
#define mpl_num(x) Num<x>
#define mpl_add(x,y) Add<x,y>::value
#define mpl_if(x,y,z) TypeIf<z,y,z>::value

#endif // EASYMPL_H
