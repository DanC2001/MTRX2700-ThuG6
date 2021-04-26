/*
 * Note: This file is recreated by the project wizard whenever the MCU is
 *       changed and should not be edited by hand
 */

/* Include the derivative-specific header file */
#include <mc9s12dg256.h>

#pragma LINK_INFO DERIVATIVE "mc9s12dg256"

//#ifndef MODULE_3.h
//#define MODULE_3.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// These definitions are generally set but could be changed by the user if desired for specific purpose
// For general functioning of the speaker alteration is not required though

#define MAX_NOTES 100 /* Defines the maximum number of notes per tune */

#define NOTE_LENGTH 500 /* Defines the length in milliseconds that each note will be played for */



void milsec_delay(unsigned int);
void notes_to_period(int *output_array, char *input_string, int length);
void play_tune(char input_string[], int note_duration);

//#endif
