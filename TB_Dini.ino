


volatile int TURBINE;      //pengukuran SINYAL data yang bersifat incremental
volatile int TURBINE2;      //pengukuran SINYAL data yang bersifat incremental
volatile int TURBINE3;
volatile int TURBINE4;

byte sensorInterrupt = 3;  // 0 = digital pin 20
byte HSensor= 2;
byte sensorInterrupt1 = 5;  // 1 = digital pin 18
byte HSensor2= 2;
byte sensorInterrupt2 = 2; // 3 = digital pin 21
byte HSensor3=2 ;
byte sensorInterrupt3 =4 ; // 4 = digital pin 19
byte HSensor4= 2;
int Calc;
int Calc2;
int Calc3;
int Calc4;
String kirim = "";
String kirim2 = "";


void speedrpm ()    //fungsi penghitungan dan interrupt
{
  TURBINE++; //bersifat incrementing (dengan mode falling edge)
  
}
void speedrpm2 ()    //fungsi penghitungan dan interrupt
{
  TURBINE2++; //bersifat incrementing (dengan mode falling edge)
  
}
void speedrpm3 ()    //fungsi penghitungan dan interrupt
{
TURBINE3++; //bersifat incrementing (dengan mode falling edge)
  
}
void speedrpm4 ()    //fungsi penghitungan dan interrupt
{
TURBINE4++; //bersifat incrementing (dengan mode falling edge)
  
}



void setup()
{
   pinMode(HSensor, INPUT);
  digitalWrite(HSensor, HIGH);
  pinMode(HSensor2, INPUT);
  digitalWrite(HSensor2, HIGH);
  pinMode(HSensor3, INPUT);
  digitalWrite(HSensor3, HIGH);
  pinMode(HSensor4, INPUT);
  digitalWrite(HSensor4, HIGH);
  
  
  Serial.begin(9600);
  
  attachInterrupt(sensorInterrupt, speedrpm, RISING); //cara penulisan perintah interrupt
  attachInterrupt(sensorInterrupt1, speedrpm2, RISING); //cara penulisan perintah interrupt
  attachInterrupt(sensorInterrupt2, speedrpm3, RISING); //cara penulisan perintah interrupt
   attachInterrupt(sensorInterrupt3, speedrpm4, RISING); //cara penulisan perintah interrupt

 
  
}

void loop ()
{
  TURBINE = 00; //data awal  = 0
  TURBINE2 = 00; //data awal = 0
  TURBINE3 = 00;
  TURBINE4 =00;
  sei(); //perintah aktifnya mode interrupt
  delay (500); //nilai delay 1 detik
  cli(); //perintah untuk matinya program interrupt
  Calc = (TURBINE * 60 / 7.5); //Pulsa * 60 / 7.5
  Calc2 = (TURBINE2 * 60 / 7.5); //Pulsa * 60 / 7.5
  Calc3 = (TURBINE3 * 60 / 7.5) ;
    Calc4 = (TURBINE4 * 60 / 7.5) ;


  //satuan FLOW RATE benda cair yaitu L / hour
  

   kirim = ";";
  kirim += Calc;
  kirim += ";";
  kirim += Calc2;
   
   kirim2 = ";";
  kirim2 += Calc3;
  kirim2 += ";";
  kirim2 += Calc4;

  Serial.print(kirim);
  Serial.print(kirim2);
  Serial.print("\n");
  
  
 
  
 
}
