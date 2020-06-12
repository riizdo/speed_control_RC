/*  author: riizdo
 *  date: 10/06/2020
 *  description: speed control in boat RC
 */

//declaration of constants
#define PULSE_IN_PIN 2
#define PULSE_OUT_PIN 5
#define FORWARD_PIN 4
#define REWIND_PIN 3
#define MAX_VALUE 1970
#define MIN_VALUE 1190
#define SUP 15

//declaration of variables
unsigned long int value = 0;
int val = 0;

//initialization
void setup() {
  Serial.begin(9600);

  pinMode(PULSE_IN_PIN, INPUT);
  pinMode(FORWARD_PIN, OUTPUT);
  pinMode(REWIND_PIN, OUTPUT);
  pinMode(PULSE_OUT_PIN, OUTPUT);
}

//main
void loop() {
  value = pulseIn(PULSE_IN_PIN, HIGH);
  
  val = map(value, MIN_VALUE, MAX_VALUE, 255, -255);

  if (val < 0 && REWIND_PIN == LOW && FORWARD_PIN == LOW) {
    digitalWrite(REWIND_PIN, HIGH);
  } else if (val < 0 && REWIND_PIN == LOW && FORWARD_PIN == HIGH) {
    digitalWrite(FORWARD_PIN, LOW);
  } else if (val > SUP && FORWARD_PIN == LOW && REWIND_PIN == LOW) {
    digitalWrite(FORWARD_PIN, HIGH);
  } else if (val > SUP && FORWARD_PIN == LOW && REWIND_PIN == HIGH) {
    digitalWrite(REWIND_PIN, LOW);
  } else {
    
  }//close condition of direction motors
  
  analogWrite(PULSE_OUT_PIN, val * -1);
  
  Serial.print("El valor de la entrada: ");
  Serial.print(value);
  Serial.print(" // ");
  Serial.println(val);
}
