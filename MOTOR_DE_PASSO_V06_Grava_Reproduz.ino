
int potenciometro=A7;
int Grava=10;//grava
int Reproduz=9;//reproduz
int step_Motor=A11;
int val, angulo;
int vetor_de_posicoes[50];
int controle; 
int conta; 
void setup() {
  Serial.begin(9600);
  pinMode(Grava, INPUT);
  pinMode(Reproduz, INPUT);
  digitalWrite(Grava, LOW);
  digitalWrite(Reproduz, LOW);
  analogWrite(step_Motor,OUTPUT);
 
}

void loop()
{
  //-------------------------------------------------------------------------------------------------------------------------------------------------
   if(digitalRead(Grava)==HIGH)
  {
    Serial.println("Gravando..");//imforma queesta gravando
    for(controle=0; controle<= 50;controle++)//laço de repetiçao para gravar as posiçoes 
    {   
        val=analogRead(potenciometro)/4; //lê o potenciometro e divide por 4 para 0  á 255
        angulo=map(val, 0, 1023, 0, 255);//tranforma em angulo ...a rpicipio é reduntante mas deixo assim por enquanto
        vetor_de_posicoes[controle]=angulo;//armazena os valores para posicoes
        delay(1000); //aguarda para novos valores
        Serial.println(angulo);//amostragem dos valors para conferencia no console
        if(vetor_de_posicoes[controle-1]==vetor_de_posicoes[controle]) //sai do laço se caso nao for usar todas as casas do vetor[50]
        break;
    }
    Serial.println("Saindo..");
    printf("foi %d", controle); 
    Serial.println(controle);    //confere quantas vezes contos os dados
  }
  //-------------------------------------------------------------------------------------------------------------------------------------------------
 if(digitalRead(Reproduz)==HIGH)
  {
      //....................reproduzindo os dados no motor.......
    Serial.println("Reproduzindo..");
      for(conta=0; conta<= controle ;conta++)
      {   
            digitalWrite(step_Motor, HIGH);
            delayMicroseconds(500);
            digitalWrite(step_Motor, LOW);
            delayMicroseconds(500);  
          Serial.println(vetor_de_posicoes[controle]);
          for()
          {
            
            delay(1000);        
            if(vetor_de_posicoes[controle-1]==vetor_de_posicoes[controle])
            break;
          }
          
      }
      Serial.println("fim.."); 
      Serial.println(controle);    //confere quantas vezes contos os dados
  }
  
}
