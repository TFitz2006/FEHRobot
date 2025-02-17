#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHServo.h>
#include <FEHMotor.h>
#include <FEHLCD.h>


FEHMotor Motor_Right(FEHMotor::Motor2,9.0);
FEHMotor Motor_Left(FEHMotor::Motor0,9.0);


// Declarations for analog optosensors
AnalogInputPin right_opto(FEHIO::P0_7);
AnalogInputPin middle_opto(FEHIO::P1_3);
AnalogInputPin left_opto(FEHIO::P2_0);






int main(void){


    float timetracker = TimeNow();
    while (TimeNow() - timetracker < 15.0){

        if (middle_opto.Value() < 2.4 && middle_opto.Value() > 2.1 && left_opto.Value() < .6 && right_opto.Value() < 1.2){
            Motor_Right.SetPercent(25);
            Motor_Left.SetPercent(25);
        } 

        if (left_opto.Value() > 1.85 && middle_opto.Value() < 1.70 && right_opto.Value() < 1.0){
            Motor_Left.SetPercent(2);
            Motor_Right.SetPercent(15);
            Sleep(.50);
            Motor_Right.SetPercent(25);
            Motor_Left.SetPercent(25);

        }

         if (right_opto.Value() > 2.15 && middle_opto.Value() < 1.70 && left_opto.Value() < .60){
            Motor_Left.SetPercent(15);
            Motor_Right.SetPercent(2);
            Sleep(.50);
            Motor_Right.SetPercent(25);
            Motor_Left.SetPercent(25);

        }
        
    }
}
