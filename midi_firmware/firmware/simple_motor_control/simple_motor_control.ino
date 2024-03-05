#define in1 9
#define in2 10
#define nsleep 11
#define vref 12

double cmd = 0.0;

void setup() {
pinMode(in1, OUTPUT);
pinMode(in2,OUTPUT);
pinMode(nsleep,OUTPUT);
pinMode(vref, OUTPUT);

digitalWrite(nsleep, HIGH);
analogWrite(vref, 10);
digitalWrite(in1,LOW);
Serial.begin(115200);

}

void loop() {
if(Serial.available())
{
  cmd = Serial.readString().toDouble();
}


analogWrite(in2,cmd*100);


}
