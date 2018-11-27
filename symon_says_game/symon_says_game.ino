const int red=2; 
const int blue=3; 
const int yellow=4;
const int green=5; 
const int white=6; 
const int buzzer=7; 
long sequence[99];             // Array que alberga la secuencia
int contador = 0;   
const int bred=9; 
const int bblue=10;
const int byellow=11; 
const int bgreen=12; 
const int bwhite=13; 
int counter=0; 
int counter2=0; 
int pres1, pres2, pres3, pres4, pres5; 
long input = 6; 
int wait =1000; 
int highest_score =99; 

int length =15; //Numero de notas de la melodia 
char notes[] = "ccggaagffeeddc "; // Notas de la melodia (cada letra es una nota distinta)
  int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };  // Duracion de cada tono en un array
  int tempo = 100;  //Tempo de la melodia 

void encender(int a, int b, int c, int d, int e, int f, int g)
{
  //Funcion que permite mostrar los numeros del 0 al 9
  //Asigna un segmento del display1 a cada pin

  digitalWrite(22, a);  //Asigna el segmento 'a' al pin 2
  digitalWrite(23, b);  //Asigna el segmento 'b' al pin 3
  digitalWrite(24, c);  //Asigna el segmento 'c' al pin 4
  digitalWrite(25, d);  //Asigna el segmento 'd' al pin 5
  digitalWrite(26, e);  //Asigna el segmento 'e' al pin 6
  digitalWrite(27, f);  //Asigna el segmento 'f' al pin 7
  digitalWrite(28, g);  //Asigna el segmento 'g' al pin 8
}

void encender2(int h, int i, int j, int k, int l, int m, int n)
{
  //Funcion que permite mostrar los numeros del 0 al 9
  //Asigna un segmento del display2 a cada pin

  digitalWrite(29, h);  //Asigna el segmento 'a' al pin 2
  digitalWrite(30, i);  //Asigna el segmento 'b' al pin 3
  digitalWrite(31, j);  //Asigna el segmento 'c' al pin 4
  digitalWrite(32, k);  //Asigna el segmento 'd' al pin 5
  digitalWrite(33, l);  //Asigna el segmento 'e' al pin 6
  digitalWrite(34, m);  //Asigna el segmento 'f' al pin 7
  digitalWrite(35, n);  //Asigna el segmento 'g' al pin 8
}

void setup()
{
  pinMode(red,OUTPUT); 
  pinMode(blue,OUTPUT); 
  pinMode(yellow,OUTPUT);  
  pinMode(green,OUTPUT); 
  pinMode(white,OUTPUT);
  pinMode(buzzer,OUTPUT); 
  //////////////////////
  pinMode(bred,INPUT); 
  pinMode(bblue,INPUT); 
  pinMode(byellow,INPUT); 
  pinMode(bgreen,INPUT); 
  pinMode(bwhite,INPUT); 
  ///////////////////////
  digitalWrite(bred,HIGH); 
  digitalWrite(bblue,HIGH); 
  digitalWrite(byellow,HIGH); 
  digitalWrite(bgreen,HIGH); 
  digitalWrite(bwhite,HIGH); 
  /////////////////////// 
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
   /////////////////////// 
  pinMode(29, OUTPUT); 
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  } 
void loop()
{
  nivel();
  /*mostrar_secuencia();  // Reproduce la sequencia 
  delay(2000);
  leer_secuencia();     // Lee la sequencia
  delay(1000);          // Espera 1 segundo*/
  } 

   // Funcion para definir las notas y sus frecuencias
  void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
 
  for (int i = 0; i < 8; i++) {
     if (names[i] == note) {
       playtone(tones[i], duration);
     }
   }
  } 

   // Funcion para definir las notas segun la duración y el tono
  void playtone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone *2) {
      digitalWrite(buzzer, HIGH);
      delayMicroseconds(tone);
      digitalWrite(buzzer, LOW);
      delayMicroseconds(tone);
    }
  }

  void flash_red() { 
  digitalWrite(red, HIGH);
  playtone(2273,wait);            
  digitalWrite(red, LOW);
  }
  
  void flash_blue() {
  digitalWrite(blue, HIGH);
  playtone(1700,wait);            
  digitalWrite(blue, LOW); 
  } 

  void flash_yellow() {
  digitalWrite(yellow, HIGH);
  playtone(1275,wait);             
  digitalWrite(yellow, LOW);
  } 
  
  void flash_green() {
  digitalWrite(green, HIGH);
  playtone(1136,wait);             
  digitalWrite(green, LOW);
  } 

  void flash_white() {
  digitalWrite(white, HIGH);
  playtone(1000,wait);             
  digitalWrite(white, LOW);
  } 

  //Funcion para mostrar que boton se debe presionar
  void mostrar_boton(long led) {
    switch (led) {
        case 0:
          flash_red(); 
          displays();
          break;
        case 1:
          flash_blue();
          displays();
          break;
        case 2:
          flash_yellow(); 
          displays();
          break;
        case 3:
          flash_green();
          displays();
          break; 
        case 4:
          flash_white();
          displays();
          break;
      }
      delay(50);
     } 
     void inicio(){
     digitalWrite(red, HIGH);       
     digitalWrite(green, HIGH);
     digitalWrite(yellow, HIGH);
     digitalWrite(blue, HIGH); 
     digitalWrite(white, HIGH); 

     delay(1000);   
     digitalWrite(red, LOW);      
     digitalWrite(green, LOW);
     digitalWrite(yellow, LOW);
     digitalWrite(blue, LOW); 
     digitalWrite(white, LOW); 
      }

     void fin() {
     digitalWrite(red, HIGH);       
     digitalWrite(green, HIGH);
     digitalWrite(yellow, HIGH);
     digitalWrite(blue, HIGH); 
     digitalWrite(white, HIGH); 

     delay(500);   
     digitalWrite(red, LOW);      
     digitalWrite(green, LOW);
     digitalWrite(yellow, LOW);
     digitalWrite(blue, LOW); 
     digitalWrite(white, LOW); 
     delay(500); 

      digitalWrite(red, HIGH);       
     digitalWrite(green, HIGH);
     digitalWrite(yellow, HIGH);
     digitalWrite(blue, HIGH); 
     digitalWrite(white, HIGH); 

     delay(500);   
     digitalWrite(red, LOW);      
     digitalWrite(green, LOW);
     digitalWrite(yellow, LOW);
     digitalWrite(blue, LOW); 
     digitalWrite(white, LOW); 
     delay(500);

     digitalWrite(red, HIGH);       
     digitalWrite(green, HIGH);
     digitalWrite(yellow, HIGH);
     digitalWrite(blue, HIGH); 
     digitalWrite(white, HIGH); 

     delay(500);   
     digitalWrite(red, LOW);      
     digitalWrite(green, LOW);
     digitalWrite(yellow, LOW);
     digitalWrite(blue, LOW); 
     digitalWrite(white, LOW);
     resetcontador();   
     displays();                 
    } 

    void resetcontador() {
      nivel();
    contador = 0; 
    counter = 0; 
    counter2 =0;
    wait;
    } 


  // Funcion para leer los botones que pulsa el jugador
 void leer_secuencia() {
   for (int i=1; i < contador; i++) {              
      while (input==6){                          
        if (digitalRead(bred) == LOW) {   
          displays(); 
          counter++;       //Aumenta el contador
    if (counter > 9)
    {
      counter = 0; //Si el contador esta en 9 y se aumenta, sigue mostrando el 9 
      counter2++;
      if(counter2 > 9)
      {
        counter2 = 0;
        fin();
        }
      }
          input = 0;
        }
        if (digitalRead(bblue) == LOW) { 
          displays(); 
          counter++;       //Aumenta el contador
    if (counter > 9)
    {
      counter = 0; //Si el contador esta en 9 y se aumenta, sigue mostrando el 9 
      counter2++;
      if(counter2 > 9)
      {
        counter2 = 0;
        fin();
        }
      }
          input = 1;
        }
        if (digitalRead(byellow) == LOW) {
          displays();
          counter++;       //Aumenta el contador
    if (counter > 9)
    {
      counter = 0; //Si el contador esta en 9 y se aumenta, sigue mostrando el 9 
      counter2++;
      if(counter2 > 9)
      {
        counter2 = 0;
        fin();
        }
      }
          input = 2;
        }
        if (digitalRead(bgreen) == LOW) {  
          displays(); 
          counter++;       //Aumenta el contador
    if (counter > 9)
    {
      counter = 0; //Si el contador esta en 9 y se aumenta, sigue mostrando el 9 
      counter2++;
      if(counter2 > 9)
      {
        counter2 = 0;
        fin();
        }
      }
          input = 3;
        } 
        if (digitalRead(bwhite) == LOW) { 
          displays();  
          counter++;       //Aumenta el contador
    if (counter > 9)
    {
      counter = 0; //Si el contador esta en 9 y se aumenta, sigue mostrando el 9 
      counter2++;
      if(counter2 > 9)
      {
        counter2 = 0;
        fin();
        }
      }
          input = 4;
        }
      }
    
   if (sequence[i-1] == input) {              
        mostrar_boton(input);                         
        if (i == highest_score) {                        
          fin();                        
        }
      }
        else {
          playtone(4545,1500);                  
          delay(1000);
          fin();
          resetcontador(); 
          displays();                         
      } 
    input = 6;                                   
    }
  } 

   void displays()
   {
    //Condicionales para antirrebote y uso del pulsador aumentar

  if (digitalRead(bred)== LOW)
  {
    pres1 = 1;   //Variable del antirrebote que cambia cuando se presiona el pulsador
  }
  if (digitalRead(bred)== HIGH && pres1 == 1)
  {
    pres1 = 0;  //Se reinicia la variable antirrebote
    
    }

    if (digitalRead(bblue)== LOW)
  {
    pres2 = 1;   //Variable del antirrebote que cambia cuando se presiona el pulsador
  }
  if (digitalRead(bblue)== HIGH && pres2 == 1)
  {
    pres2 = 0;  //Se reinicia la variable antirrebote
    
    } 

    if (digitalRead(byellow)== LOW)
  {
    pres3 = 1;   //Variable del antirrebote que cambia cuando se presiona el pulsador
  }
  if (digitalRead(byellow)== HIGH && pres3 == 1)
  {
    pres3 = 0;  //Se reinicia la variable antirrebote
    
    }

    if (digitalRead(bgreen)== LOW)
  {
    pres4 = 1;   //Variable del antirrebote que cambia cuando se presiona el pulsador
  }
  if (digitalRead(bgreen)== HIGH && pres4 == 1)
  {
    pres4 = 0;  //Se reinicia la variable antirrebote
    
    } 

    if (digitalRead(bwhite)== LOW)
  {
    pres5 = 1;   //Variable del antirrebote que cambia cuando se presiona el pulsador
  }
  if (digitalRead(bwhite)== HIGH && pres5 == 1)
  {
    pres5 = 0;  //Se reinicia la variable antirrebote
   
    }

     switch (counter)
  {
    //Dependiendo del contador, se muestra el numero indicado
    

    case 0:
      encender (0, 0, 0, 0, 0, 0, 1); //Muestra el numero 0
      break;

    case 1:
      encender (1, 0, 0, 1, 1, 1, 1); //Muestra el numero 1
      break;

    case 2:
      encender (0, 0, 1, 0, 0, 1, 0); //Muestra el numero 2
      break;

    case 3:
      encender (0, 0, 0, 0, 1, 1, 0); //Muestra el numero 3
      break;

    case 4:
      encender (1, 0, 0, 1, 1, 0, 0); //Muestra el numero 4
      break;

    case 5:
      encender (0, 1, 0, 0, 1, 0, 0); //Muestra el numero 5
      break;

    case 6:
      encender (0, 1, 0, 0, 0, 0, 0); //Muestra el numero 6
      break;

    case 7:
      encender (0, 0, 0, 1, 1, 1, 1); //Muestra el numero 7
      break;

    case 8:
      encender (0, 0, 0, 0, 0, 0, 0); //Muestra el numero 8
      break;

    case 9:
      encender (0, 0, 0, 1, 1, 0, 0); //Muestra el numero 9
      break;
  } 
///////////////////
  switch (counter2)
  {
    

    case 0:
      encender2 (0, 0, 0, 0, 0, 0, 1); //Muestra el numero 0
      break;

    case 1:
      encender2 (1, 0, 0, 1, 1, 1, 1); //Muestra el numero 1
      break;

    case 2:
      encender2 (0, 0, 1, 0, 0, 1, 0); //Muestra el numero 2
      break;

    case 3:
      encender2 (0, 0, 0, 0, 1, 1, 0); //Muestra el numero 3
      break;

    case 4:
      encender2 (1, 0, 0, 1, 1, 0, 0); //Muestra el numero 4
      break;

    case 5:
      encender2 (0, 1, 0, 0, 1, 0, 0); //Muestra el numero 5
      break;

    case 6:
      encender2 (0, 1, 0, 0, 0, 0, 0); //Muestra el numero 6
      break;

    case 7:
      encender2 (0, 0, 0, 1, 1, 1, 1); //Muestra el numero 7
      break;

    case 8:
      encender2 (0, 0, 0, 0, 0, 0, 0); //Muestra el numero 8
      break;

    case 9:
      encender2 (0, 0, 0, 1, 1, 0, 0); //Muestra el numero 9
      break;
     }
    }
    void nivel()
   {
    if(digitalRead(bred)==LOW) 
    { 
      inicio();
      while(true){
        brojo(); 
        if(contador == false )
        {break;}
        } 
       }
      
       if(digitalRead(byellow)==LOW)
      {
        inicio();
       while(true){
       bamarillo(); 
       if(contador == false )
        {break;}
        }
       }
       if(digitalRead(bgreen)==LOW)
      {
        inicio();
       while(true){
       berde(); 
       if(contador == false )
        {break;}
        }
       } 
       
    }
    void brojo() //Nivel 3
    {
    randomSeed(analogRead(9));

  sequence[contador] = random(5);       
    for (int i = 0; i < contador; i++) {  
      mostrar_boton(sequence[i]);             
    }
    
    wait=230  - (contador * 15);        
    contador++;   
    delay(1000);
      leer_secuencia();     // Lee la sequencia
      delay(1000); 
   }
   
   void bamarillo() //Nivel 2
    {
        //delay(1000);
    randomSeed(analogRead(9));
    
  sequence[contador] = random(5);       
    for (int i = 0; i < contador; i++) {  
      mostrar_boton(sequence[i]);             
    }
    wait=500  - (contador * 15);        
    contador++;   
    delay(1000);
      leer_secuencia();     // Lee la sequencia
      delay(1000); 
   }
   void berde() //nivel 1
    {
        //delay(2000);
    randomSeed(analogRead(9));
    
  sequence[contador] = random(5);       
    for (int i = 0; i < contador; i++) {  
      mostrar_boton(sequence[i]);             
    }
    wait=1000  - (contador * 15);        
    contador++;   
    delay(1000);
      leer_secuencia();     // Lee la sequencia
      delay(1000); 
   }
   
    
    
