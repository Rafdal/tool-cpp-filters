#ifndef Oscillator_H
#define Oscillator_H

// Oscillator Filter implemented with a circular buffer

template <typename T>
class Oscillator
{
public:
    Oscillator(unsigned int windowSize)
    {
        bufSize = windowSize;
        dataBuffer = new T[windowSize];

        for(pos=0; pos < bufSize; pos++)
        {
            dataBuffer[pos] = 0;
        }
        pos = 0;
    }
    ~Oscillator()
    {
        delete[] dataBuffer;
    }

    void write(T val);
    inline T read()
    {
        return value;
    }

private:
    T* dataBuffer;    
    T value;
    int bufSize;
    int pos = 0;
};

#endif