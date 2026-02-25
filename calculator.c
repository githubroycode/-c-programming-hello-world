#include <stdio.h>

int main() {
    int choice;
    double num1, num2, result;

    printf("==== Simple Calculator ====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");

    if (scanf("%d", &choice) != 1) {
        printf("Error! Invalid input.\n");
        return 1;
    }

    printf("Enter first number: ");
    if (scanf("%lf", &num1) != 1) {
        printf("Error! Invalid number.\n");
        return 1;
    }

    printf("Enter second number: ");
    if (scanf("%lf", &num2) != 1) {
        printf("Error! Invalid number.\n");
        return 1;
    }

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("Result = %.2lf\n", result);
            break;

        case 2:
            result = num1 - num2;
            printf("Result = %.2lf\n", result);
            break;

        case 3:
            result = num1 * num2;
            printf("Result = %.2lf\n", result);
            break;

        case 4:
            if (num2 != 0.0) {
                result = num1 / num2;
                printf("Result = %.2lf\n", result);
            } else {
                printf("Error! Division by zero is not allowed.\n");
            }
            break;

        default:
            printf("Invalid choice! Please enter a number between 1 and 4.\n");
    }

    return 0;
}

