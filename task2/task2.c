#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
    setlocale(LC_CTYPE, "RUS");
    float x, y;
    char c;
    printf("¬ведите выражение:");
    scanf("%f%c%f", &x, &c, &y);
    switch (c)
    {
    case '+':
        printf("=%g\n", x + y);
        break;
    case '-':
        printf("=%g\n", x - y);
        break;
    case '*':
        printf("=%g\n", x * y);
        break;
    case '/':
        if (y == 0)
            printf("ќшибка: деление на ноль\n");
        else
            printf("=%g\n", x / y);
        break;
    case '^':
        printf("=%g\n", pow(x, y));
        break;
    }
    return 0;
}