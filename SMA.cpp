#include "SMA.h"

template<typename T> 
void SMA<T>::write(T val)
{
    dataBuffer[pos++] = val;
    if(pos == bufSize)
        pos = 0;
}

template <typename T>
T SMA<T>::read()
{
    T sum = 0;
    for(int i=0; i < bufSize; i++)
    {
        sum += dataBuffer[i];
    }
    return (sum / bufSize);
}

template class SMA<float>;
template class SMA<double>;
template class SMA<int>;