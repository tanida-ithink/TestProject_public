#ifndef AIR_CONDITIONER_CONTROLLER_H_
#define AIR_CONDITIONER_CONTROLLER_H_

#include "TemperatureSensor.h"

// モード：オフ
const int MODE_OFF = 0;
// モード：冷房
const int MODE_COOLING = 1;
// モード：暖房
const int MODE_HEATTING = 2;

/**
 * AirConditionerController
 * エアコンコントローラ
 */
class AirConditionerController {
    private:
        // 温度センサ・インターフェイスのポインタ
        TemperatureSensor *pTemperatureSensor_ = nullptr;
        // 冷房をつける基準値(単位：℃)
        const int COOLING_THRESHOLD = 30;
        // 暖房をつける基準値(単位：℃)
        const int HEATING_THRESHOLD = 20;
        // エアコンのモード (オフ・冷房・暖房)
        int Mode;

    public:
        AirConditionerController(TemperatureSensor* pTemperatureSensor)
        {
          pTemperatureSensor_ = pTemperatureSensor;
        }
        virtual ~AirConditionerController() {}

        // 初期化処理
        void Init();

        // 自動運転判定
        void AutoMode();

        // モード取得
        int GetMode();
};

#endif // AIR_CONDITIONER_CONTROLLER_H_