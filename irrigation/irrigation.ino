/*
Dario Molina
Computer Science Major CSin3 Cohort 3.

Description:  This program is for the arduino and check to see when a plant needs water. 
It uses a moisture sensor and collects data.  The int MOISTURE_LEVEL is a number I used as a baseline, but i want to keep working on this project for at times it waters the plant too often.  
I chose this project because I live in California, and with the drought i wanted to create something were we could optimze the water consumption, and what better way than to use Computer Science.
*/

const int VAL_PROBE = 0; //Analog pin 0
const int MOISTURE_LEVEL = 400; // I chose this value as a baseline for the water sensor

void setup()// declaring what each pin will do
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(0, INPUT);
}

void LedState(int state)

{
  digitalWrite(13,state);// send data to the screen
}

void loop()
{
  int moisture = analogRead(VAL_PROBE);// retrieving data from moisture sensor
  
  Serial.print("Moisture = ");
  Serial.println(moisture);// write out to the screen moisture value
  
  if(moisture > MOISTURE_LEVEL)// conditional statement to check if plant needs water
  {
    //LedState(HIGH);// turn on led light
   // digitalWrite(13,HIGH);
    digitalWrite(7,LOW);// send current to pump to water the plant
  }
  else 
  {
    //LedState(LOW);
    //digitalWrite(13,LOW);
    digitalWrite(7,HIGH);
  }
  
  delay(500);
}
