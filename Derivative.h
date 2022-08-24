#ifndef Derivative_H
#define Derivative_H

// Discrete Derivative Filter

template <typename T>
class Derivative
{
public:
    Derivative(float gain = 1.0f)
    {
        lastValue = 0;
        g = (gain>0)? gain : 1.0f;
    }
    ~Derivative(){}

    inline T calc(T val)
    {
        T deriv = (((double)val - lastVal) * g);
        lastVal = (double)val;
        return deriv;
    }
    
private:
    double lastVal;
    float g;
};

#endif
