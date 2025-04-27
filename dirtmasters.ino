
#define fbpin 9
#define lrpin 10
#define tpin 11

#define in1 7
#define in2 4
#define in3 3
#define in4  2
#define en1 6

int SPEED;

void setup() {
  pinMode(fbpin,INPUT);
  pinMode(lrpin,INPUT);
  pinMode(tpin,INPUT);
  Serial.begin(9600);

  pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
      pinMode(in3,OUTPUT);
        pinMode(in4,OUTPUT);
          pinMode(en1,OUTPUT);
           

}

void loop() {
  int lr = pulseIn(fbpin,HIGH);
   int fb = pulseIn(lrpin,HIGH);
    int th = pulseIn(tpin,HIGH);

    Serial.print("fbval:");
      Serial.print(fb);
        Serial.print(" lrval:");
          Serial.print(lr);
            Serial.print(" thval:");
              Serial.println(th);

   SPEED = map(th,992,1987,0,255);           
 if(lr>1900){
  front();
 }
 else if(lr < 1100){
  back();
 }
 
 else if(fb > 1900){
  right();
 }
 else if(fb < 1100){
  left();
 }
 else {
  stopt();
 }
}
void front(){
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   analogWrite(en1,SPEED);
}
void back(){
   digitalWrite(in2,HIGH);
   digitalWrite(in1,LOW);
    analogWrite(en1,SPEED);
}
void stopt(){
   digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);
    analogWrite(en1,0);
}
void left(){
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void right(){
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
}
