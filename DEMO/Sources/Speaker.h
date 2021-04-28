#ifndef MODULE_3.h
#define MODULE_3.h

/* Include the derivative-specific header file */
#include <mc9s12dg256.h>

#pragma LINK_INFO DERIVATIVE "mc9s12dg256"

// Standard c library functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// These definitions are generally set but could be changed by the user if desired for specific purpose
// For general functioning of the speaker alteration is not required though

#define MAX_NOTES 100 /* Defines the maximum number of notes per tune */

#define NOTE_LENGTH 1000 /* Defines the length in milliseconds that each note will be played for */

// This function is used to generate a square wave at the designated frequency to the speaker on the HCS12
// It also sets the finish flag and the time left information
// The input string is a string of notes from A to E
void play_tune(char input_string[], int note_duration, int* finished_flag_ptr);


// This function takes as input a digit to be displayed and the LED to display on and displays the digit
// to the LED as well as configuring the 7-segs for output
void LED_display(int digit, int LED_number);


// This function creates a delay for the inputted number of milliseconds
// It is used to create the required delay to generate the square wave to send to the speaker
void milsec_delay(unsigned int);


// This function converts the string of note values represent as A B C D or E inputted as a string by the user
// into their corresponding periods and stores this information in an output array
void notes_to_period(int *output_array, char *input_string, int length);

#endif
