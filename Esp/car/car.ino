#define ENA 5
#define ENB 12
#define IN_1 0
#define IN_2 4
#define IN_3 14
#define IN_4 2

#define TRIG 13
#define ECHO 15
#define SERVO 10
#define LIGHT 9
#define BAT_READ A0


#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
Servo s1;

String command;
int speedCar = 200;
int speed_Coeff = 3;
int move_delay = 100;
const char* ssid = "Ankita-Pawan";
const char* password = "arunbagwem074853";

ESP8266WebServer server(80);
long duration;
int distance;
unsigned long servoUpdateTime = 0;
const int servoUpdateInterval = 15;
int servoPosition = 0;
int servoIncrement = 1;

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, OUTPUT);
  s1.attach(SERVO);
  Serial.begin(9600);

  // Connecting WiFi

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Starting WEB-server
  server.on("/", HTTP_handleRoot);
  server.onNotFound(HTTP_handleRoot);
  server.begin();
}

int ultraSonic(){
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    duration = pulseIn(ECHO, HIGH);
    distance= duration*0.034/2;
    return distance;
}


void goAhead() {

  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCar);
}

void goBack() {

  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}

void goRight() {

  digitalWrite(IN1, HIGH);_
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCar);
}

void goLeft() {

  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}

void goAheadRight() {

  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCar / speed_Coeff);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCar);
}

void goAheadLeft() {

  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCar / speed_Coeff);
}

void goBackRight() {

  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar / speed_Coeff);

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}

void goBackLeft() {

  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar / speed_Coeff);
}

void stopRobot() {

  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}




void moveDir(int angle){
  if (angle == 20){
      analogWrite(IN_1, LOW);
      analogWrite(IN_2, 255);
      analogWrite(ENA, 255);
      analogWrite(IN_3, LOW);
      analogWrite(IN_4, 20);
      analogWrite(ENB, 255);
      delay(move_delay);
      stopRobot();

  }
  if (angle == 30){
      analogWrite(IN_1, LOW);
      analogWrite(IN_2, 255);
      analogWrite(ENA, 255);
      analogWrite(IN_3, LOW);
      analogWrite(IN_4, 66);
      analogWrite(ENB, 255);
      delay(move_delay);
      stopRobot();
  }
  if (angle == 40){
      analogWrite(IN_1, LOW);
      analogWrite(IN_2, 255);
      analogWrite(ENA, 255);
      analogWrite(IN_3, LOW);
      analogWrite(IN_4, 129);
      analogWrite(ENB, 255);
      delay(move_delay);
      stopRobot();
  }
  if (angle == 50){
      analogWrite(IN_1, LOW);
      analogWrite(IN_2, 255);
      analogWrite(ENA, 255);
      analogWrite(IN_3, LOW);
      analogWrite(IN_4, 192 );
      analogWrite(ENB, 255);
      delay(move_delay);
      stopRobot();
  }
  if (angle == 60){     
      analogWrite(IN_1, LOW);
      analogWrite(IN_2, 255);
      analogWrite(ENA, 255);
      analogWrite(IN_3, LOW);
      analogWrite(IN_4, 255);
      analogWrite(ENB, 255);
      delay(move_delay);
      stopRobot();
      }
  if (angle == 70){
      analogWrite(IN_1, LOW);
      analogWrite(IN_2, 192);
      analogWrite(ENA, 255);
      analogWrite(IN_3, LOW);
      analogWrite(IN_4, 255);
      analogWrite(ENB, 255);
      delay(move_delay);
      stopRobot();
  }
  if (angle == 80){
      analogWrite(IN_1, LOW);
      analogWrite(IN_2, 129);
      analogWrite(ENA, 255);
      analogWrite(IN_3, LOW);
      analogWrite(IN_4, 255);
      analogWrite(ENB, 255);
      delay(move_delay);
      stopRobot();
  }
  if (angle == 90){
      analogWrite(IN_1, LOW);
      analogWrite(IN_2, 66);
      analogWrite(ENA, 255);
      analogWrite(IN_3, LOW);
      analogWrite(IN_4, 255);
      analogWrite(ENB, 255);
      delay(move_delay);
      stopRobot();
  }
  if (angle == 100){
      analogWrite(IN_1, LOW);
      analogWrite(IN_2, 20);
      analogWrite(ENA, 255);
      analogWrite(IN_3, LOW);
      analogWrite(IN_4, 255);
      analogWrite(ENB, 255);
      delay(move_delay);
      stopRobot();
  }
}


void moveServo(){
    if (millis() - servoUpdateTime >= servoUpdateInterval) {
    s1.write(servoPosition);
    servoPosition += servoIncrement;
    if (servoPosition >= 180 || servoPosition <= 0) {
      servoIncrement = -servoIncrement;
    }
    servoUpdateTime = millis();
  }
}


void loop() {
  // int distance = ultraSonic();
  // if (distance<5){
  //   stopRobot();
  //   goBack();
  //   delay(1);
  //   stopRobot();

  // }
  server.handleClient();

  command = server.arg("State");
  if (command == "F") goAhead();
  else if (command == "20") moveDir(20); //far left
  else if (command == "30") moveDir(30);
  else if (command == "40") moveDir(40);
  else if (command == "50") moveDir(50);
  else if (command == "60") moveDir(60); //center
  else if (command == "70") moveDir(70);
  else if (command == "80") moveDir(80);
  else if (command == "90") moveDir(90);
  else if (command == "100") moveDir(100); //far right
  else if (command == "0") speedCar = 0;
  else if (command == "1") speedCar = 25;
  else if (command == "2") speedCar = 50;
  else if (command == "3") speedCar = 150;
  else if (command == "4") speedCar = 200;
  else if (command == "9") speedCar = 255;
  else if (command == "S") stopRobot();

  else if (command == "B") goBack();
  else if (command == "L") goLeft();
  else if (command == "R") goRight();
  else if (command == "I") goAheadRight();
  else if (command == "G") goAheadLeft();
  else if (command == "J") goBackRight();
  else if (command == "H") goBackLeft();

  // moveServo();
}

void HTTP_handleRoot(void) {
  if (server.hasArg("State")) {
    Serial.println(server.arg("State"));
  }
  server.send(200, "text/html", "");
  delay(1);
}




#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is ``on
  
  // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Hello world!");
  
  lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
  lcd.print("LCD Tutorial");
}

void loop() {
}