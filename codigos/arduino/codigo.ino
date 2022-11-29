// Puertos Arduino
#include <SoftwareSerial.h>
SoftwareSerial serialBT(3, 2);

char state;

int ruedas_izquierda_adelante = 11;
int ruedas_izquierda_atras = 12;
int ruedas_derecha_adelante = 8;
int ruedas_derecha_atras = 10;
int arma = 4;

// Inicialización de variables
void setup()
{
  pinMode(ruedas_izquierda_adelante, OUTPUT);
  pinMode(ruedas_izquierda_atras, OUTPUT);
  pinMode(ruedas_derecha_adelante, OUTPUT);
  pinMode(ruedas_derecha_atras, OUTPUT);
  pinMode(arma, OUTPUT);
  limpiarRuedas();   // todos los motores parten apagados
  limpiarArma();
  Serial.begin(9600);
  serialBT.begin(9600);
}

void loop() {
  leerSerial();
}


void limpiarRuedas(){
  digitalWrite(ruedas_izquierda_adelante, 0);
  digitalWrite(ruedas_izquierda_atras, 0);
  digitalWrite(ruedas_derecha_adelante, 0);
  digitalWrite(ruedas_derecha_atras, 0);
}

void limpiarArma(){
  digitalWrite(arma, 0);
  }
void avanza(){
  digitalWrite(ruedas_derecha_adelante, 1);
  digitalWrite(ruedas_izquierda_adelante, 1);
}

void retrocede(){
  digitalWrite(ruedas_derecha_atras, 1);
  digitalWrite(ruedas_izquierda_atras, 1);
}

void izquierda(){
  digitalWrite(ruedas_izquierda_atras, 1);
  digitalWrite(ruedas_derecha_adelante, 1);
}

void derecha(){
  digitalWrite(ruedas_izquierda_adelante, 1);
  digitalWrite(ruedas_derecha_atras, 1);
}

void leerSerial() {
  serialBT.listen(); 
  if (serialBT.available() > 0) {
    state = serialBT.read();
    Serial.println(state);
    
    if (state == 'G') {
      limpiarRuedas();
      avanza();
	}
    
    if (state == 'B') {
      limpiarRuedas();
      retrocede();
	}
    
    if (state == 'S') {
      limpiarRuedas();

	} 
    
    if (state == 'L') {
      limpiarRuedas();
      izquierda();
    }
    
    if (state == 'R') {
      limpiarRuedas();
      derecha();
    }
    
    if (state == 'W') {
      digitalWrite(arma,1);
      
    }
    if (state == 'M'){
      limpiarArma();
    }
    
    
  }
}


  
