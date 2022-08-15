#include "Schmitt.h"

template <typename T>
bool Schmitt<T>::filter(T val)
{
    if(val >= topLevel)
        lastState = true;
    else if(val < bottomLevel)
        lastState = false;

    return lastState ^ inverted;
}

template class Schmitt<float>;
template class Schmitt<double>;
template class Schmitt<int>;