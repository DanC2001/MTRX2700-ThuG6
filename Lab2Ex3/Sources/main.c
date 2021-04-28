#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Module_3.h"

// These definitions are generally set but could be changed by the user if desired for specific purpose
// For general functioning of the speaker alteration is not required though

//#define MAX_NOTES 100 /* Defines the maximum number of notes per tune */

//#define NOTE_LENGTH 1000 /* Defines the length in milliseconds that each note will be played for */

//void LED_display(int digit, int LED_number);
//void milsec_delay(unsigned int);
//void notes_to_period(int *output_array, char *input_string, int length);
//void play_tune(char input_string[], int note_duration, int* finished_flag_ptr);

void main(void) {
    
    
    // Define finished flag
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
    
    // Check user input and perform c
    
    // Display the current state of the finished flag on the first LED
    LED_display(finished_flag, 0);
    
    // Run play tune function
    play_tune(input_string, NOTE_LENGTH, finished_flag_ptr);
    
    LED_display(finished_flag, 0);

       
      	EnableInterrupts;


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */

}
