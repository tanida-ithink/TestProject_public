#include "gtest/gtest.h"

#include "MockTemperatureSensor.h"
#include "AirConditionerController.h"

namespace
{

    using ::testing::AtLeast;
    using ::testing::Return;
    using ::testing::Test;

    // フィクスチャークラスを作る
    class AirConditionerControllerTest : public Test {
    protected:
        MockTemperatureSensor mock;
        AirConditionerController airConditionerController = AirConditionerController(&mock);
        
        virtual void SetUp() {
            airConditionerController.Init();  
        }

        // virtual void TearDown() {}
    };

    TEST_F(AirConditionerControllerTest, OffModeTest) {
        EXPECT_CALL(mock, GetTemperature())
          .Times(AtLeast(2))
          .WillOnce(Return(29))    // 温度 29
          .WillOnce(Return(21));   // 温度 21

        airConditionerController.AutoMode();
        EXPECT_EQ(MODE_OFF, airConditionerController.GetMode());
        airConditionerController.AutoMode();
        EXPECT_EQ(MODE_OFF, airConditionerController.GetMode());
    }

    TEST_F(AirConditionerControllerTest, HeattingTest) {
        EXPECT_CALL(mock, GetTemperature())
          .Times(AtLeast(2))
          .WillOnce(Return(20))    // 温度 20
          .WillOnce(Return(19));   // 温度 19

        airConditionerController.AutoMode();
        EXPECT_EQ(MODE_HEATTING, airConditionerController.GetMode());
        airConditionerController.AutoMode();
        EXPECT_EQ(MODE_HEATTING, airConditionerController.GetMode());
    }

    TEST_F(AirConditionerControllerTest, CoolingTest) {
        EXPECT_CALL(mock, GetTemperature())
          .Times(AtLeast(2))
          .WillOnce(Return(30))    // 温度 30
          .WillOnce(Return(31));   // 温度 31

        airConditionerController.AutoMode();
        EXPECT_EQ(MODE_COOLING, airConditionerController.GetMode());
        airConditionerController.AutoMode();
        EXPECT_EQ(MODE_COOLING, airConditionerController.GetMode());
    }

    // int main(int argc, char **argv) {
    //     // テスト開始前に Google Mockを初期化する処理
    //     ::testing::InitGoogleMock(&argc, argv);
    //     return RUN_ALL_TESTS();
    // }

} // namespace