#include "pindef.h"

void loop() {
  updateThrottle();
  delay(50);
}

/*
 * Pre condition: 77 <= throttle <= 335
 * 
 * NOTE: Voltages do not seem to set correctly if there is no delay in the loop
 * Also: the throttle is +5V not +12V so it needs +5V power or outputs will probably 
 * be wrong
 */
int updateThrottle() {
  int throttle = analogRead(PIN_THROTTLE_CTRL);
  
  //dead zone: 77 to 100 (about 10% pushed down)
  if (throttle < 100) {
    analogWrite(PIN_MOTOR_L_THROTTLE, LOW);
    analogWrite(PIN_MOTOR_R_THROTTLE, LOW);
    return 0;
  }
  throttle -= 100;

  double maxDif = 335 - 100;
  int out = (int) ((throttle/maxDif) * 200);
  //6.59V max with 255
  //183 is max signal to give 5V exactly (in theory)
  //testing yields 5.075 V max using 200 as the digital max
  //low voltage is around 10 mV on avg
  
  analogWrite(PIN_MOTOR_L_THROTTLE, out);
  analogWrite(PIN_MOTOR_R_THROTTLE, out);
  
  return out;
}

void setup() {
    Serial.begin(115200);

    digitalWrite(PIN_BRAKE_CTRL, LOW);
    pinMode(PIN_BRAKE_CTRL, INPUT);
    digitalWrite(PIN_REGEN_CTRL, LOW);
    pinMode(PIN_REGEN_CTRL, INPUT);
    digitalWrite(PIN_GEARSHIFT_CTRL, LOW);
    pinMode(PIN_GEARSHIFT_CTRL, INPUT);
    digitalWrite(PIN_TURNSIG_CTRL, LOW);
    pinMode(PIN_TURNSIG_CTRL, INPUT);
    digitalWrite(PIN_THROTTLE_CTRL, LOW);
    pinMode(PIN_THROTTLE_CTRL, INPUT);
    digitalWrite(PIN_STEER_CTRL, LOW);
    pinMode(PIN_STEER_CTRL, INPUT);
    digitalWrite(PIN_HAZARD_CTRL, LOW);
    pinMode(PIN_HAZARD_CTRL, INPUT);
    //attachInterrupt(digitalPinToInterrupt(PIN_HAZARD_CTRL), toggle_hazard_state, RISING);
    digitalWrite(PIN_DOWN_CTRL, LOW);
    pinMode(PIN_DOWN_CTRL, INPUT);
    digitalWrite(PIN_UP_CTRL, LOW);
    pinMode(PIN_UP_CTRL, INPUT);
    digitalWrite(PIN_SEL_CTRL, LOW);
    pinMode(PIN_SEL_CTRL, INPUT);
    digitalWrite(PIN_KILL_SENSE, LOW);
    pinMode(PIN_KILL_SENSE, INPUT);
    digitalWrite(PIN_HAZARD_LED, LOW);
    pinMode(PIN_HAZARD_LED, INPUT);
    digitalWrite(PIN_UART_1_RX, LOW);
    pinMode(PIN_UART_1_RX, INPUT);
    digitalWrite(PIN_UART_1_TX, LOW);
    pinMode(PIN_UART_1_TX, INPUT);

    /******************************************/
    /* pin definitions for motor controllers  */
    /******************************************/
    digitalWrite(PIN_MOTOR_L_REGEN_EN, LOW);
    pinMode(PIN_MOTOR_L_REGEN_EN, OUTPUT);
    digitalWrite(PIN_MOTOR_L_REGEN, LOW);
    pinMode(PIN_MOTOR_L_REGEN, OUTPUT);
    digitalWrite(PIN_MOTOR_L_THROTTLE, LOW);
    pinMode(PIN_MOTOR_L_THROTTLE, OUTPUT);
    digitalWrite(PIN_MOTOR_L_ECO_EN, LOW);
    pinMode(PIN_MOTOR_L_ECO_EN, OUTPUT);
    digitalWrite(PIN_MOTOR_L_METER, LOW);
    pinMode(PIN_MOTOR_L_METER, OUTPUT);
    digitalWrite(PIN_MOTOR_L_FWD_EN, LOW);
    pinMode(PIN_MOTOR_L_FWD_EN, OUTPUT);
    digitalWrite(PIN_MOTOR_L_REV_EN, LOW);
    pinMode(PIN_MOTOR_L_REV_EN, OUTPUT);

    digitalWrite(PIN_MOTOR_R_REGEN_EN, LOW);
    pinMode(PIN_MOTOR_R_REGEN_EN, OUTPUT);
    digitalWrite(PIN_MOTOR_R_REGEN, LOW);
    pinMode(PIN_MOTOR_R_REGEN, OUTPUT);
    digitalWrite(PIN_MOTOR_R_THROTTLE, LOW);
    pinMode(PIN_MOTOR_R_THROTTLE, OUTPUT);
    digitalWrite(PIN_MOTOR_R_ECO_EN, LOW);
    pinMode(PIN_MOTOR_R_ECO_EN, OUTPUT);
    digitalWrite(PIN_MOTOR_R_METER, LOW);
    pinMode(PIN_MOTOR_R_METER, OUTPUT);
    digitalWrite(PIN_MOTOR_R_FWD_EN, LOW);
    pinMode(PIN_MOTOR_R_FWD_EN, OUTPUT);
    digitalWrite(PIN_MOTOR_R_REV_EN, LOW);
    pinMode(PIN_MOTOR_R_REV_EN, OUTPUT);

    /******************************************/
    /* pin definitions for high power devices */
    /******************************************/
    digitalWrite(PIN_HORN, LOW);
    pinMode(PIN_HORN, OUTPUT);
    digitalWrite(PIN_HEADLIGHTS, LOW);
    pinMode(PIN_HEADLIGHTS, OUTPUT);
    digitalWrite(PIN_BRAKELIGHTS, LOW);
    pinMode(PIN_BRAKELIGHTS, OUTPUT);
    digitalWrite(PIN_STROBE_CTRL, LOW);
    pinMode(PIN_STROBE_CTRL, OUTPUT);
    digitalWrite(PIN_RIGHT_BLINKERS, LOW);
    pinMode(PIN_RIGHT_BLINKERS, OUTPUT);
    digitalWrite(PIN_LEFT_BLINKERS, LOW);
    pinMode(PIN_LEFT_BLINKERS, OUTPUT);
    digitalWrite(PIN_HEADLIGHT_CTRL, LOW);
    pinMode(PIN_HEADLIGHT_CTRL, INPUT);
    digitalWrite(PIN_HORN_CTRL, LOW);
    pinMode(PIN_HORN_CTRL, INPUT);
    digitalWrite(PIN_BRAKE_CTRL, LOW);
    pinMode(PIN_BRAKE_CTRL, INPUT);

    // UI::init();
}
