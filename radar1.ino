#include <Servo.h>. 
const int trigPin = 10;
const int echoPin = 11;
long duracion;
int distancia;
Servo myServo; 
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(12); 
}
void loop() {
  // rota el servo de 0 a 180°
  for(int i=0;i<=180;i++){  
  myServo.write(i);
  delay(0);
  distancia = calcularDistancia();// hacemos una llamada a la funcion que mide la distancia 
  
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distancia); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // regresa de 180 a 0°
  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(0);
  distancia = calcularDistancia();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distancia);
  Serial.print(".");
  }
}
// Funcion que calcula la distancia del sensor 
int calcularDistancia(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duracion = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distancia= duracion*0.034/2;
  return distancia;
}
