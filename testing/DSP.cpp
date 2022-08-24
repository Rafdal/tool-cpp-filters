#include <Arduino.h>

#include <EMA.h>
#include <MovingSpread.h>
#include <TimedProcess.h>

EMA<uint8_t> ema(0.2f);
TimedProcessMicros samplingProcess;
MovingSpread<uint8_t> ms(0.7f, 2.8f);

uint8_t raw = 0; // sensor value

void setup()
{
    Serial.begin(2500000);


    samplingProcess.set(2000, [](){
        raw = (uint8_t)(analogRead(A0)/4);

        ema.write(raw); // EMA Filter with alpha = 0.5
        ms.write(ema.read());

        Serial.write(0xFF); // Sync byte
        Serial.write(raw);
        Serial.write(ema.read());
        Serial.write(ms.read());
    });
}

void loop()
{
    samplingProcess.run();
}
