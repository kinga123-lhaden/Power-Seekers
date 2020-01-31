/*
 * Project Name: Landslide Detection system with optical fibre
 * Author List: Kinga Lhaden Dakpa, Thubten Jamtsho            
 *Filename:     projectCode
 *Functions:    void setup(), void loop()
 *Global Variable: 
        int sensorPin = A1;
        int sensorValue=1023;
        int led = 13;        
 */


int sensorPin = A1; // declaring pin for the illuminance sensor
int sensorValue=1023; // variable to store the value coming from the sensor. It is read as 1023 in serial monitor for complete brightless and 0 for darkness

int led = 13; // declaring pin for the led. It is being used to signal landslide instead of the alarm for the prototype

/*
 * Function Name: setup()
 * Input: none
 * Output: none
 * Logic: It only sets the serial port for communicaion and declares the led as an output pin.
 * Example call: Automatically called by the system during initialization
 */

void setup() {

Serial.begin(9600); 
pinMode(led,OUTPUT); 
  
}


/*
 * Function Name: loop()
 * Input: none
 * Output: prints the values coming from the sensor on the screen
 * Logic: It keeps on reiterating to constantly read the sensorValue
 * Example call: Automatically called by the system after the setup() function
 */
 
void loop() {

sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the screen
delay(100); //a delay of 0.1 seconds in reading each sensorValue is declared 

if(sensorValue<=130){ /*a conditional statement for when the sensorValue is read to be less than 130. The values less than 300 means no or less light.
                          This will happen only when there is a break in the circuit which happens when the optical fibre is displaced from the sensor*/
  digitalWrite(led,HIGH); //The led will turn on if the condiation is true. This means there is an earthquake 
  delay(5000); //a delay of 5 seconds is declared. The alarm will remain on for 15 seconds  
  }
else{
  digitalWrite(led,LOW); //The alarm/led will turn off when the condition becomes false.
  } 
}


  
  
 
