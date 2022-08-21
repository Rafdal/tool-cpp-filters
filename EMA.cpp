#include "EMA.h"

template<typename T> 
void EMA<T>::write(T newval)
{
    value = value + alpha * (newval - value);
}

template <typename T>
T EMA<T>::read()
{
    return value;
}

template class EMA<float>;
template class EMA<double>;
