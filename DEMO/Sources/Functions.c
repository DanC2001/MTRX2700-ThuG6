#include <hidef.h>      /* common defines and macros */
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "derivative.h"      /* derivative-specific definitions */


void enableTimer(int cr1, int cr2){
   TSCR1 = cr1;  // enable timer, and fast clear
   TSCR2 = cr2;  // Prescaler, no timer overflow
   TFLG2 = 0x80;  // Clear the TOF flag
   TSCR2 |= 0x80; // enable TCNT overflow interrupt	       
} 


int convertTimerToTime(int prescalar, unsigned timer, float* output){
   
   long Eclock = 24000000;    // 24MHz
   volatile double perStep;
   volatile double time;
   
   // gets time value for each clock tick
   switch(prescalar){         // what is the prescaler?
    case 0x00:  //000
      perStep = Eclock;
      break;
    
    case 0x01:  //001
      perStep = Eclock/2;
      break;
      
    case 0x02:  //010
      perStep = Eclock/4;
      break;
   
    case 0x03:  //011
      perStep = Eclock/8;
      break;
    
    case 0x04:  //100
      perStep = Eclock/16;
      break;
   
    case 0x05:  //101
      perStep = Eclock/32;
      break;
      
    case 0x06:  //110
      perStep = Eclock/64;
      break;
      
    case 0x07:  //111
      perStep = Eclock/128;
      break;
      
   }
   
   time = timer * (1/perStep);  // Seconds
   time = time*1000;            // Miliseconds  (ms)
   time = time*1000;            // Microseconds (µs)
   
   *output = time;
   return 1;               
}


void BenchmarkTable(double da, double db, int prescalar){
   //~~~~~~~~~~~~~ Variable Definition ~~~~~~~~~~~~~//
   volatile unsigned time1; // Variables to track time
   volatile unsigned time2;
   unsigned diff;
   
   int i, cols = 0, row =0; // Ints for program tracking
   int ia = (int)da, ib = (int)db; // Ints for testing
   long la = (long)da, lb = (long)db; // longs for testing
   float fa = (float)da, fb = (float)db; // floats for testing
   
   
   // variable to store test results (must be voltile for optimizer to run operations
   volatile int result; 
   
   //~~~ Strings in the stack ~~~//
   // String to store cells
   char str[10];
   const char delim[2] = " ";
   char* ptr;
   
   //Table Headers (note length is strlen +1 for use with strtok)
   char header[31] = "us Add Sub Mul Div Sin Cos Sqr";  
   char colHeader[16] = "Int Lng Flt Dub";
   
   //~~~ Strings in the heap ~~~//
   char* data   = (char*)malloc(300 * sizeof(char));
   float* output = (float*)malloc(28 * sizeof(float));
   char* Table   = (char*)malloc(400 * sizeof(char));
                                                        
   /*~~~~~~~~~~~~~~~~~~~~Benchmarking~~~~~~~~~~~~~~~~~~~~*/
   
   
   //~~~~~~~~~~~~~~~~~~~~~~INTEGERS~~~~~~~~~~~~~~~~~~~~~~//
   time1 = TCNT;
   result = ia + ib;                            // Add
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[0]);
   
   time1 = TCNT;
   result = ia - ib;                            // Subtract   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[1]);
   
   time1 = TCNT;
   result = ia * ib;                            // Multiply   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[2]);
   
   time1 = TCNT;
   result = ia / ib;                            // Divide   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[3]);
   
   time1 = TCNT;
   result = sin(ia);                            // Sin   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[4]);
   
   time1 = TCNT;
   result = cos(ia);                            // Cos   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[5]);
   
   
   time1 = TCNT;
   result = sqrt(ia);                           // Sqrt   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[6]);
   
   //~~~~~~~~~~~~~~~~~~~~~~~~LONG~~~~~~~~~~~~~~~~~~~~~~~~//
   time1 = TCNT;
   result = la + lb;                            // Add   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[7]);
   
   time1 = TCNT;
   result = la - lb;                            // Subtract   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[8]);
   
   time1 = TCNT;
   result = la * lb;                            // Multiply   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[9]);
   
   time1 = TCNT;
   result = la / lb;                            // Divide   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[10]);
   
   time1 = TCNT;
   result = sin(la);                            // Sin   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[11]);
   
   time1 = TCNT;
   result = cos(la);                            // Cos   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[12]);
   
   time1 = TCNT;
   result = sqrt(la);                           // Sqrt   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[13]);
   
   
   //~~~~~~~~~~~~~~~~~~~~~~~FLOAT~~~~~~~~~~~~~~~~~~~~~~~~//
   time1 = TCNT;
   result = fa + fb;                            // Add   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[14]);
   
   time1 = TCNT;
   result = fa - fb;                            // Subtract   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[15]);
   
   time1 = TCNT;
   result = fa * fb;                            // Multiply   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[16]);
   
   time1 = TCNT;
   result = fa / fb;                            // Divide   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[17]);
   
   time1 = TCNT;
   result = sin(fa);                            // Sin   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[18]);
   
   time1 = TCNT;
   result = cos(fa);                            // Cos   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[19]);
   
   time1 = TCNT;
   result = sqrt(fa);                           // Sqrt   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[20]);
   
   
   //~~~~~~~~~~~~~~~~~~~~~~~DOUBLE~~~~~~~~~~~~~~~~~~~~~~~//
   time1 = TCNT;
   result = da + db;                            // Add   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[21]);
   
   time1 = TCNT;
   result = da - db;                            // Subtract   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[22]);
   
   time1 = TCNT;
   result = da * db;                            // Multiply   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[23]);
   
   time1 = TCNT;
   result = da / db;                            // Divide   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[24]);
   
   time1 = TCNT;
   result = sin(da);                            // Sin   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[25]);
   
   time1 = TCNT;
   result = cos(da);                            // Cos   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[26]);
   
   time1 = TCNT;
   result = sqrt(da);                           // Sqrt   
   time2 = TCNT;
   diff = time2-time1;
   convertTimerToTime(prescalar, diff, &output[27]);
   
   /*~~~~~~~~~~~~~~~~~ Data Processing ~~~~~~~~~~~~~~~~~~*/
   // For every datapoint
   for(i=0;i<=27;i++){
      // convert into 2dp numbers with 8 padding (cell size)
      sprintf(&str,"%8.2f", output[i]);
      // Concatenate to large string of data
      strcat(data,str); 
   }
   free(output);  // free memory allocated to output as it is no longer used.
   
   /*~~~~~~~~~~~~~~~~~~~ Table Making ~~~~~~~~~~~~~~~~~~~*/
   //// set the header for the table
   ptr = strtok(header, delim);  //get first cell of table header
   
   //while token not null   (null when out of headers)
   while(ptr != NULL){           
      sprintf(&str, "%8s",ptr);  //add spacing for table  (size of cell is 8 char)
      strcat(Table,str);         //add to table string    
      ptr = strtok(NULL, delim); //get next cell
      cols++;                    //kep track of number of columns
   }
   
   strcat(Table,"\n");           //add a newline for next row
   
   ptr = strtok(colHeader, delim); // get next rows heading cell
   
   //while token not null   (null when out of headers)
   while(ptr!= NULL){            
      sprintf(&str, "%8s",ptr);  //add spacing for table (size of cell is 8 char)
      strcat(Table,str);         //add to table string
      // add row of data to table string 
      // (Table string, (data pointer + 1 + (row * data entries per row * 8 width)), characters per row)
      strncat(Table, (data + 1 + (row*(cols-1)*8)), 8*cols-1);
      row++;                     // keep track of the rows
      strcat(Table,"\n");        // add newline
      ptr = strtok(NULL, delim); // get next rows heading cell
   }
   strcat(Table,"\n");           // add newline for proceeding data 
   
   
   /*~~~~~~~~~~~~~~~~~~~ Serial output ~~~~~~~~~~~~~~~~~~~*/
   
   // note for when implementing to main codeset STACK MUT BE ENLARGED works with 500
   // do this in the linker files at the bottom of Project.prm
   
   
   
   // This is the main.c from my personal project this should be implemented into the module1.c or overaching main
   /* #include <hidef.h>      // common defines and macros 
      #include <math.h>
      #include <string.h>
      #include <stdio.h>
      #include "derivative.h"      // derivative-specific definitions 

      unsigned diff1, diff2, time1, time2;
      volatile double timetotal;
      unsigned overflow = 0;
      int prescalar = 0x00;

      void main(void) 
      {
         
         double test  = 4.2;
         double test2 = 5.5;
         double result;
         
         	
         enableTimer(0x90, prescalar);
         BenchmarkTable(test, test2, prescalar);
         
            
      while(1){
      }*/
}
}