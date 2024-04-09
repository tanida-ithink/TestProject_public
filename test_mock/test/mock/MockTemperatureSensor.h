#ifndef MOCK_TEMPERATURE_SENSOR_H_
#define MOCK_TEMPERATURE_SENSOR_H_

#include "gmock/gmock.h"
#include "TemperatureSensor.h"

/**
 * TemperatureSensor
 * 温度センサのMock
 */
class MockTemperatureSensor : public TemperatureSensor {
    public:
        MOCK_METHOD(int, GetTemperature, ());
};

#endif // MOCK_TEMPERATURE_SENSOR_H_