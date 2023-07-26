// Definindo os sensores.



#define R_S A7 // Sensor lateral direita 

#define L_S AD // Sensor lateral esquerda

// Definindo os pinos dos motores de acordo com as conexões entre a Ponte H e o Arduino (vide esquema do circuito)

// Motor A (esq.)
const int enA = 8;
const int IN1 = 12;
const int IN2 = 11;
// Motor B (dir.)
const int enB = 7;
const int IN3 = 10;
const int IN4 = 9;

// Velocidades: vão de 0 a 255 e, portanto, deve-se usar analogWrite (valor analógico)
int velocidadeA = 255;
int velocidadeB = 255;



void setup(){ 
  //motores
  pinMode(enA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  //Sensores
  pinMode(R_S, INPUT); 
  pinMode(L_S, INPUT); 
  delay(1000);
  Serial.begin(9600);
}

void loop(){  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){Afrente();}   //Se o sensor direito e o sensor esquerdo estiverem na cor branca, ele chamará a função Afrente (Andar para frente)

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){Vdireita();} //Se o sensor direito for preto e o sensor esquerdo for branco, ele chamará a função Vdireita (Virar à direita)

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){Vesquerda();}  //se o sensor direito for branco e o sensor esquerdo for preto, ele chamará a função Vesquerda (Virar à esquerda)

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){Parar();} //Se o sensor direito e o sensor esquerdo estiverem na cor preta, ele chamará a função Parar

}




void Afrente(){   // Mover-se para a frente.
  // Motor A para frente
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Motor B para frente
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);
  Serial.print("batata//"); 
}

void Vesquerda(){   //Virar para a esquerda.
  // Motor A parado
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  // Motor B para frente
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);
  Serial.print("arroz//"); 
}
  
void Vdireita(){ //Virar para a direita
   
  // Motor A para frente
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Motor B parado
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(2000);
  Serial.print("gilmar//"); 
}

void Parar(){   //Parado
  // Motor A parado
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  // Motor B para frente
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(2000);
  Serial.print("carlos//"); 
}
