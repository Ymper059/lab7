#include <stdio.h>
#include <locale.h>
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

int main()
{
    setlocale(LC_CTYPE, "RUS");
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
    return 0;
}