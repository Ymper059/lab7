#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
void task1()
{
    char c;
    printf("Введите символ: ");
    scanf(" %c", &c);

    switch (c)
    {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        printf("Это цифра\n");
        break;
    default:
        if (isalpha((unsigned char)c))
            printf("Это буква\n");
        else
            printf("Неизвестный символ\n");
    }
}

void task2()
{
    float x, y;
    char c;
    printf("Введите выражение: ");
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
            printf("Ошибка: деление на ноль\n");
        else
            printf("=%g\n", x / y);
        break;
    case '^':
        printf("=%g\n", pow(x, y));
        break;
    default:
        printf("Неизвестная операция\n");
    }
}

int value(char c)
{
    switch (c)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    }
    return 0;
}

void task3()
{
    char s[20];
    int i = 0, result = 0;

    printf("Введите год римскими цифрами: ");
    scanf("%19s", s);

    while (s[i] != '\0')
    {
        if (value(s[i]) < value(s[i + 1]))
            result -= value(s[i]);
        else
            result += value(s[i]);
        i++;
    }
    printf("Год: %d\n", result);
}

int main()
{
    setlocale(LC_CTYPE, "RUS");
    int choice;

    do
    {
        printf("1 - Цифра или буква\n");
        printf("2 - Калькулятор\n");
        printf("3 - Римские цифры -> год\n");
        printf("0 - Выход\n");
        printf("Выберите задание: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 0:
            printf("Выход\n");
            break;
        }
    } while (choice != 0);

    return 0;
}