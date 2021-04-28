#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

// Header file for the speaker module corresponding to exercise 3
#include "Module_3.h"


void main(void) {
    
    
    // Define finished flag and associated pointer so know when speaker stops playing
    int finished_flag = 0;
    int* finished_flag_ptr = &finished_flag;
    
    
    // * * * * * * * * * * USER INTERFACE * * * * * * * * * * //
    
    // This interface is used to select which exercise to perform
    
    // 1 - Performs Exercise 1: Timing maths functions
    // 2 - Performs Exercise 2: Serial using interrupts
    // 3 - Performs Exercise 3: Play tune via speaker
    int exercise = 3;
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
    
    
    
    // * * * * * * * * * * SPEAKER USER INTERFACE * * * * * * * * * * //
    
    // Define the string of notes to be played on the speaker 
    // Notes are to be typed as capital letters
    // Frequencies of each note are:
    
    // A -> 1000 Hz
    // B -> 500 Hz
    // C -> 333 Hz
    // D -> 250 Hz
    // E -> 200 Hz
    
    // For example, "ABCDE" will play a descending tune
    // Each note plays for 0.5 seconds
    
    // Left hand LED displays 0 will tune in process, 1 when tune is finsihed
    // Right hand LED counts down the last 4 seconds of the tune
    // Data was intended to be displayed via serial but relied on exercise two which is still unfinished
    
    // Enter string below:
    char input_string[] = "ABDA"; 
    
    
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
    
    // Check user input and perform exercise
    if(exercise == 1){
      
      // Perform exercise 1
    }
    else if(exercise == 2){
      
      // Perform exercise 2
    } 
    else if(exercise == 3){
      
      // Display the current state of the finished flag on the first LED
      LED_display(finished_flag, 0);
      
      // Run play tune function
      play_tune(input_string, NOTE_LENGTH, finished_flag_ptr);
      
      LED_display(finished_flag, 0);
    
    }

       
      	EnableInterrupts;


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */

}
