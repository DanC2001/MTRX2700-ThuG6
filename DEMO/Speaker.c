#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Module_3.h"

// This module runs exercise 3 which plays a tune using the speaker
void play_tune(char *input_string, int note_duration, int* finished_flag_ptr){

      
    // Initialise variables
    unsigned int array_index = 0;
    unsigned int delay_index = 0;
    unsigned int no_loops;

    // Set finished flag to 0 to indicate tune is playing
    // Volatile necessary as compiler was optimising out this flag
    volatile int finished_flag = 0;

    // Define the length of the string
    int length = strlen(input_string);
    
    // Keep track of time left in the program in seconds
    int time_left = note_duration*length/1000;
    
    // Define output array of periods
    int period_array[MAX_NOTES];
    
    // Convert note values to period
    notes_to_period(period_array, input_string, length);
    
    // Set pin 5 of port P to be output 
    DDRT |= PTT_PTT5_MASK;
    
    // Loop through each frequency to be played 
     
    for (array_index = 0; array_index < length ; array_index++){
      
       // Calculate how many loops is equal to the designated time
       no_loops = note_duration/(2*period_array[array_index]);
          
       // Play each note for designated time
       for(delay_index = 0; delay_index <  no_loops; delay_index++){
        
        // Set speaker port to low and pause 
        PTT_PTT5 = 0;
        milsec_delay(period_array[array_index]);
        
        // Set speaker port to high and pause
        PTT_PTT5 = 1;    
        milsec_delay(period_array[array_index]);
       }
       
        // Switch to fourth LED to display time remaining
       PTP = 55;
       
       // Once note has been played, update the amount of time remaining in seconds
       time_left = time_left - note_duration/1000;
       
       // Count down last 4 seconds to 7-seg display
       if(time_left >= 4){
        PORTB = 102;  // Displays 4
       }
       
       else if(time_left >= 3){
        PORTB = 79;   //  Displays 3
       } 
       else if(time_left >= 2){
        PORTB = 91;     // Displays 2
       } 
       else if (time_left >= 1){
         PORTB = 6;   // Displays 1
       } 
       else if (time_left >= 0){
           PORTB = 63;   // Displays 0
       }
       
    }             
    
    // Set finished flag
    *finished_flag_ptr = 1;
 
     
}


// This function creates a time delay for a specified number of milliseconds
void milsec_delay(unsigned int time_ms){

    // Define counter variables to count back from
    // Volatile helps ensure this is not optimised out by compiler
    volatile int i; 
    volatile int j;
    
    // Define length of delay required for 1 millisecond
    volatile int ms_delay = 4000;
    
    // Waste time for number of inputted milliseconds
    for(i = 0; i < time_ms ; i++) 
      for(j = 0 ; j <ms_delay ; j++);
}
  
// This function takes a string of note values and converts it to 
// their period in ms, returns a pointer to the array
void notes_to_period(int *output_array, char *input_string, int length){

    // Define variables needed
    int i = 0;
    char current_note;
    int ascii_offset = 64;

    // Loop through input array
    for(i = 0; i < length; i++){

        // Define current note
        current_note = input_string[i];

        // Subtract ascii offset, for capital letters subtracting 64 gives A = 1,
        // B = 2, C = 3, D = 4, E = 5
        current_note = current_note - ascii_offset;

        // Save current_note in the output array
        output_array[i] = current_note; 

    } 

} 


// This function displays a specified digit to a single 7 seg display based on which 7-seg number is specified
void LED_display(int digit, int LED_number){

  // Define array of values that display digits 0-9 on LED
  int numbers[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};
  
  
  // Define array of values which can select which LED to display on
  int LED_configure[] = {62, 61, 59, 55};
  
  // Define number to display
  int display_num = numbers[digit];
  
  // Define LED to display on
  int display_LED = LED_configure[LED_number];
  
  // Configure PORTB as output
  DDRB = 0xFF;
  
  // Configure PORTP as output        
  DDRP = 0xFF;
  
  // Write the value to be displayed to port B
  PORTB = display_num;
  
  // Write the value of which LED is activated to port P
  PTP = display_LED; 
  
  
}
  





