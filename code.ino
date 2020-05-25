char t;
 
void setup() {
pinMode(13,OUTPUT);    //LED1
pinMode(12,OUTPUT);    //LED2
pinMode(11,OUTPUT);    //Lewe koła wstecz
pinMode(10,OUTPUT);    //Lewe koła naprzód
pinMode(9,OUTPUT);     //Prawe koła wstecz
pinMode(8,OUTPUT);     //Prawe koła naprzód

digitalWrite(13,HIGH); //wszystko OFF na start
digitalWrite(12,HIGH);
digitalWrite(11,HIGH);
digitalWrite(10,HIGH);
digitalWrite(9,HIGH);
digitalWrite(8,HIGH);
  
Serial1.begin(9600);
 
}
 
void loop() {
if(Serial1.available()){
  t = Serial1.read();
  Serial1.println(t);
}
 
if(t == 'F'){            //Cała naprzód
  digitalWrite(10,LOW);
  digitalWrite(8,LOW);
}
 
else if(t == 'B'){      //Cała wstecz
  digitalWrite(11,LOW);
  digitalWrite(9,LOW);
}
 
else if(t == 'R'){      //Skręć w prawo (lewe koła do tyłu; prawe koła do przodu)
  digitalWrite(8,LOW);
  digitalWrite(11,LOW);
}
 
else if(t == 'L'){      //Skręć w lewo (lewe koła do przodu; prawe koła do tyłu)
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}

else if(t == 'M'){      //LED Śmierci 1
  digitalWrite(13,LOW);
}
else if(t == 'S'){      //LED Śmierci 2
  digitalWrite(12,LOW);
}
else if(t == 'W'){
  digitalWrite(12,LOW);
  delay(250);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  delay(250);
  digitalWrite(13,HIGH);
}
else if(t == 'A'){
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  delay(250);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  delay(250);
}
 
else {      
  digitalWrite(13,HIGH); //Wszystko Stop
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
}
delay(100);
}
