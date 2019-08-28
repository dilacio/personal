#include "AuxiliarDAL.h"
const char* AuxiliarDAL::toUpper(const char* str)
{
    for (char* cp = const_cast<char*>(str); char c = *cp; cp++)
    {
        if (c >= 'a' && c <= 'z')
            *cp = c - 'a' + 'A';
    }
    return str;
}

