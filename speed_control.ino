/*  author: riizdo
 *  date: 10/06/2020
 *  description: speed control in boat RC
 */

#define pulsePin 2
#define ledPin 13

unsigned long int value;
unsigned long int maxValue = 0;
unsigned long int minValue = 40000;
int val = 0;


void setup() {
  Serial.begin(9600);

  pinMode(pulsePin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  value = pulseIn(pulsePin, HIGH);



  if (value > maxValue) {
    maxValue = value;
  }
  if (value < minValue) {
    minValue = value;
  }
  
  val = map(value, minValue, maxValue, 255, 0);
  
  analogWrite(ledPin, val);
  
  Serial.print("El valor de la entrada: ");
  Serial.print(value);
  Serial.print(" // ");
  Serial.print(minValue);
  Serial.print(" // ");
  Serial.print(maxValue);
  Serial.print(" // ");
  Serial.println(val);
}
