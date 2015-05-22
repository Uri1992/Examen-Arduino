/*************************************************************************
**                                                                      **
**                 Descripció programa                                  **
**                                                                      **
*************************************************************************/

//******  Includes  ******************************************************


//******  Variables  *****************************************************

const int led[] = {13, 12, 11, 10, 9, 8 , 7, 6};
const int pot = A0;
int temps;
int tempsBlink;
int valorPot;
int triaProgPot;

//*******  Setup  ********************************************************
void setup()
{
  Serial.begin(9600);
  
  pinMode(pot, INPUT);
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
  pinMode(led[3], OUTPUT);
  pinMode(led[4], OUTPUT);
  pinMode(led[5], OUTPUT);
  pinMode(led[6], OUTPUT);
  pinMode(led[7], OUTPUT);
}

//******  Loop  **********************************************************
void loop ()
{
  triaProgPot = analogRead(pot);
  triaProgPot = map (triaProgPot, 0, 1030, 1, 5);
  
  Serial.print("Programa ");
  Serial.println(triaProgPot);
  
  switch (triaProgPot)
  {
    case 1:
    {
      valPot();
    }
    break;
    
    case 2:
    {
      totsLeds();
    }
    break;
    
    case 3:
    {
      blinkPot();
    }
    break;
    
    case 4:
    {
      cotxeF();
    }
    break;
    
    default:
    {
      Serial.println("ERROR ");
    break;
    }
  }
}

void valPot ()
{
  valorPot = analogRead(pot);
  Serial.println(valorPot);
  delay(100);
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], LOW);
  digitalWrite(led[2], LOW);
  digitalWrite(led[3], LOW);
  digitalWrite(led[4], LOW);
  digitalWrite(led[5], LOW);
  digitalWrite(led[6], LOW);
  digitalWrite(led[7], LOW);
}

void totsLeds ()
{
  digitalWrite(led[0], HIGH);
  digitalWrite(led[1], HIGH);
  digitalWrite(led[2], HIGH);
  digitalWrite(led[3], HIGH);
  digitalWrite(led[4], HIGH);
  digitalWrite(led[5], HIGH);
  digitalWrite(led[6], HIGH);
  digitalWrite(led[7], HIGH);
}

void blinkPot ()
{
  tempsBlink = analogRead(pot);
  tempsBlink = map (tempsBlink, 510, 768, 10, 500);
  
  for (int numLed = 0; numLed < 8; numLed++)
    {
      digitalWrite(led[numLed], HIGH);
    }
    
    delay(tempsBlink);
    
  for (int numLed = 8; numLed >= 0; numLed--)
    {
       digitalWrite(led[numLed], LOW);
    }
    
    delay(tempsBlink);
}

void cotxeF ()
{
  for (int numLed = 0; numLed < 9; numLed++)
    {
    temps = analogRead(pot);
    temps = map (temps, 768, 1023, 10, 500);
    
    digitalWrite(led[numLed], HIGH);
    digitalWrite(led[numLed-1], HIGH);
    digitalWrite(led[numLed-2], HIGH);
    delay(temps);
    digitalWrite(led[numLed], LOW);
    digitalWrite(led[numLed-1], LOW);
    digitalWrite(led[numLed-2], LOW);
    }
  
  for (int numLed = 9; numLed > 0; numLed--)
    {
    temps = analogRead(pot);
    temps = map (temps, 768, 1023, 10, 500);
    
    digitalWrite(led[numLed], HIGH);
    digitalWrite(led[numLed-1], HIGH);
    digitalWrite(led[numLed-2], HIGH);
    delay(temps);
    digitalWrite(led[numLed], LOW);
    digitalWrite(led[numLed-1], LOW);
    digitalWrite(led[numLed-2], LOW);
    }
}
  
  
