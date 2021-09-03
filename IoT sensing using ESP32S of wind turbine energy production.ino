#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define BLYNK_PRINT Serial
#define  Simple.timer  Timer


WidgetLED led2(V1);                      //LIVE >> Led para sinalizar Blynk conectado


float v0;
const int pinoSensor = A0; //PINO ANALÓGICO EM QUE O SENSOR ESTÁ CONECTADO



char auth[] = //"your char auth";

char ssid[] = //"Your char ssid"; 
char pass[] = //"Your char pass";

//char ssid1[] = "";             
//char pass1[] = "";

//char ssid2[] = "";
//char pass2[] = "";

//char ssid3[] = "";
//char pass3[] = "";

//char ssid4[] = "";
//char pass4[] = "";

 
float tensaoEntrada = 0.0; //VARIÁVEL PARA ARMAZENAR O VALOR DE TENSÃO DE ENTRADA DO SENSOR
float tensaoMedida = 0.0; //VARIÁVEL PARA ARMAZENAR O VALOR DA TENSÃO MEDIDA PELO SENSOR
 
float valorR1 = 30000.0; //VALOR DO RESISTOR 1 DO DIVISOR DE TENSÃO
float valorR2 = 7500.0; // VALOR DO RESISTOR 2 DO DIVISOR DE TENSÃO
int leituraSensor = 0; //VARIÁVEL PARA ARMAZENAR A LEITURA DO PINO ANALÓGICO



BlynkTimer timer;
void myTimerEvent()
{
  
  Blynk.virtualWrite(V0, millis() / 1000);
}


void setup(){
   pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
   Serial.begin(115200); //INICIALIZA A SERIAL
   Blynk.begin(auth, ssid, pass);
   
   timer.setInterval(1000L, myTimerEvent);

}
void loop(){

   Blynk.run();
   leituraSensor = analogRead(pinoSensor); //FAZ A LEITURA DO PINO ANALÓGICO E ARMAZENA NA VARIÁVEL O VALOR LIDO
   tensaoEntrada = (leituraSensor * 5.0) / 1024.0; //VARIÁVEL RECEBE O RESULTADO DO CÁLCULO
   tensaoMedida = tensaoEntrada / (valorR2/(valorR1+valorR2)); //VARIÁVEL RECEBE O VALOR DE TENSÃO DC MEDIDA PELO SENSOR
   Blynk.virtualWrite(V0, tensaoMedida);
   timer.run();
   Serial.print("Tensão DC medida: "); //IMPRIME O TEXTO NA SERIAL
   Serial.print(tensaoMedida,2); //IMPRIME NA SERIAL O VALOR DE TENSÃO DC MEDIDA E LIMITA O VALOR A 2 CASAS DECIMAIS
   Serial.println("V"); //IMPRIME O TEXTO NA SERIAL
   delay(1000); //INTERVALO DE 1000 MILISSEGUNDOS
}

float tensaoEntrada = 0.0; //VARIÁVEL PARA ARMAZENAR O VALOR DE TENSÃO DE ENTRADA DO SENSOR
float tensaoMedida = 0.0; //VARIÁVEL PARA ARMAZENAR O VALOR DA TENSÃO MEDIDA PELO SENSOR
 
float valorR1 = 30000.0; //VALOR DO RESISTOR 1 DO DIVISOR DE TENSÃO
float valorR2 = 7500.0; // VALOR DO RESISTOR 2 DO DIVISOR DE TENSÃO
int leituraSensor = 0; //VARIÁVEL PARA ARMAZENAR A LEITURA DO PINO ANALÓGICO
 
void setup(){
   pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
   Serial.begin(115200); //INICIALIZA A SERIAL
   Blynk.begin(auth, ssid, pass);
 
}

void loop(){
   Blynk.run();
   Timer.run();

   leituraSensor = analogRead(pinoSensor); //FAZ A LEITURA DO PINO ANALÓGICO E ARMAZENA NA VARIÁVEL O VALOR LIDO
   tensaoEntrada = (leituraSensor * 5.0) / 1024.0; //VARIÁVEL RECEBE O RESULTADO DO CÁLCULO
   tensaoMedida = tensaoEntrada / (valorR2/(valorR1+valorR2)); //VARIÁVEL RECEBE O VALOR DE TENSÃO DC MEDIDA PELO SENSOR
   Blynk.virtualWrite(V0, tensaoMedida);

   Serial.print("Tensão DC medida: "); //IMPRIME O TEXTO NA SERIAL
   Serial.print(tensaoMedida,2); //IMPRIME NA SERIAL O VALOR DE TENSÃO DC MEDIDA E LIMITA O VALOR A 2 CASAS DECIMAIS
   Serial.println("V"); //IMPRIME O TEXTO NA SERIAL
   delay(500); //INTERVALO DE 500 MILISSEGUNDOS
}
