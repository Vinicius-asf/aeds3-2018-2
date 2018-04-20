#include <stdlib.h>
#include <stdio.h>

void uppercase(char *letter)
{
    *letter -= 32;
}

void lowercase(char *letter)
{
    *letter += 32;
}

int main()
{
    char teste[51];
    int i = 0;
    int Case = 0;
    while (fgets(teste, 51, stdin) && teste[i] != 0)
    {
        while (teste[i] != 10)
        {
            if (teste[i] != 32)
            {
                if (Case == 0)
                {
                    Case = 1;
                    if (teste[i] > 96)
                    {
                        uppercase(&teste[i]);
                    }
                }
                else
                {
                    Case = 0;
                    if (teste[i] < 96)
                    {
                        lowercase(&teste[i]);
                    }
                }
            }
            i++;
        }
        printf("%s", teste);
        i = 0;
        Case = 0;
    } 
    return 0;
}