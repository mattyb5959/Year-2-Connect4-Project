#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 64
Adafruit_NeoPixel strip (LED_COUNT, LED_PIN, NEO_GRB+NEO_KHZ800);

int value;
int valu;
int val;
float voltage;
void setup() 
{
    Serial.begin(9600);
    SerialMatrix()l
    strip.begin();
    strip.show();
    
}


int Matrix [6][7] = { {0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0} };
int MatrixOut [8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0} };

int MatrixOutN [8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0} };

int Button;
boolean ButtonBlock;
int Column;
int Row = -1;
boolean PlayerColor;
boolean Reset = false;
int Win = 0;
int Tie = 0;
void loop()
{
  if (Tie%2==0)
    PlayerColor = true;
  else
    PlayerColor = false;
  ButtonBlock = false;
  a: 
  value = 0;
  valu = 0;
  val = 0;
  voltage = 0;
  value = analogRead(A0); 
  valu = analogRead(A1);
  val = analogRead(A2);
  if (value>800)
    voltage = value +5.0/1023;
  else if (valu>800)
    voltage = valu+5/1023;
  else if (val >800)
    voltage - val +5.0/1023;
  else
    goto a;
  if voltage > 4.9&&voltage<=5&&value > 800)
    Button = 1;
  else if (voltage > 4.7 && voltage <=4.9 &&value>800)
    Button = 2;  
  else if (voltage > 4.5 && voltage <=4.7 &&value>800)
    Button = 3; 
  else if (voltage > 4.9 && voltage <=5 &&value>800)
    Button = 4;  
  else if (voltage > 4.7 && voltage <=4.9 &&value>800)
    Button = 5;  
  else if (voltage > 4.5 && voltage <=4.97 &&value>800)
    Button = 6;  
  else if (voltage > 4.9 && voltage <=5 &&value>800)
    Button = 7;
  else if (voltage > 4.6 && voltage <=4.9 &&value>800)
  {
    Button = 0;
    Reset = true;
  }
  if (Button ==1&&!ButtonBlock)
  {
    Column =0;
    ButtonBlock = true;
  }
  else if (Button ==2&&!ButtonBlock)
  {
    Column = 1
    ButtonBlock = true;
  }
  else if (Button ==3&&!ButtonBlock)
  {
    Column = 2
    ButtonBlock = true;
  }

    else if (Button ==4&&!ButtonBlock)
  {
    Column = 3
    ButtonBlock = true;
  }

    else if (Button ==5&&!ButtonBlock)
  {
    Column = 4
    ButtonBlock = true;
  }

    else if (Button ==6&&!ButtonBlock)
  {
    Column = 5
    ButtonBlock = true;
  }
   else if (Button ==7&&!ButtonBlock)
  {
    Column = 6
    ButtonBlock = true;
  }
if (ButtonBlock)
  for int (i = 5; i>=0; i--)
    if Matrix [i][Column]==0)
    {
      if(PlayerColor)
      Matrix[i][Column]=1;
      else
      Matrix[i][Column]=2;
      Tie++;
      Row=i;
      SerialMatrix();
      OutputMatrix();
      break;
    }
WinCheck();
if (Win==1||Win==2)
{
  delay(600);
  for (int i=0; i<6; i++)
    for(int j=0; j<7; j++)
    Matrix [i][j]=win;
    SerialMatrix();
    OutputMatrix();
    delay(5000);
    Reset=true;
}
  if (Tie>41)
    Reset = true;
    if (Reset) 
    {
      for (int i=0;i<6;i++)
        for(int j=0; j<7;j++)
          Matrix[i][j]=0;
      PlayerColor = true;
      Win = 0;
      Tie = 0;
      Reset = false;
      SerialMatrix();
      OutputMatrix();
    }
    int c=0;
    while (c==0)
    {
      delay(2000);
      c=1;
    }
    c=0;
}
void WinCheck()
{
  int x;
  if (PlayerColor)
  x =1;
  else 
  x=2;
  if (true)
  {
    int c=0;
    for (int i = Column;i>=0;i--)
    {
      if (Matrix[Row][i]==x)
      c++;
      else
      break;
    }
    for (int i=Column+1; i<7;i++)
    {
      if (Matrix[Row][i]==x)
      c++;
      else
      break;
    
    }
    if (c>3)
    Win=x;
  }
  if(true)
  {
    int c=0;
    for (int i=Row;i<6; i++)
    {
      if
        (Matrix[i][Column]==x) c++;
        else 
          break;
    }
    for (int i = Row-1; i>=0;i--)
    {
      if (Matrix[i][Column]==x)
      c++
      else
      break;   
    }
    if (c>3)
      Win=x;
  }
  if(true)
  {
    int c=0;
    int i = Row;
    int j = Column;
    while (i>=0&&j>=0)
    {
      if (Matrix[i][j]==x)
      c++;
      else
        break;
      i--;
      j--;
    }
    i=Row+1;
    j=Column+1;
    while(i<6&&j<7)
    {
      if (Matrix[i][j]==x)
      c++;
      else
        break;
      i++;
      j++;   
    }
    if (c>3)
    Win=x;
  }
  if (true)
  {
    int c=0
    int i = Row
    int j=Column;
    while (i>=0&&j<7)
    {
      if (Matrix [i][j]==x
        c++;
      else
        break;
      i--;
      j++;  
    }
    i=Row+1;
    j = Column -1
    while (i<6&&j>=0)
    {
      if Matrix[i][j]==x)
        c++;
      else
        break;
      i++;
      j--;
    }
    if (c>3)
      Win=x;
  }
}
