#include <ESP8266WiFi.h>
const char ssid[] = "NodeMCU-ESP8266";  
//const char *password = "12345678";
WiFiServer server(80); 



//Motores
int PinIN1 = 5;
int PinIN2 = 4;
int PinIN3 = 0;
int PinIN4 = 2;

void MoverAdelante();
void MoverAtras();
void GirarDerecha();
void GirarIzquierda();
void Detener();


void setup() {
  Serial.begin (115200);


  // configuramos los pines como salida
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);

  server.begin();                         //inicializamos el servidor
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid); 
  Serial.println();
  Serial.print("Direccion IP Access Point - por defecto: ");      //Imprime la dirección IP
  Serial.println(WiFi.softAPIP()); 
  Serial.print("Direccion MAC Access Point: ");                   //Imprime la dirección MAC
  Serial.println(WiFi.softAPmacAddress()); 
  
}

void loop() {
  // Comprueba si el cliente ha conectado
  WiFiClient client = server.available();  
  if (!client) {
    return;
  }
 
  // Espera hasta que el cliente envía alguna petición
  Serial.println("nuevo cliente");
  while(!client.available()){
    delay(1);
  }
 
  // Imprime el número de clientes conectados
    Serial.printf("Clientes conectados al Access Point: %dn", WiFi.softAPgetStationNum()); 
    
    String linea1 = client.readStringUntil('r');// Leemos la primera línea de la petición del cliente.
    Serial.print("LINEA: ");
    Serial.println(linea1);
    
    if (linea1.indexOf("ADELANTE") > 0) { 
      MoverAdelante();
    }
    if (linea1.indexOf("ATRAS") > 0)  {
      MoverAtras();
    }
    if (linea1.indexOf("DERECHA") > 0)  {
      GirarDerecha();
    }
    if (linea1.indexOf("IZQUIERDA") > 0)  {
      GirarIzquierda();
    }
     if (linea1.indexOf("PARAR") > 0)  {
      Detener();
    }
    client.flush();
    Serial.println("Enviando respuesta...");
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");// La conexión se cierra después de finalizar de la respuesta
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head><title>WALTER: Robot Aspiradora</title>");
    client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
    client.println("<style>button{background-color:#f44336;border:none;color:white;padding:15px 32px;text-align:center;text-decoration:none;display:inline-block;font-size: 24px; transition-duration: 0.4s;}button:hover{background-color: #4CAF50;  color: white;}</style>");
    client.println("</head>");
    client.println("<body>");
    client.println("<div style='text-align:center;'>");
    client.println("<h1 align='center'>Walter: Robot Aspiradora</h1>");
    client.println("<br />");
    client.println("<button onClick=location.href='./?ADELANTE'>ADELANTE</button><br>");
    client.println("<button onClick=location.href='./?ATRAS'>ATRAS</button><br>");
    client.println("<button onClick=location.href='./?DERECHA'>DERECHA</button><br>");
    client.println("<button onClick=location.href='./?IZQUIERDA'>IZQUIERDA</button><br>");
    client.println("<button onClick=location.href='./?PARAR'>PARAR</button>");
    client.println("<br />");
    client.println("</div>");
    client.println("</body>");
    client.println("</html>");
    delay(1);
    Serial.println("RESPUESTA ENVIADA");
    Serial.println();
  }




void MoverAdelante()
{
   digitalWrite (PinIN1, HIGH);
   digitalWrite (PinIN2, LOW);
   digitalWrite (PinIN3, HIGH);
   digitalWrite (PinIN4, LOW);
}

void MoverAtras(){
   digitalWrite (PinIN1, LOW);
   digitalWrite (PinIN2, HIGH);
   digitalWrite (PinIN3, LOW);
   digitalWrite (PinIN4, HIGH);
  
}

void GirarDerecha(){
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
}

void GirarIzquierda(){
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  
}

void Detener(){
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);
}
