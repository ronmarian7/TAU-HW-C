#include <stdio.h>

void avgOut(double avg) {
    printf("The average is: %.3f\n", avg);
}

void sneezeOut() {
    printf("You sneeze more than you cough\n");
}

void coughOut() {
    printf("You cough more than you sneeze\n");
}

void callMda() {
    printf("Call MDA!\n");
}

void dontCallMda() {
    printf("Don't call MDA!\n");
}

int main() {
    printf("Please enter three whole numbers:\n");
    double coughs = 0.0, sneezes = 0.0, age = 0.0, avg = 0.0;
    scanf_s("%lf %lf %lf", &coughs, &sneezes, &age);
    avg = (coughs + sneezes + age)/3;
    avgOut(avg);
    if (coughs > sneezes)
        coughOut();
    else if (sneezes > coughs)
        sneezeOut();

    if (avg > 40)
        callMda();
    else
        dontCallMda();

    return 0;
}
