/*
Name: Dario Molina
Date: 11/14/2017
Description: Pumps water to a plant every 24 hours for 2 seconds.
*/


const int VAL_PROBE = 0; //Analog pin 0
const int MOISTURE_LEVEL = 400; 


void setup()// declaring what each pin will do
{
  Serial.begin(9600);  
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(0, INPUT);

  //making sure no current is set to pump
  digitalWrite(7,HIGH);
}


void loop()
{
  //retrieve data from moisture sensor
  int moisture = analogRead(VAL_PROBE);

  //write moisture from plant to console
  Serial.print("Moisture = ");
  Serial.println(moisture);/
  
  if(moisture > MOISTURE_LEVEL)// conditional statement to check if plant needs water
  {

    //turn on the water pump
    digitalWrite(7,LOW);
    delay(2000);

    //water plant for 2 minutes then turn off pump
    digitalWrite(7,HIGH);

  }

  //delay for 24 hours
  delay(3600000 * 24);
}

