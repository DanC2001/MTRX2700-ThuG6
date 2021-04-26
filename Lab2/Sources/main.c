#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */




#include "Module_3.h"

void main(void) {

      
    // Receive user input
    char input_string[] = "EAEAE";
    
    // Run play tune function
    play_tune(input_string, NOTE_LENGTH);

       
      	EnableInterrupts;


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */

}
