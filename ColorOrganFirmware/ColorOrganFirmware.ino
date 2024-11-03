#include <SparkFun_Tlc5940.h>
 
#define STROBE 4
#define RESET 5
#define DC_Left A0
#define DC_Right A1

int freq_amp = 0;
int Frequencies_Left[7];
int Frequencies_Right[7];

void setup() {
  Serial.begin(115200);
  Serial.println("RESET!!!");
 
  //init PWM
  Tlc.init(0);
 
  //Set Spectrum Shield pin configurations
  pinMode(STROBE, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DC_Left, INPUT);
  pinMode(DC_Right, INPUT); 
  digitalWrite(STROBE, HIGH);
  digitalWrite(RESET, HIGH);
 
  //Initialize Spectrum Analyzers
  digitalWrite(STROBE, LOW);
  delay(1);
  digitalWrite(RESET, HIGH);
  delay(1);
  digitalWrite(STROBE, HIGH);
  delay(1);
  digitalWrite(STROBE, LOW);
  delay(1);
  digitalWrite(RESET, LOW);

  for(int iter = 0; iter < 20; iter++)
  {
    for (freq_amp = 0; freq_amp<7; freq_amp++)
    {
      analogRead(DC_Left);//must be here or you get jitter in first analog input read
      //Serial.print(String(analogRead(DC_Left)*input_gain)+"\t");
      //Serial.print(String(analogRead(DC_Right)*input_gain)+"\t");
   
      digitalWrite(STROBE, HIGH);
      digitalWrite(STROBE, LOW);
     }
     //Serial.println();  
  }
}
 
void loop() {
  Read_Frequencies();
  Set_Leds();
}
 
void Read_Frequencies(){
  //Read frequencies for each band
  
  for (freq_amp = 0; freq_amp<7; freq_amp++)
  {
    analogRead(DC_Left);//must be here or you get jitter in first analog input read
    
    Frequencies_Left[freq_amp] = analogRead(DC_Left)*1.08;
   
    digitalWrite(STROBE, HIGH);
    digitalWrite(STROBE, LOW);
  }

  for (freq_amp = 0; freq_amp<7; freq_amp++)
  {
    analogRead(DC_Right);//must be here or you get jitter in first analog input read
     
    Frequencies_Right[freq_amp] = analogRead(DC_Right)*1.08;
   
    digitalWrite(STROBE, HIGH);
    digitalWrite(STROBE, LOW);
  }
}
 
void Set_Leds(){
  Tlc.clear();

  int value=0;
  int output_value=0;

  for(int i = 0; i <= 13; i++){
    //run through logarithmic filter
    
    //set value from left or right array
    if(i <= 6)
    {
      value = Frequencies_Right[i];
    }
    else if(i >= 7)
    {
      value = Frequencies_Left[i-7];
    }
    else
    {
      //do nothing
    } 
    //output_value=4*pow (2.71828, (value/123.2));
    //output_value=(pow (2.71828, (value/275))/.01)-100;
    if(value > 118){
      output_value = 1.6*value;
    } else {
      output_value = 0;
    }
    //Serial.println("output value is: "+String(output_value)+" and value is: "+String(value));
    set_led(i, output_value);  

    //Serial.println("PWM channel: "+String(i));
    //Serial.println("inputvalue: "+String(value));
    //Serial.println("outputvalue: "+String(output_value));
  }

  Tlc.update();
}
 
int set_led(int pwm_channel, int output_value)
{
    if(output_value < 2){
      output_value=0;
    }

    //    int scale_factor = 1.5;
    //    if(pwm_channel == 0 || pwm_channel == 7){
    //      scale_factor = 2;
    //    }

    Tlc.set(pwm_channel,output_value);  //was times scale factor computed above
}
