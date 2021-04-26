#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
// Include required header files
// WARNING: Remember to alter required file depending if in simulation or hardware!
#include "Module_3.h"


// This module runs exercise 3 which plays a tune using the speaker
void play_tune(char *input_string, int note_duration){

      
    // Initialise variables
    unsigned int array_index;
    unsigned int delay_index;
    unsigned int no_loops;
    
    // Set finished flag to 0 to indicate tune is playing
    // Volatile necessary as compiler was optimising out this flag
    volatile int finished_flag = 0;

    // Define the length of the string
    int length = strlen(input_string);
    
    // Keep track of time left in the program
    volatile int time_left = note_duration*length;
    
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
        
        PTT_PTT5 = 0;
        milsec_delay(period_array[array_index]);
        PTT_PTT5 = 1;    
        milsec_delay(period_array[array_index]);
       }
       
       // Once note has been played, update the amount of time remaining
       time_left = time_left - note_duration;
    }             
    
    // Set finished flag
    finished_flag = 1;
     
}


// This function creates a time delay for specified number of milliseconds

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
  



