// Temperature Converter in C
#include <stdio.h>

float celsiusToFahrenheit(float c) { return (c * 9.0 / 5.0) + 32; }
float celsiusToKelvin(float c)     { return c + 273.15; }
float fahrenheitToCelsius(float f) { return (f - 32) * 5.0 / 9.0; }
float fahrenheitToKelvin(float f)  { return (f - 32) * 5.0 / 9.0 + 273.15; }
float kelvinToCelsius(float k)     { return k - 273.15; }
float kelvinToFahrenheit(float k)  { return (k - 273.15) * 9.0 / 5.0 + 32; }

int main() {
    int choice;
    float temp;

    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit & Kelvin\n");
    printf("2. Fahrenheit to Celsius & Kelvin\n");
    printf("3. Kelvin to Celsius & Fahrenheit\n");
    printf("Choice: ");
    scanf("%d", &choice);
    printf("Enter temperature: ");
    scanf("%f", &temp);

    switch (choice) {
        case 1:
            printf("%.2f°C = %.2f°F = %.2fK\n",
                temp, celsiusToFahrenheit(temp), celsiusToKelvin(temp));
            break;
        case 2:
            printf("%.2f°F = %.2f°C = %.2fK\n",
                temp, fahrenheitToCelsius(temp), fahrenheitToKelvin(temp));
            break;
        case 3:
            printf("%.2fK = %.2f°C = %.2f°F\n",
                temp, kelvinToCelsius(temp), kelvinToFahrenheit(temp));
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}
