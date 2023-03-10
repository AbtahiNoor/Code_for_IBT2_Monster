#include <VNH3SP30.h>

VNH3SP30 Motor1;    // define control object for 1 motor

// motor pins
#define M1_PWM 3    // pwm pin motor (digital output)
#define M1_INA 4    // control pin INA (digital output)
#define M1_INB 5    // control pin INB (digital output)
#define M1_DIAG 6   // diagnose pins (combined DIAGA/ENA and DIAGB/ENB - digital input)
#define M1_CS A0    // current sense pin (analog input)

void setup() {
  Motor1.begin(M1_PWM, M1_INA, M1_INB, M1_DIAG, M1_CS);    // Motor 1 object connected through specified pins 
  Serial.begin(115200);   
}

void loop() {
  Serial.println("3/4 speed forward");
  Motor1.setSpeed(300); // motor 3/4-speed "forward"
  delay(2000); // wait for 2 seconds
  Serial.print("Current="); Serial.println(Motor1.motorCurrent());

  Serial.println("Motor stop (coast)");
  Motor1.setSpeed(0); // motor stop (coasting)
  delay(2000); // wait for 2 seconds
  Serial.print("Current at stop="); Serial.println(Motor1.motorCurrent());
 
  Serial.println("Half speed backward");
  Motor1.setSpeed(-200); // motor half-speed "backward"
  delay(2000); // wait for 2 seconds
 
  Serial.println("Motor stop (coast)");
  Motor1.setSpeed(0); // motor stop 
  delay(2000); // wait for 2 seconds

  Serial.println("Full speed backward");
  Motor1.setSpeed(-400); // motor full-speed "backward"
  delay(2000); // wait for 2 seconds
  Serial.print("Current="); Serial.println(Motor1.motorCurrent());

  Serial.println("Brake at 3/4 power");
  Motor1.brake(300); // motor brake at 3/4 power
  delay(10);
  Serial.print("Current during brake="); Serial.println(Motor1.motorCurrent());
  delay(4000); // wait for 4 seconds
  Serial.print("Current after brake="); Serial.println(Motor1.motorCurrent());
}
