#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Q 100
#define LEN 200
int main()
{
    char Str[LEN + 1];
    int q;
    scanf("%d", &q);
    scanf(" %s", Str);
    int len = strlen(Str);
    int s[Q] = { 0 }, a[Q] = { 0 }, b[Q] = { 0 }, p = 0;
    char str[Q][LEN + 1];
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &s[i]);
        switch (s[i])
        {
        case 1:
            scanf(" %s", str[i]);
            break;
        case 2:
            scanf("%d%d", &a[i], &b[i]);
            break;
        case 3:
            scanf("%d %s", &a[i], str[i]);
            break;
        case 4:
            scanf(" %s", str[i]);
            break;
        default:
            printf("Input Error!");
            break;
        }
    }
    for (int i = 0; i < q; i++)
    {
        char temp[LEN + 1] = "\0";
        int count = 0;
        switch (s[i])
        {
        case 1:
            for (int j = len; j <= len + strlen(str[i]); j++)
            {
                Str[j] = str[i][j - len];
                Str[j + 1] = '\0';
            }
            len = strlen(Str);
            printf("%s\n", Str);
            break;
        case 2:
            for (int j = a[i]; j < a[i] + b[i]; j++)
            {
                str[i][j - a[i]] = Str[j];
                Str[j - a[i]] = str[i][j - a[i]];
            }
            Str[b[i]] = '\0';
            for (int j = b[i] + 1; Str[j] != '\0'; j++)
            {
                Str[j] = '\0';
            }
            len = strlen(Str);
            printf("%s\n", Str);
            break;
        case 3:
            for (int j = a[i]; Str[j] != '\0'; j++)
            {
                temp[j - a[i]] = Str[j];
                temp[j - a[i] + 1] = '\0';
            }
            for (int j = a[i]; str[i][j - a[i]] != '\0'; j++)
            {
                Str[j] = str[i][j - a[i]];
                p = j;
            }
            for (int j = p + 1; temp[j - p - 1] != '\0'; j++)
            {
                Str[j] = temp[j - p - 1];
                Str[j + 1] = '\0';
            }
            len = strlen(Str);
            printf("%s\n", Str);
            break;
        case 4:
            for (int j = 0; Str[j] != '\0'; j++)
            {
                count = 0;
                for (int k = j; str[i][k - j] != '\0'; k++)
                {
                    if (Str[k] == str[i][k - j])
                    {
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (count == strlen(str[i]))
                {
                    p = j;
                    break;
                }
                else
                {
                    p = -1;
                }
            }
            printf("%d\n", p);
            break;
        default:
            printf("Input Error!");
            break;
        }
    }
    return 0;
}
