#include "timeStamp.h"

timeStamp::timeStamp()
{
    this->a = 0;
    this->b = 0;
    this->c = 0;
}

timeStamp::timeStamp(int a, int b, int c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

bool timeStamp::operator == (timeStamp t)
{
    if ((a == t.a) && (b == t.b) && (c == t.c))
        return true;
    else
        return false;
}

bool timeStamp::operator != (timeStamp t)
{
    if ((a != t.a) && (b != t.b) && (c != t.c))
        return true;
    else
        return false;
}

bool timeStamp::operator < (timeStamp t)
{
    if ((c < t.c) || ((c == t.c) && (b < t.b)) || ((c == t.c) && (b == t.b) && (a < t.a)))
        return true;
    else
        return false;
}

bool timeStamp::operator > (timeStamp t)
{
    if ((c > t.c) || ((c == t.c) && (b > t.b)) || ((c == t.c) && (b == t.b) && (a > t.a)))
        return true;
    else
        return false;
}

ostream &operator << (ostream &os, timeStamp &t)
{
    os << t.a << ":" << t.b << ":" << t.c;
    return os;
}

istream  &operator >> (istream &is, timeStamp &t)
{
    is >> t.a >> t.b >> t.c;
    return is;
}
