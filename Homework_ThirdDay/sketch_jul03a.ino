#define _dottime 250
#define _pin 13
void setup()
{
  pinMode(_pin,OUTPUT);
  Serial.begin(9600);
}
char input;
void loop()
{
  if(Serial.available()>0)
  {
      printChar(Serial.read());
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


void dot()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}
void dash()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime*4);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}
void c_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*2);
}
void w_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*6);
}

char LUT[26][5]={
  "*_",
  "_***",
  "_*_*",
  "_**",
  "*",
  "**_*",
  "__*",
  "****",
  "**",
  "*___",
  "_*_",
  "*_**",
  "__",
  "_*",
  "___",
  "*__*",
  "__*_",
  "*_*",
  "***",
  "_",
  "**_",
  "***_",
  "*__",
  "_**_",
  "_*__",
  "__**"
};
//根据字母在字母表中的位置控制灯输出相应Morse码
void printLetter(int index)
{
  char* p = (*LUT)+index;
  while(p++)
  {
    if(*p == '*')
      dot();
    else
      dash();
  }
  c_space();
}
//根据输入的字符(字母，空格或回车)控制灯输出相应Morse码
void printChar(char c)
{
  switch(c)
  {
    case ' ':
      w_space();
      break;
    case '\n':
      break;
    default:
      printLetter(c-97);
      break;
  }
}
