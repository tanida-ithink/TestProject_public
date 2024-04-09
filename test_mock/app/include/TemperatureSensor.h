#ifndef TEMPERATURE_SENSOR_H_
#define TEMPERATURE_SENSOR_H_

/**
 * TemperatureSensor
 * 温度センサ
 */
class TemperatureSensor {
    public:
        // virtual ~TemperatureSensor() = 0; 
        virtual int GetTemperature() = 0;
};

#endif // TEMPERATURE_SENSOR_H_