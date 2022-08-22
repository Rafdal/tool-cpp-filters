#ifndef Dispersion_H
#define Dispersion_H

// Dispersion Filter implemented with a circular buffer

template <typename T>
class Dispersion
{
public:
    Dispersion(unsigned int windowSize)
    {
        bufSize = windowSize;
        dataBuffer = new T[windowSize];

        for(pos=0; pos < bufSize; pos++)
        {
            dataBuffer[pos] = 0;
        }
        pos = 0;
    }
    ~Dispersion()
    {
        delete[] dataBuffer;
    }

    void write(T val);
    void write(T val, T mean);
    inline T read()
    {
        return value;
    }

private:
    T* dataBuffer;   
    T value; 
    int bufSize;
    int pos = 0;

    T defaultMean();
};

#endif