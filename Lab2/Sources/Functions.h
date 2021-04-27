#ifndef FUNCTIONS_HEADER
#define FUNCTIONS_HEADER

void enableTimer(int cr1, int cr2);
long BenchmarkII(int operator, int a, int b);
void convertTimerToTime(int prescalar, unsigned timer, double* output);
long BenchmarkLL(int operator, long a, long b);
long BenchmarkDD(int operator, double a, double b);
long BenchmarkFF(int operator, float a, float b);

void BenchmarkTable(double a, double b, int prescalar);

/*long BenchmarkIL(int operator, int a, long b);
long BenchmarkIF(int operator, int a, float b);
long BenchmarkID(int operator, int a, double b);
long BenchmarkLF(int operator, long a, float b);
long BenchmarkLD(int operator, long a, double b);
long BenchmarkDF(int operator, double a, float b);
    */


#endif