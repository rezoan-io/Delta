#include <stdio.h>
#include <math.h>

/*
 * CSE261 Group Assignment
 * Topic: Implementation and Comparison of Simpson's and Trapezoidal Rules
 * Language: C
 *
 * --- How to Compile and Run ---
 * 1. Save the code as 'integration_comparison.c'
 * 2. Compile: gcc integration_comparison.c -o integration_comparison -lm
 * 3. Run: ./integration_comparison
 *
 * This program calculates the definite integrals of:
 *   (1) sin(x) from 0 to π
 *   (2) ln(x) from 1 to 2
 * using the Trapezoidal Rule and Simpson's Rule,
 * then compares the results with their exact values.
 */
// Function prototypes
double trapezoidal_rule(double (*f)(double), double a, double b, int n);
double simpsons_rule(double (*f)(double), double a, double b, int n);

// Functions to integrate
double f1(double x) { return sin(x); }   // f1(x) = sin(x)
double f2(double x) { return log(x); }   // f2(x) = ln(x)
int main() {
    int n; // Number of subintervals
    double a1 = 0.0, b1 = M_PI;       // Integration limits for sin(x)
    double a2 = 1.0, b2 = 2.0;        // Integration limits for ln(x)
    double exact1 = 2.0;              // Exact value for ∫0 to π sin(x) dx
    double exact2 = 2 * log(2) - 1;   // Exact value for ∫1 to 2 ln(x) dx

    printf("Enter number of intervals (n): ");
    scanf("%d", &n);

    // Simpson's rule requires an even number of subintervals
    if (n % 2 != 0) {
        printf("Simpson's rule requires even n, so using n+1.\n");
        n++;
    }
    // Compute integrals using both methods
    double trap1 = trapezoidal_rule(f1, a1, b1, n);
    double simp1 = simpsons_rule(f1, a1, b1, n);

    double trap2 = trapezoidal_rule(f2, a2, b2, n);
    double simp2 = simpsons_rule(f2, a2, b2, n);

    // Calculate percentage errors
    double error_trap1 = fabs(trap1 - exact1) / exact1 * 100.0;
    double error_simp1 = fabs(simp1 - exact1) / exact1 * 100.0;
    double error_trap2 = fabs(trap2 - exact2) / exact2 * 100.0;
    double error_simp2 = fabs(simp2 - exact2) / exact2 * 100.0;
    // Display results
    printf("\n--- Numerical Integration Results ---\n");

    printf("\n1) Integral of sin(x) from 0 to π:\n");
    printf("   • Trapezoidal Rule Result = %.8lf | Error %% = %.6lf%%\n", trap1, error_trap1);
    printf("   • Simpson's Rule Result  = %.8lf | Error %% = %.6lf%%\n", simp1, error_simp1);

    printf("\n2) Integral of ln(x) from 1 to 2:\n");
    printf("   • Trapezoidal Rule Result = %.8lf | Error %% = %.6lf%%\n", trap2, error_trap2);
    printf("   • Simpson's Rule Result  = %.8lf | Error %% = %.6lf%%\n", simp2, error_simp2);

    return 0;
}
/*
 * trapezoidal_rule
 * ----------------
 * Approximates the integral of a function f(x) from a to b
 * using the composite Trapezoidal Rule with n subintervals.
 */
double trapezoidal_rule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }
    return (h / 2.0) * sum;
}
/*
 * simpsons_rule
 * -------------
 * Approximates the integral of a function f(x) from a to b
 * using the composite Simpson's Rule with n subintervals (n must be even).
 */
double simpsons_rule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 4 * f(a + i * h);
    }
    return (h / 3.0) * sum;
}