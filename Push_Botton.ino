int led= 5;
int bnt= 3;
int bntclicado=0;
int bntliberado=0;



void setup() {
 pinMode (led,OUTPUT);
 pinMode (bnt,INPUT);
}

void troca_led(){
  if(digitalRead (led)){
    digitalWrite(led,LOW);
  }
  else{
    digitalWrite(led,HIGH);
    }
}

void bntestado(){
  if (bntclicado==1 && bntliberado==1){
    bntclicado=0;
    bntliberado=0;
    troca_led();
  } 
}

void loop() {
  if(digitalRead(bnt)){
    bntclicado=1;
    bntliberado=0;
  }
  else{
    bntliberado=1;
  }
  bntestado();
}