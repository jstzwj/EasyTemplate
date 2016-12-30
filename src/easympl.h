#ifndef EASYMPL_H
#define EASYMPL_H
#include"num.h"
#include"bool.h"
#include"char.h"
#include"if.h"
#include"chararray.h"
#include"compose.h"
#include"list.h"

#define mpl_print(x) x()()


#define mpl_fun_begin(name) \
    class name\
    {\
    public:

#define mpl_fun_end };

#define mpl_fun_return(ret) typedef ret value;

#endif // EASYMPL_H
