/* Lab 1, variant 1 (English prompts, no encoding problems in console). */
#include <stdio.h>
#include <math.h>

/* 1. 8-digit number, user chooses which digits go into the sum (0/1). No if. */
void task1(void)
{
    char n[16];
    int total = 0, flag, i;

    printf("Enter an 8-digit number: ");
    scanf("%8s", n);
    for (i = 0; i < 8; i++) {
        printf("Include digit %c (position %d) in the sum? (0/1): ", n[i], i + 1);
        scanf("%d", &flag);
        total += (n[i] - '0') * flag; /* flag 0 zeroes the digit's contribution */
    }
    printf("Sum: %d\n", total);
}

/* 2. 6-digit number: even digits -> 0, odd digits -> 1. No if. */
void task2(void)
{
    char s[16];
    int i;

    printf("Enter a 6-digit number: ");
    scanf("%6s", s);
    printf("Result: ");
    for (i = 0; i < 6; i++)
        printf("%d", (s[i] - '0') % 2);
    printf("\n");
}

/* 3. Equations of the triangle sides. */
static void line(const char *name, double x1, double y1, double x2, double y2)
{
    double a = y1 - y2;
    double b = x2 - x1;
    double c = x1 * y2 - x2 * y1;
    printf("Side %s: (%g)x + (%g)y + (%g) = 0\n", name, a, b, c);
}

void task3(void)
{
    double x[3], y[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("Vertex %c (x y separated by a space): ", 'A' + i);
        scanf("%lf %lf", &x[i], &y[i]);
    }
    line("AB", x[0], y[0], x[1], y[1]);
    line("BC", x[1], y[1], x[2], y[2]);
    line("CA", x[2], y[2], x[0], y[0]);
}

/* 4. Truth table for (!A | !B & C) ~ A, columns separated by tabs. */
void task4(void)
{
    int A, B, C, nA, nB, conj, disj, eq;

    printf("A\tB\tC\t!A\t!B\t!B&C\t!A|(!B&C)\t(!A|!B&C)~A\n");
    for (A = 0; A <= 1; A++)
        for (B = 0; B <= 1; B++)
            for (C = 0; C <= 1; C++) {
                nA = !A;
                nB = !B;
                conj = nB & C;
                disj = nA | conj;
                eq = (disj == A);
                printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\n",
                       A, B, C, nA, nB, conj, disj, eq);
            }
}

/* 5. abc and xyz -> a+z, b+x, c+y (each on a new line). */
void task5(void)
{
    int abc, xyz, a, b, c, x, y, z;

    printf("Enter a 3-digit number abc: ");
    scanf("%d", &abc);
    printf("Enter a 3-digit number xyz: ");
    scanf("%d", &xyz);

    a = abc / 100;  b = abc / 10 % 10;  c = abc % 10;
    x = xyz / 100;  y = xyz / 10 % 10;  z = xyz % 10;

    printf("%d\n", a + z);
    printf("%d\n", b + x);
    printf("%d\n", c + y);
}

/* 6. abcd -> ab + cd. */
void task6(void)
{
    int n;

    printf("Enter a 4-digit number abcd: ");
    scanf("%d", &n);
    printf("ab + cd = %d\n", n / 100 + n % 100);
}

/* 7. max(x, y) without a conditional operator. */
void task7(void)
{
    double x, y;

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter y: ");
    scanf("%lf", &y);
    printf("max(x, y) = %g\n", (x + y + fabs(x - y)) / 2);
}

int main(void)
{
    printf("\n===== Task 1 =====\n"); task1();
    printf("\n===== Task 2 =====\n"); task2();
    printf("\n===== Task 3 =====\n"); task3();
    printf("\n===== Task 4 =====\n"); task4();
    printf("\n===== Task 5 =====\n"); task5();
    printf("\n===== Task 6 =====\n"); task6();
    printf("\n===== Task 7 =====\n"); task7();
    return 0;
}
