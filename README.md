# MTRX2700-ThuG6

MTRX 2700 S1 2021 Lab 2 Thursday 9am Group 6 Repo

**Group Members**
Daniel Cook : 490394414
Andy Scott : 500443844
James Cal: 480368784


**Summary**
This project is broken into three main exercises. The first module times the result of performing a variety of math operations
using different data types and sends the information in a table format to serial. The second module implements the serial
transmitting and receiving using interrupts. The third module plays a tune inputted by the user on the speaker. Each exercise
was written in C and implemented on the HCS12 Dragonboard.

**Timer module**
***Functions***

** Serial module **


** Speaker module **

* Functions*
1. Play tune function
	- Primary function which generates the square wave and sends it to the speaker
	- Inputs: A pointer to the string containing notes, the length of each note, a pointer to the finished flag
	- Outputs: Void

2. Milsec delay function
	- This function creates a delay for a specified number of milliseconds to create a square wave at certain frequency
	- Inputs: An integer number of milliseconds to delay for
	- Outputs: Void

3. Notes to period function
	- Converts a string of note values in letter form, to a corresponding period in ms
	- Inputs: Pointer to output array where result is stored, pointer to input string, integer length of the string
	- Outputs: Void

4. LED display function
	- This function displays the state of the finished flag to the first 7-seg display
	- A 1 indicates finished, a 0 indicates that a song is in progress
	- Inputs: An integer representing number to be displayed, an integer corresponding to which 7-seg to use

* User instructions *
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

* Testing plan *
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





