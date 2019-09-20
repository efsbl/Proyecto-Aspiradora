#define gpio 14

int rune;
boolean runestate;
int nrune;
int vueltas;
boolean turnstate;
 
void setup() {
  Serial.begin(9600);
  pinMode(gpio, INPUT);
 
  rune = (int)(0);
  runestate = (boolean)(false);
  nrune = (int)(40);
  vueltas = (int)(0);
  turnstate = (boolean)(false);
 delay(1000);
}
 
void loop() {

  
  if(digitalRead(14) != runestate){
    runestate = digitalRead(gpio);
      rune = rune + 1;
    Serial.println(rune);
    vueltas = rune / nrune;
 
  }if(vueltas != turnstate){
    turnstate = vueltas;
      Serial.println((String("Vueltas: ") + String(vueltas - 2)));
      Serial.println((String("Ticks: ") + String(rune - 80)));
 
  }
}
