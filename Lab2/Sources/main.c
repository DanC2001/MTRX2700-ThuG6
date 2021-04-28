#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
<<<<<<< HEAD
=======
#include "Module_1.h"
#include "Functions.h"
// Include required header files
// WARNING: Remember to alter required file depending if in simulation or hardware!
>>>>>>> 904abb6bc4ada818563fdaf663548a853320374a




#include "Module_3.h"

void main(void) {
<<<<<<< HEAD

      
    // Receive user input
    char input_string[] = "EAEAE";
    
    // Run play tune function
    play_tune(input_string, NOTE_LENGTH);

       
      	EnableInterrupts;
=======
  /* put your own code here */
  
   // Use flag to select with exercise to do
  module1();
>>>>>>> 904abb6bc4ada818563fdaf663548a853320374a


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */

}
