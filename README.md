# 🌀 Spiral Scanner

This program performs a 3D spiral scan. The calculated x, y, and z coordinates are saved in the SpiralScan.txt file. It can be used for radar simulations or other applications requiring spiral scanning coordinates. 




```c

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


```

# How to use
1. Compile the program:
2. Run the program:
   
Enter the requested parameters when prompted:
   
```
Azimuth Center: 0.0
Elevation Center: 0.0
Squint Angle: 10.0
Squint Angle Velocity (degrees/second): 2.0
Period (seconds): 0.1
PRI (seconds): 0.0001
```
After execution, check the file SpiralScan.txt for the generated coordinates.

# Example Output

0.0000000000, 0.0000000000, 0.0000000000

0.0000000000, 0.0012565378, 0.0000157910

...

0.0000000000, 1.2537277197, -0.0315162684

0.0000000000, 1.2552813032, -0.0157751785




