#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename templ>
void swap(templ &variable1, templ &variable2)
{
    templ a;
    a = variable1;
    variable1 = variable2;
    variable2 = a;
}

template <typename templ>
templ min(const templ &variable1, const templ &variable2)
{
    if (variable1 < variable2)
        return variable1;
    return variable2;
}

template <typename templ>
templ max(const templ &variable1, const templ &variable2)
{
    if (variable1 > variable2)
        return variable1;
    return variable2;
}

#endif