/* Lab 2, variant 2*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 1. Convert a number to base 5. */
void task1(void)
{
    long long n, m;
    int digits[70], len = 0, i;

    printf("Enter an integer: ");
    scanf("%lld", &n);

    m = n;
    if (m < 0)
        m = -m;
    if (m == 0)
        digits[len++] = 0;
    while (m > 0) {
        digits[len++] = (int)(m % 5);   
        m /= 5;
    }

    printf("Base 5: ");
    if (n < 0)
        printf("-");
    for (i = len - 1; i >= 0; i--)      
        printf("%d", digits[i]);
    printf("\n");
}

/* 2. Fibonacci numbers*/
void task2(void)
{
    long long N, a = 1, b = 1, next, i = 2;

    printf("Enter N: ");
    scanf("%lld", &N);

    if (N < 1) {                        
        printf("First Fibonacci number greater than %lld: f_1 = 1\n", N);
        return;
    }

    while (b <= N) {                    
        next = a + b;
        a = b;
        b = next;
        i++;
    }
    printf("First Fibonacci number greater than %lld: f_%lld = %lld\n", N, i, b);
}

/* 3. Are the digits in ascending order, descending order, or neither?*/
void task3(void)
{
    long long n;
    int asc = 1, desc = 1, count = 1, prev, cur;

    printf("Enter a number: ");
    scanf("%lld", &n);
    if (n < 0)
        n = -n;

    prev = (int)(n % 10);               
    n /= 10;
    while (n > 0) {
        cur = (int)(n % 10);            
        count++;
        if (cur >= prev)
            asc = 0;                    
        if (cur <= prev)
            desc = 0;                   
        prev = cur;
        n /= 10;
    }

    if (count == 1)
        printf("Only one digit: order is not defined.\n");
    else if (asc)
        printf("Digits are in ascending order.\n");
    else if (desc)
        printf("Digits are in descending order.\n");
    else
        printf("Digits are not ordered.\n");
}

/* 4. Sequence of natural numbers ending with 0*/
void task4(void)
{
    long long x, sum = 0;
    int i = 1;                         

    printf("Enter natural numbers, finish with 0:\n");
    scanf("%lld", &x);
    while (x != 0) {
        if (i % 2 == 0 && x % 2 != 0)
            sum += x;
        i++;
        scanf("%lld", &x);
    }
    printf("Sum: %lld\n", sum);
}

/* 5. All three-digit numbers*/
void task5(void)
{
    int n, a, b, c, count = 0;

    for (n = 100; n <= 999; n++) {
        a = n / 100;
        b = n / 10 % 10;
        c = n % 10;
        if (abs(a - b) <= 2 || abs(a - c) <= 2 || abs(b - c) <= 2) {
            printf("%d ", n);
            count++;
            if (count % 15 == 0)        
                printf("\n");
        }
    }
    printf("\nTotal: %d numbers\n", count);
}

/* 6. GCD and LCM*/
void task6(void)
{
    long long a, b, x, y, t, gcd, lcm;

    printf("Enter two natural numbers: ");
    scanf("%lld %lld", &a, &b);

    x = a;
    y = b;
    while (y != 0) {                    
        t = x % y;
        x = y;
        y = t;
    }
    gcd = x;
    lcm = a / gcd * b;                  

    printf("GCD = %lld\n", gcd);
    printf("LCM = %lld\n", lcm);
}

/* 7. n^3 as a sum of n consecutive odd numbers*/
void task7(void)
{
    long long n, first, sum = 0, k, term;

    printf("Enter a natural number: ");
    scanf("%lld", &n);
    if (n < 1) {
        printf("The number must be natural (1, 2, 3, ...).\n");
        return;
    }

    first = n * (n - 1) + 1;
    printf("%lld^3 = ", n);
    for (k = 0; k < n; k++) {
        term = first + 2 * k;
        sum += term;
        if (k > 0)
            printf(" + ");
        printf("%lld", term);
    }
    if (n > 1)
        printf(" = %lld", sum);
    printf("\n");
}

/* 8. Can N be written as a sum of squares of two natural numbers?*/
void task8(void)
{
    long long N, a, b, rem;
    int found = 0;

    printf("Enter a natural number N: ");
    scanf("%lld", &N);

    for (a = 1; 2 * a * a <= N; a++) {
        rem = N - a * a;
        b = (long long)sqrt((double)rem);
        while (b * b > rem)             
            b--;
        while ((b + 1) * (b + 1) <= rem)
            b++;
        if (b * b == rem && b >= a) {
            printf("%lld = %lld^2 + %lld^2\n", N, a, b);
            found = 1;
        }
    }
    if (!found)
        printf("%lld cannot be represented as a sum of two squares.\n", N);
}

int main(void)
{
    int choice;

    do {
        printf("\n===== Lab 2, variant 2 =====\n");
        printf("1 - Base 5\n");
        printf("2 - Fibonacci numbers\n");
        printf("3 - Order of digits\n");
        printf("4 - Sum by position and value\n");
        printf("5 - Three-digit numbers with close digits\n");
        printf("6 - GCD and LCM\n");
        printf("7 - Cube as a sum of odd numbers\n");
        printf("8 - Sum of two squares\n");
        printf("0 - Exit\n");
        printf("Choose a task: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        case 7: task7(); break;
        case 8: task8(); break;
        case 0: break;
        default: printf("Unknown task.\n");
        }
    } while (choice != 0);

    return 0;
}
