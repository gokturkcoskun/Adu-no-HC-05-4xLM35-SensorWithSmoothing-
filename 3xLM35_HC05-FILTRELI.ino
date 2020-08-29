#include <SoftwareSerial.h>
const int numReadings1 = 20;
const int numReadings2 = 20;
const int numReadings3 = 20;
const int numReadings4 = 20;

int readings1[numReadings1];       
int readIndex1 = 0; 
int total1 = 0;  
int average1 = 0;  

int readings2[numReadings2];       
int readIndex2 = 0; 
int total2 = 0;  
int average2 = 0;  

int readings3[numReadings3];       
int readIndex3= 0; 
int total3 = 0;  
int average3 = 0;  

int readings4[numReadings4];       
int readIndex4 = 0; 
int total4 = 0;  
int average4 = 0;  

int lm135 = A2;
int lm235 = A3;
int lm335 = A4;
int lm435 = A5;



SoftwareSerial mySerial(2, 3);

int okunanVoltaj1;
int read_ADC = 0;
double sicaklik1 = 0;
double sicaklik2 = 0;
double sicaklik3 = 0;
double sicaklik4 = 0;
 
void setup(){

  for (int thisReading1 = 0; thisReading1 < numReadings1; thisReading1++) {
    readings1[thisReading1] = 0;
  }
  for (int thisReading2 = 0; thisReading2 < numReadings2; thisReading2++) {
    readings2[thisReading2] = 0;
  }
  for (int thisReading3 = 0; thisReading3 < numReadings3; thisReading3++) {
    readings3[thisReading3] = 0;
  }
  for (int thisReading4 = 0; thisReading4 < numReadings4; thisReading4++) {
    readings4[thisReading4] = 0;
  }

analogReference(INTERNAL);
//pinMode(NemSensor,INPUT); 
Serial.begin(9600);
mySerial.begin(9600);
}
 
void loop(){

  while(mySerial.available()){ /* Yeni porta gelen bir mesaj var mı */
  Serial.print(mySerial.read()); /* Yeni porta gelen mesaj var ise mesaj bilgisayara yollanıyor */
    delay(10);  
   }

  total1 = total1 - readings1[readIndex1];
  readings1[readIndex1] = analogRead(lm135);
  total1 = total1 + readings1[readIndex1];
  readIndex1 = readIndex1 + 1;
  
  total2 = total2 - readings2[readIndex2];
  readings2[readIndex2] = analogRead(lm235);
  total2 = total2 + readings2[readIndex2];
  readIndex2 = readIndex2 + 1;
  
  total3 = total3- readings3[readIndex3];
  readings3[readIndex3] = analogRead(lm335);
  total3 = total3 + readings3[readIndex3];
  readIndex3 = readIndex3 + 1;
  
  total4 = total4 - readings4[readIndex4];
  readings4[readIndex4] = analogRead(lm435);
  total4 = total4 + readings4[readIndex4];
  readIndex4 = readIndex4 + 1;


  if (readIndex1 >= numReadings1) {
    readIndex1 = 0;
  }
  
  average1 = total1 / numReadings1;

  sicaklik1 = average1 / 9.31;

  if (readIndex2 >= numReadings2) {
    readIndex2 = 0;
  }
  
  average2 = total2 / numReadings2;

  sicaklik2 = average2 / 9.31;

  if (readIndex3 >= numReadings3) {
    readIndex3 = 0;
  }
  
  average3 = total3 / numReadings3;

  sicaklik3 = average3 / 9.31;

  if (readIndex4 >= numReadings4) {
    readIndex4 = 0;
  }
  
  average4 = total4 / numReadings4;

  sicaklik4 = average4 / 9.31;

  Serial.print("\n");

  Serial.print("Sıcaklık(1): ");
  Serial.println(sicaklik1);
  mySerial.print("S");
  //mySerial.print(":");
  mySerial.print(sicaklik1,0);
  // mySerial.print(":");

   Serial.print("\n");

  Serial.print("Sıcaklık(2): ");
  Serial.println(sicaklik2);
  mySerial.print("S");
  //mySerial.print(":");
  mySerial.print(sicaklik2,0);
  // mySerial.print(":");

   Serial.print("\n");

  Serial.print("Sıcaklık(3): ");
  Serial.println(sicaklik3);
  mySerial.print("S");
  //mySerial.print(":");
  mySerial.print(sicaklik3,0);
  // mySerial.print(":"); 

  Serial.print("\n");

  Serial.print("Sıcaklık(4): ");
  Serial.println(sicaklik4);
  mySerial.print("S");
  //mySerial.print(":");
  mySerial.print(sicaklik4,0);
  // mySerial.print(":"); 

  Serial.print("\n");
 
  delay(500);



}
