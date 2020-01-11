#define led 13
#define buton 12
#define titresim 7
#define buzzer 4
#define gaz A0
#define onisisuresi 4000
#define esikdeger 240


void setup() {
  pinMode(titresim,INPUT);
  pinMode(buton,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  delay(onisisuresi);

}

void loop() {
  int titresimdegeri = digitalRead(titresim);
  int dumandegeri = analogRead(gaz);
  int butondegeri = digitalRead(buton);
  Serial.print("Titresim Degeri: ");
  Serial.println(titresimdegeri);
  Serial.print("Yanıcı Gaz Degeri: ");
  Serial.println(dumandegeri);
  if(titresimdegeri == 1 or dumandegeri >= esikdeger){
    while (butondegeri == 0){
        tone(buzzer,500);
        digitalWrite(led,LOW);
    }

  }
  else {
    noTone(buzzer);
    digitalWrite(led,HIGH);  
  }
  delay(1050);
}
