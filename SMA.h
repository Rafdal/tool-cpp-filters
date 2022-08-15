#ifndef SMA_H
#define SMA_H

// Simple Moving Average (SMA) Filter implemented with a circular buffer

template <typename T>
class SMA
{
public:
    SMA(unsigned int windowSize)
    {
        bufSize = windowSize;
        dataBuffer = new T[windowSize];

        for(pos=0; pos < bufSize; pos++)
        {
            dataBuffer[pos] = 0;
        }
        pos = 0;
    }
    ~SMA()
    {
        delete[] dataBuffer;
    }

    void write(T val);
    T read();

private:
    T* dataBuffer;    
    int bufSize;
    int pos = 0;
};

#endif