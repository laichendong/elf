#include <stdio.h>

float convertToCelsius(int fahr);

int main(){
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = convertToCelsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    
}

float convertToCelsius(int fahr){
    return (5.0/9.0) * (fahr - 32.0);
}