/* Lab 1, variant 2 */
#include <stdio.h>
#include <math.h>

/* 1. 8-digit number*/
void task1(void)
{
    char n[16];
    long long product = 1;
    int flag, d, i;

    printf("Enter an 8-digit number: ");
    scanf("%8s", n);
    for (i = 0; i < 8; i++) {
        printf("Include digit %c (position %d) in the product? (0/1): ", n[i], i + 1);
        scanf("%d", &flag);
        d = n[i] - '0';
        product *= flag * d + (1 - flag);
    }
    printf("Product: %lld\n", product);
}

/* 2. 6-digit number*/
void task2(void)
{
    char s[16];
    int i;

    printf("Enter a 6-digit number: ");
    scanf("%6s", s);
    printf("Result: ");
    for (i = 0; i < 6; i++)
        printf("%d", 1 - (s[i] - '0') % 2);
    printf("\n");
}

/* 3. Two points*/
void task3(void)
{
    double x1, y1, x2, y2, r2;

    printf("Enter point P1 (x y separated by a space): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter point P2 (x y separated by a space): ");
    scanf("%lf %lf", &x2, &y2);

    r2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

    printf("Circle 1 (center P1, passes through P2):\n");
    printf("(x - (%g))^2 + (y - (%g))^2 = %g\n", x1, y1, r2);
    printf("Circle 2 (center P2, passes through P1):\n");
    printf("(x - (%g))^2 + (y - (%g))^2 = %g\n", x2, y2, r2);
}

/* 4. Table of powers of numbers 2..9*/
void task4(void)
{
    int base, e, p;

    for (base = 2; base <= 9; base++) {
        p = base * base;                 
        for (e = 2; e <= 5; e++) {
            printf("%d^%d = %d\t", base, e, p);
            p *= base;                    
        }
        printf("\n");
    }
}

/* 5. abc and xyz*/
void task5(void)
{
    int abc, xyz, a, b, c, x, y, z;

    printf("Enter a 3-digit number abc: ");
    scanf("%d", &abc);
    printf("Enter a 3-digit number xyz: ");
    scanf("%d", &xyz);

    a = abc / 100;  b = abc / 10 % 10;  c = abc % 10;
    x = xyz / 100;  y = xyz / 10 % 10;  z = xyz % 10;

    printf("%d\n", a * y);
    printf("%d\n", b * z);
    printf("%d\n", c * x);
}

/* 6. abcd*/
void task6(void)
{
    int n, a, b, c, d;

    printf("Enter a 4-digit number abcd: ");
    scanf("%d", &n);

    a = n / 1000;  b = n / 100 % 10;  c = n / 10 % 10;  d = n % 10;

    printf("a*c + b*d = %d\n", (10 * a + c) + (10 * b + d));
}

/* 7. min(x, y)*/
void task7(void)
{
    double x, y;

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter y: ");
    scanf("%lf", &y);
    printf("min(x, y) = %g\n", (x + y - fabs(x - y)) / 2);
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
