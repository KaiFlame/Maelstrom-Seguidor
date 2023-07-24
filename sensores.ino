// Definindo os sensores.


#define F_S A1, A2, A3, A4, A5, Ab // Sensor frontal

#define R_S A7 // Sensor lateral direita 

#define L_S AD // Sensor lateral esquerda

//Obs: Não sei se a definição do sensor frontal esta correta.

void setup(){ 

pinMode(R_S, INPUT); 

pinMode(L_S, INPUT); 

pinMode(F_S, INPUT); 

delay(1000);

}

void loop(){  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){Afrente();}   //Se o sensor direito e o sensor esquerdo estiverem na cor branca, ele chamará a função Afrente (Andar para frente)

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){Vdireita();} //Se o sensor direito for preto e o sensor esquerdo for branco, ele chamará a função Vdireita (Virar à direita)

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){Vesquerda();}  //se o sensor direito for branco e o sensor esquerdo for preto, ele chamará a função Vesquerda (Virar à esquerda)

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){Parar();} //Se o sensor direito e o sensor esquerdo estiverem na cor preta, ele chamará a função Parar

}


// Falta definir o nome das funções de movimento (no código que o Albergaria fez), para que o robo realize os movimentos de acordo com os sensores. 

