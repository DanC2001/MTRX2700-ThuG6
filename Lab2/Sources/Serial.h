/*
 * Note: This file is recreated by the project wizard whenever the MCU is
 *       changed and should not be edited by hand
 */

/* Include the derivative-specific header file */
#include <mc9s12dg256.h>

#pragma LINK_INFO DERIVATIVE "mc9s12dg256"

void Init_SCI1 (void);

void Init_SCI0 (void);

interrupt 21 void SC1_ISR(void);

void PrintChars(int counter);

void storeChar(int counter);