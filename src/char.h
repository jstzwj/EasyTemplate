#ifndef CHAR_H
#define CHAR_H

template<char n>
class Char
{
public:
    typedef char type;
    typedef Char value_type;
    const static char value=n;
    constexpr char operator ()()const{return n;}
};




#endif // CHAR_H
