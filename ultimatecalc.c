#include <stdio.h>
#include <math.h>

// Define PI for degree-to-radian conversion
#define PI 3.14159265358979323846

void handleArithmetic() {
    int choice;
    printf("\n--- Arithmetic Menu ---\n");
    printf("1. Addition (2 Integers)\n");
    printf("2. Subtraction (2 Integers)\n");
    printf("3. Multiplication (2 Integers)\n");
    printf("4. Division (2 Integers, Integer Output)\n");
    printf("5. Division (2 Floating-point Numbers)\n");
    printf("6. Remainder (2 Integers)\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    // Variables for inputs
    int int1, int2, intResult;
    double float1, float2, floatResult;

    switch(choice) {
        case 1:
            printf("Enter 1st integer: ");
            scanf("%d", &int1);
            printf("Enter 2nd integer: ");
            scanf("%d", &int2);
            intResult = int1 + int2;
            printf("Result: %d\n", intResult);
            break;
        case 2:
            printf("Enter 1st integer: ");
            scanf("%d", &int1);
            printf("Enter 2nd integer: ");
            scanf("%d", &int2);
            intResult = int1 - int2;
            printf("Result: %d\n", intResult);
            break;
        case 3:
            printf("Enter 1st integer: ");
            scanf("%d", &int1);
            printf("Enter 2nd integer: ");
            scanf("%d", &int2);
            intResult = int1 * int2;
            printf("Result: %d\n", intResult);
            break;
        case 4:
            printf("Enter 1st integer: ");
            scanf("%d", &int1);
            printf("Enter 2nd integer: ");
            scanf("%d", &int2);
            if(int2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                intResult = int1 / int2;
                printf("Result: %d\n", intResult);
            }
            break;
        case 5:
            printf("Enter 1st floating-point number: ");
            scanf("%lf", &float1);
            printf("Enter 2nd floating-point number: ");
            scanf("%lf", &float2);
            if(float2 == 0.0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                floatResult = float1 / float2;
                printf("Result: %lf\n", floatResult);
            }
            break;
        case 6:
            printf("Enter 1st integer: ");
            scanf("%d", &int1);
            printf("Enter 2nd integer: ");
            scanf("%d", &int2);
            if(int2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                intResult = int1 % int2;
                printf("Result: %d\n", intResult);
            }
            break;
        default:
            printf("Invalid arithmetic choice!\n");
    }
}

void handleTrigonometric() {
    int choice;
    printf("\n--- Trigonometric Menu ---\n");
    printf("1. Sin\n2. Cos\n3. Tan\n4. Cot\n5. Sec\n6. Cosec\n");
    printf("7. Arcsin\n8. Arccos\n9. Arctan\n10. Arccot\n11. Arcsec\n12. Arccosec\n");
    printf("Enter your choice (1-12): ");
    scanf("%d", &choice);

    double value, radians, result;

    if (choice >= 1 && choice <= 6) {
        printf("Enter the angle in degrees: ");
        scanf("%lf", &value);
        radians = value * (PI / 180.0); // Convert degrees to radians for C math functions
    } else if (choice >= 7 && choice <= 12) {
        printf("Enter the value for inverse function: ");
        scanf("%lf", &value);
    } else {
        printf("Invalid trigonometric choice!\n");
        return;
    }

    switch(choice) {
        case 1: // Sin
            printf("Result: %lf\n", sin(radians));
            break;
        case 2: // Cos
            printf("Result: %lf\n", cos(radians));
            break;
        case 3: // Tan
            if (cos(radians) == 0.0) printf("Error: Undefined (Asymptote)\n");
            else printf("Result: %lf\n", tan(radians));
            break;
        case 4: // Cot
            if (sin(radians) == 0.0) printf("Error: Undefined\n");
            else printf("Result: %lf\n", 1.0 / tan(radians));
            break;
        case 5: // Sec
            if (cos(radians) == 0.0) printf("Error: Undefined\n");
            else printf("Result: %lf\n", 1.0 / cos(radians));
            break;
        case 6: // Cosec
            if (sin(radians) == 0.0) printf("Error: Undefined\n");
            else printf("Result: %lf\n", 1.0 / sin(radians));
            break;
        case 7: // Arcsin
            if (value < -1.0 || value > 1.0) printf("Error: Domain must be between -1 and 1\n");
            else printf("Result: %lf radians (%lf degrees)\n", asin(value), asin(value) * (180.0 / PI));
            break;
        case 8: // Arccos
            if (value < -1.0 || value > 1.0) printf("Error: Domain must be between -1 and 1\n");
            else printf("Result: %lf radians (%lf degrees)\n", acos(value), acos(value) * (180.0 / PI));
            break;
        case 9: // Arctan
            printf("Result: %lf radians (%lf degrees)\n", atan(value), atan(value) * (180.0 / PI));
            break;
        case 10: // Arccot
            result = (PI / 2.0) - atan(value);
            printf("Result: %lf radians (%lf degrees)\n", result, result * (180.0 / PI));
            break;
        case 11: // Arcsec
            if (value > -1.0 && value < 1.0) printf("Error: Domain must be x <= -1 or x >= 1\n");
            else {
                result = acos(1.0 / value);
                printf("Result: %lf radians (%lf degrees)\n", result, result * (180.0 / PI));
            }
            break;
        case 12: // Arccosec
            if (value > -1.0 && value < 1.0) printf("Error: Domain must be x <= -1 or x >= 1\n");
            else {
                result = asin(1.0 / value);
                printf("Result: %lf radians (%lf degrees)\n", result, result * (180.0 / PI));
            }
            break;
    }
}

int main() {
    int mainChoice;

    printf("=== Ultimate Calculator ===\n");
    printf("1. Arithmetic Operations\n");
    printf("2. Trigonometric Operations\n");
    printf("Select operation type (1 or 2): ");
    scanf("%d", &mainChoice);

    if (mainChoice == 1) {
        handleArithmetic();
    } else if (mainChoice == 2) {
        handleTrigonometric();
    } else {
        printf("Invalid selection! Exiting program.\n");
    }

    return 0;
}

![Output of the ultimate caluclator will look like](Screenshot 2026-08-23 211723.png)



    
