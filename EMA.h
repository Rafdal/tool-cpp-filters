#ifndef EMA_H
#define EMA_H

// Exponential Moving Average (EMA) Filter
// https://en.wikipedia.org/wiki/Moving_average#Exponential_moving_average

template <typename T>
class EMA
{
public:
    EMA(T a) // alpha is a value between 0 and 1
    {
        if(a > 0 && a < 1)
        {
            alpha = a;
        }
        else
        {
            alpha = (T)0.3; // default value
        }
        value = (T)0;
    }
    ~EMA(){}

    void write(T val);
    T read();

private:
    T alpha;
    T value;
};

#endif
