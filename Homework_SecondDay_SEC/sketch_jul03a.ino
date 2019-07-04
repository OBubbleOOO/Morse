void setup()
{
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}
char input;
void loop()
{
  if(Serial.available()>0)
  {
      input = Serial.read() - '0';
      show(input);
  }
}
void show(byte num)
{
  digitalWrite(12,LOW);
  if(num&0x01)
    digitalWrite(7,HIGH);
  else
    digitalWrite(7,LOW);
  if(num&2)
    digitalWrite(2,HIGH);
  else
    digitalWrite(2,LOW);
  if(num&4)
    digitalWrite(8,HIGH);
  else
    digitalWrite(8,LOW);
  if(num&8)
    digitalWrite(4,HIGH);
  else
    digitalWrite(4,LOW);
  digitalWrite(12,HIGH);
}
