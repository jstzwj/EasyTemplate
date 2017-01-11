#ifndef CHARARRAY_H
#define CHARARRAY_H

#include"char.h"
#include"list.h"
template<const char * head, int cur,char curChar=head[cur]>
class CharArray
{
public:
    static constexpr const char * c_str=head;
    using value=list_item<Char<*head>,typename CharArray<head,cur+1>::value >;
};
template<const char * head, int cur>
class CharArray<head,cur,0>
{
public:
    static constexpr char * c_str=head;
    using value=list_end;
};

#endif // CHARARRAY_H
