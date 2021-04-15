#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
// Include required header files
// WARNING: Remember to alter required file depending if in simulation or hardware!


void main(void) {
  /* put your own code here */
  
   // Use flag to select with exercise to do

	EnableInterrupts;


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
