// code for the pins P5
#define SENSOR_PIN A0
const int LED_PIN = 11; 
const int Y_LED_PIN = 13; 
float lastTime = 0 ;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(Y_LED_PIN, OUTPUT);
  Serial.println("--- Infrared sensor ----");

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);

  //----------------------------------------------------------IR measurements
  double brightness = 0 ;


  while( millis() <= lastTime + 20 ) {} //wait for sensor's sampling time

  lastTime = millis();

  int ADC_value = analogRead(SENSOR_PIN);  

  //int real_distance = 4800/(analogRead(SENSOR_PIN)-20);

  int real_distance = 29.988 * pow(map(ADC, 0, 1023, 0, 5000)/1000.0, -1.173);


  if(real_distance>45) {

    brightness=255;
    analogWrite(LED_PIN, brightness);
    digitalWrite(Y_LED_PIN, HIGH);

  } 
  else if (real_distance<15) {
    brightness= 0 ;
    analogWrite(LED_PIN, brightness);
    digitalWrite(Y_LED_PIN, HIGH);
  }
  else if ( real_distance>=15 && real_distance<=45 ){
    brightness =  map(real_distance, 45, 15, 255, 0);;
    analogWrite(LED_PIN, brightness);
    digitalWrite(Y_LED_PIN, LOW);
  }

  Serial.print("Infrared sensor reading : ");
  Serial.print(real_distance);
  Serial.print(" cm  | Brightness : ");
  Serial.print(100-(100*brightness/255));
  Serial.print(" %  | ADC Value : ");
  Serial.println(ADC_value);


}