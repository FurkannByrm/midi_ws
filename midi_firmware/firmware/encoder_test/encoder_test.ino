//Texas Instruments DRV8701 motor driver H-Bridge Connection PINs
#define in1 9  // dir
#define in2 10  // pwm
#define nsleep 12  //
#define vref 13  // 

#define right_encoder_phaseA 3  // Interrupt 
#define right_encoder_phaseB 5  

unsigned int right_encoder_counter = 0;
String right_encoder_sign = "p";
double right_wheel_meas_vel = 0.0;    // rad/s

void setup() {
  // Set pin modes
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(nsleep, OUTPUT);
  pinMode(vref, OUTPUT);

  
  // Set Motor Rotation Direction
  digitalWrite(nsleep, HIGH);
  digitalWrite(in1, LOW);
  analogWrite(vref, 100);

  Serial.begin(115200);

  pinMode(right_encoder_phaseB, INPUT);
  attachInterrupt(digitalPinToInterrupt(right_encoder_phaseA), rightEncoderCallback, RISING);
}

void loop() {
  right_wheel_meas_vel = 10.0 * (double)right_encoder_counter * (60.0/200704.0) * 0.10472; //rad/sn 
  String encoder_read = "r" + right_encoder_sign + String(right_wheel_meas_vel);
  Serial.println(encoder_read);
  //right_encoder_counter = 0;
  analogWrite(in2, 0);
  delay(100);
}

void rightEncoderCallback()
{
  if(digitalRead(right_encoder_phaseB) == HIGH)
  {
    right_encoder_sign = "p";
  }
  else
  {
    right_encoder_sign = "n";
  }
  right_encoder_counter++;
}