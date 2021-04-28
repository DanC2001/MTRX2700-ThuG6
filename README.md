# MTRX2700-ThuG6

*MTRX 2700 S1 2021 Lab 2 Thursday 9am Group 6 Repo*

## Group Members
Daniel Cook : 490394414 : Exercise 1
James Cal: 480368784 : Exercise 2
Andy Scott : 500443844 : Exercise 3


## Summary
This project is broken into three main exercises. The first module times the result of performing a variety of math operations
using different data types and sends the information in a table format to serial. The second module implements the serial
transmitting and receiving using interrupts. The third module plays a tune inputted by the user on the speaker. Each exercise
was written in C and implemented on the HCS12 Dragonboard.

## Timer module

### Functions
1. *Enable Timer*
	- Function that takes timer settings and initializes the timer module
	- *Inputs:* Control register 1 settings, 0x00 through 0x07 for prescalar setting
	- *Outputs:* Void
2. *convertTimerToTime*
	- Function thta will convert the timer number to a time in microseconds
	- *Inputs:* *int* Prescallar used in timer (0x00-0x07), *uint* timer value, *float ptr* pointer to float to place time value in
	- *Outputs* *int* success value, *time* output to the memory adress given by pointer through input
3. *BenchmarkTable*
	- Function that takes in testing values and the prescalar and will output a table to serial
	- *Inputs:* *double* testing value 1, *double* testing value 2 (not used for sin, cos, sqrt), *int* prescallar used when setting up timer (0x00-0x77)
	- *Outputs:* *Serial* formatted table of benchmarked times

### User Instructions
- Type in prescaller you wish to use (0x00-0x77 - NOTE: prescalar will determine precision and sensitivity lower is better) 
- Type in testing values you wish to use (NOTE: these must be of form double as they are typecast to lower forms in the function).

### Serial module


## Speaker module

### Functions
1. *Play tune function*
	- Primary function which generates the square wave and sends it to the speaker
	- *Inputs:* A pointer to the string containing notes, the length of each note, a pointer to the finished flag
	- *Outputs:* Void

2. *Milsec delay function*
	- This function creates a delay for a specified number of milliseconds to create a square wave at certain frequency
	- *Inputs:* An integer number of milliseconds to delay for
	- *Outputs:* Void

3. *Notes to period function*
	- Converts a string of note values in letter form, to a corresponding period in ms
	- *Inputs:* Pointer to output array where result is stored, pointer to input string, integer length of the string
	- *Outputs:* Void

4. *LED display function*
	- This function displays the state of the finished flag to the first 7-seg display
	- A 1 indicates finished, a 0 indicates that a song is in progress
	- *Inputs:* An integer representing number to be displayed, an integer corresponding to which 7-seg to use

### User instructions
- Type in a string of notes to be played by the speaker, the expected range of notes is A to E
- Notes should be inputted as capital letters
- Each note will give the following frequency:

	A -> 1000 Hz
	B -> 500 Hz
	C -> 333 Hz
	D -> 250 Hz
	E -> 200 Hz

- The default time each note will be played for is 0.5 seconds, if desired this can be altered at the top of the file
  where the #define is
- To play the speaker, the speaker module out of the three exercises must also be selected.

### Testing plan
1. Single letter
	- A
	- B
2. String of letters
	- ABC
	- ABCDEABCDE
3. Invalid letter
	- G
	- Z
4. Invalid strings
	- abc
	- EFGH
5. Invalid charcters
	- 123
	- !@#
6. Blank string
	- ""





