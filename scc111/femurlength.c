#include <stdio.h>

int main ()
{
    float femurLength = 0.0;
    float tibiaLength = 0.0;
    scanf("%f", &femurLength);
    scanf("%f", &tibiaLength);

    printf("Femur length = %.2f\n", femurLength);
    printf("Tibia length = %.2f\n", tibiaLength);

    printf("\n");
    printf("Estimates based on Femur\n");
    printf("Height Upper = %.2f\n", (2.38 * femurLength) + 61.41 + 3.27);
    printf("Height Lower = %.2f\n", (2.38 * femurLength) + 61.41 - 3.27);
    
    printf("\n");
    printf("Estimates based on Tibia\n");
    printf("Height Upper = %.2f\n", (2.52 * tibiaLength) + 78.62 + 3.37);
    printf("Height Lower = %.2f\n", (2.38 * tibiaLength) + 78.62 - 3.37);
}