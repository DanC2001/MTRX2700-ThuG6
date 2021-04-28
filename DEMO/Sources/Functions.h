#ifndef FUNCTIONS_HEADER
#define FUNCTIONS_HEADER

void enableTimer(int cr1, int cr2);
int convertTimerToTime(int prescalar, unsigned timer, float* output);
void BenchmarkTable(double a, double b, int prescalar);
#endif