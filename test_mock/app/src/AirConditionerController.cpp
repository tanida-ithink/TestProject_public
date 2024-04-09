#include "AirConditionerController.h"

void AirConditionerController::Init() {
    Mode = MODE_OFF;
}

void AirConditionerController::AutoMode() {
    // 温度を取得
    int temperature = pTemperatureSensor_->GetTemperature();
    
    if (temperature >= COOLING_THRESHOLD)
    {
        // 冷房をオンにする
        Mode = MODE_COOLING;
    } else if (temperature <= HEATING_THRESHOLD)
    {
        // 暖房をオンにする 
        Mode = MODE_HEATTING;
    } else {
        // 停止する
        Mode = MODE_OFF;
    } 
    return;
}

int AirConditionerController::GetMode() {
    return Mode;
}