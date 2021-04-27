#include <hidef.h>      /* common defines and macros */
#include <math.h>
#include "derivative.h"      /* derivative-specific definitions */


void enableTimer(int cr1, int cr2){
   TSCR1 = cr1;  // enable timer, and fast clear
   TSCR2 = cr2;  // Prescaler=1, no timer overflow
   TFLG2 = 0x80;  // Clear the TOF flag
   TSCR2 |= 0x80; // enable TCNT overflow interrupt	       
} 

long BenchmarkII(int operator, int a, int b){
   
   volatile unsigned time1, time2;
   unsigned diff; 
   double result;
   
   switch(operator){
    case 0:                 //add
      time1 = TCNT;
      result = a + b;
      time2 = TCNT;
      break; 
    case 1:                 //subtract   
      time1 = TCNT;
      result = a - b;
      time2 = TCNT;
      break;
    case 2:                 //multiply   
      time1 = TCNT;
      result = a * b;
      time2 = TCNT;
      break;
    case 3:                 //divide   
      time1 = TCNT;
      result = a / b;
      time2 = TCNT;
      break;
    case 4:                 //sin   
      time1 = TCNT;
      result = sin(a);
      time2 = TCNT;
      break;
    case 5:                 //cos   
      time1 = TCNT;
      result = cos(a);
      time2 = TCNT;
      break;
    case 6:                 //sqrt   
      time1 = TCNT;
      result = sqrt(a);
      time2 = TCNT;
      break;  
   }
   
   diff = time2-time1;
   return diff;
}

long BenchmarkLL(int operator, long a, long b){
   
   volatile unsigned time1, time2;
   unsigned diff; 
   double result;
   
   switch(operator){
    case 0:                 //add
      time1 = TCNT;
      result = a + b;
      time2 = TCNT;
      break; 
    case 1:                 //subtract   
      time1 = TCNT;
      result = a - b;
      time2 = TCNT;
      break;
    case 2:                 //multiply   
      time1 = TCNT;
      result = a * b;
      time2 = TCNT;
      break;
    case 3:                 //divide   
      time1 = TCNT;
      result = a / b;
      time2 = TCNT;
      break;
    case 4:                 //sin   
      time1 = TCNT;
      result = sin(a);
      time2 = TCNT;
      break;
    case 5:                 //cos   
      time1 = TCNT;
      result = cos(a);
      time2 = TCNT;
      break;
    case 6:                 //sqrt   
      time1 = TCNT;
      result = sqrt(a);
      time2 = TCNT;
      break;  
   }
   
   diff = time2-time1;
   return diff;
}
long BenchmarkDD(int operator, double a, double b){
   
   volatile unsigned time1, time2;
   unsigned diff; 
   double result;
   
   switch(operator){
    case 0:                 //add
      time1 = TCNT;
      result = a + b;
      time2 = TCNT;
      break; 
    case 1:                 //subtract   
      time1 = TCNT;
      result = a - b;
      time2 = TCNT;
      break;
    case 2:                 //multiply   
      time1 = TCNT;
      result = a * b;
      time2 = TCNT;
      break;
    case 3:                 //divide   
      time1 = TCNT;
      result = a / b;
      time2 = TCNT;
      break;
    case 4:                 //sin   
      time1 = TCNT;
      result = sin(a);
      time2 = TCNT;
      break;
    case 5:                 //cos   
      time1 = TCNT;
      result = cos(a);
      time2 = TCNT;
      break;
    case 6:                 //sqrt   
      time1 = TCNT;
      result = sqrt(a);
      time2 = TCNT;
      break;  
   }
   
   diff = time2-time1;
   return diff;
}
long BenchmarkFF(int operator, float a, float b){
   
   volatile unsigned time1, time2;
   unsigned diff; 
   double result;
   
   switch(operator){
    case 0:                 //add
      time1 = TCNT;
      result = a + b;
      time2 = TCNT;
      break; 
    case 1:                 //subtract   
      time1 = TCNT;
      result = a - b;
      time2 = TCNT;
      break;
    case 2:                 //multiply   
      time1 = TCNT;
      result = a * b;
      time2 = TCNT;
      break;
    case 3:                 //divide   
      time1 = TCNT;
      result = a / b;
      time2 = TCNT;
      break;
    case 4:                 //sin   
      time1 = TCNT;
      result = sin(a);
      time2 = TCNT;
      break;
    case 5:                 //cos   
      time1 = TCNT;
      result = cos(a);
      time2 = TCNT;
      break;
    case 6:                 //sqrt   
      time1 = TCNT;
      result = sqrt(a);
      time2 = TCNT;
      break;  
   }
   
   diff = time2-time1;
   return diff;
}

void convertTimerToTime(int prescalar, unsigned timer, double* output){
   
   long Eclock = 24000000;
   volatile double perStep;
   volatile double time;
   
   switch(prescalar){
    case 0x00:
      perStep = Eclock;
      break;
    
    case 0x01:
      perStep = Eclock/2;
      break;
      
    case 0x02:
      perStep = Eclock/4;
      break;
   
    case 0x03:
      perStep = Eclock/8;
      break;
    
    case 0x04:
      perStep = Eclock/16;
      break;
   
    case 0x05:
      perStep = Eclock/32;
      break;
      
    case 0x06:
      perStep = Eclock/64;
      break;
      
    case 0x07:
      perStep = Eclock/128;
      break;
      
   }
   
   time = timer * (1/perStep);  // Seconds
   time = time*1000;            // Miliseconds  (ms)
   time = time*1000;            // Microseconds (µs)
   
   *output = time;               
}


void BenchmarkTable(double a, double b, int prescalar){
   // make array of numbers for every data type
   int i;
   long diff;
   
   double Ints[6];
   for(i=0; i<7; i++){
      diff = BenchmarkII(i,a,b);   
      convertTimerToTime(prescalar, diff, &Ints[i]);   
   }
   
   // concatenate the arrays
   // output the final array array
   
    
}