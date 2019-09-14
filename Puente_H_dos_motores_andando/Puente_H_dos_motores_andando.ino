int PinIN1 = 5;
int PinIN2 = 4;
int PinIN3 = 0;
int PinIN4 = 2;


void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  // configuramos los pines como salida
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
}

void loop() {
  
  MotorHorario1();
  Serial.println("Giro del Motor 1 en sentido horario");
  MotorHorario2();
  Serial.println("Giro del Motor 2 en sentido horario");
  delay(1000);
  
  MotorAntihorario1();
  Serial.println("Giro del Motor 1 en sentido antihorario");
  MotorAntihorario2();
  Serial.println("Giro del Motor 2 en sentido antihorario");
  delay(1000);
  
  MotorStop1();
  Serial.println("Motor 1 Detenido");
  MotorStop2();
  Serial.println("Motor 2 Detenido");
  delay(1000);
  
}

void MotorHorario1()
{
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
}
void MotorAntihorario1()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
}

void MotorStop1()
{
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
}

void MotorHorario2()
{
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
}
void MotorAntihorario2()
{
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
}

void MotorStop2()
{
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);
}
