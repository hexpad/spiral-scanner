#include <stdio.h>
#include <math.h>
#include <unistd.h> // usleep function

#define PI 3.14159265

// Function that calculates the x, y, and z coordinates of the spiral
void archemedesSpiral(double t, double *x, double *y, double *z, double squintAng, double squintVel, double a, double b) {
    *x = 0; 
    *y = a * t * cos(t) * b;
    *z = a * t * sin(t) * b;
}

int main() {
    FILE *file;
    file = fopen("SpiralScan.txt", "w"); 

    if (file == NULL) {
        printf("File opening error!\n");
        return 1;
    }

    double t, x, y, z;
    double a = 0.1;
    double b = 1;
    double aziCenter, eleCenter, squintAng, squintVel, prd, priTime;

    printf("Azimuth Center: ");
    scanf("%lf", &aziCenter);

    printf("Elevation Center: ");
    scanf("%lf", &eleCenter);

    printf("Squint Angle: ");
    scanf("%lf", &squintAng);

    printf("Squint Angle Velocity (degrees/second): ");
    scanf("%lf", &squintVel);

    printf("Period (in seconds): ");
    scanf("%lf", &prd);

    printf("PRI (in seconds): ");
    scanf("%lf", &priTime);

    double steps = prd / priTime;
    for (t = 0; t <= 4 * PI; t += (4 * PI) / steps) {
        double squint = squintAng + squintVel * t; 

        archemedesSpiral(t, &x, &y, &z, squint, squintVel, a, b); 
        fprintf(file, "%.10f, %.10f, %.10f\n", aziCenter + x, eleCenter + y, z); 

        usleep(priTime * 1000000); 
    }

    fclose(file); 

    printf("Spiral scan coordinates successfully written to file.\n");

    return 0;
}

