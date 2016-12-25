#ifndef CHARARRAY_H
#define CHARARRAY_H

template<const char * head>
class CharArray
{
public:
    static constexpr char * c_str=head;
};


#endif // CHARARRAY_H
