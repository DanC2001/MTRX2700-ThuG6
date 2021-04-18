#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
// Include required header files
// WARNING: Remember to alter required file depending if in simulation or hardware!


void Init_SCI1 (void) {
  
SCI1BDH = 0x00;
SCI1BDL = 0x9C; // Set the baud rate as 9600
SCI1CR1 = 0x4C; // Select 8 data bits, address mark wake-up
SCI1CR2 = 0xAC; // Enable transmitter, receiver, receiver full interrupt enable bit
 
}

void Init_SCI0 (void) {
  
SCI0BDH = 0x00;
SCI0BDL = 0x9C; // Set the baud rate as 9600
SCI0CR1 = 0x4C; // Select 8 data bits, address mark wake-up
SCI0CR2 = 0xAC; // Enable transmitter, receiver, receiver full interrupt enable bit
 
}


interrupt 21 void SC1_ISR(void){
  PORTB=SCI1SR1;     // debugging info
  if (SCI1SR1 & 0x20) {// Check the RDRF. If high, then store character 
     
     storeChar(counter);// Runs the storeChar function
     counter++;         // Increments the counter value by one to store in the next memory location
  } 
  else {                 // Print through the whole buffer
    
    PrintChars(counter);
    counter = 0;
  }
}

void PrintChars(int counter){

   for(i=0;i<counter;i++){
      if (i == 0){  // If first pass
         SCI1DRL = '\n'; // Print newline character
         while(!(SCI1SR1 & 0x80));
         SCI1DRL = '\r'; // Print carriage return
         while(!(SCI1SR1 & 0x80));
      }

   //transmit char to data register
   //transmit 'data received\n' to data register
   //set char in position as null
   //
}

// Add the character from SCI1DRL to a buffer, that we initialise in main (and call as a variable in this function)
 // Increament the x in buffer[x]  for next time (make sure that this is within the scope, so x+1 is stored, and not written over)
 // This function will get called by the interrupt  
 // printf "buffer[x] data received"
void storeChar(int counter){
  

    buffer[counter]= SCI1DRL;
   
}


