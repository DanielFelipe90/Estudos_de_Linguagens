#include <stdio.h>
 
int main() {
    double preciseNumber = 3.141592653589793;
    long double veryPreciseNumber = 3.14159265358979323846;
 
    printf("Número preciso (double): %.15f\n", preciseNumber);
    printf("Número muito preciso (long double): %.21Lf\n", veryPreciseNumber);
    //Na documentação microsoft o long double e double são semelhantes por isso pode ser que não compile em alguns compiladores(Windows, Linux).
 
    return 0;
}