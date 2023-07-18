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


void setup() {
  // Colocando os pinos definidos anteriormente em modo OUTPUT (saída de dados)
  pinMode(enA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  // OBS.: pode ser necessário inverter os valores HIGH e LOW em cada motor, bem como a direção das curvas, a depender da instalação deles no robô (podem ter sido invertidos na montagem)

  // Motor A para frente
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Motor B para frente
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // Motor A para trás
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Motor B para trás
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  // Curva no sentido anti-horário
  // Motor A parado
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  // Motor B para frente
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // Curva no sentido horário
  // Motor A parado
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Motor B para frente
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  // Definir a velocidade de cada motor (velocidades diferentes podem causar outras curvas)
  analogWrite(enA, velocidadeA);
  analogWrite(enB, velocidadeB); 

  // A partir dessa base, é interessante pensar em um algoritmo que mude a velocidade de cada motor separadamente de acordo com a leitura do sensor.
  // Ex.: Quanto mais preto os sensores à esquerda captarem, maior deve ser a velocidade do motor da direita, para corrigir a direção do robô. 
}
