#include <Wire.h>
const int led=13;

void setup() 
{
  Wire.begin(0x8);
  Wire.onReceive(receiveevent);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}
void receiveevent(int i)
{
  while(Wire.available())
  {
    char wireread=Wire.read();
    digitalWrite(led,wireread);
  }
}
void loop() 
{
  delay(100);
}
