#include "Oscillator.h"

template<typename T> 
void Oscillator<T>::write(T val)
{
    dataBuffer[pos++] = val;
    if(pos == bufSize)
        pos = 0;

    T max = dataBuffer[0];
    T min = dataBuffer[0];
    
    for(int i=1; i < bufSize; i++)
    {
        if(dataBuffer[i] > max)
            max = dataBuffer[i];
        if(dataBuffer[i] < min)
            min = dataBuffer[i];
    }
    value = (max - min);
}

template class Oscillator<float>;
template class Oscillator<double>;
template class Oscillator<int>;
template class Oscillator<signed char>;
template class Oscillator<unsigned char>;