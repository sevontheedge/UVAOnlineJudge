#include <stdio.h>

int main()
{
    int i, j;

    while (scanf("%d %d", &i, &j) == 2)
    {
        int max = i > j ? i : j;
        int min = max == i ? j : i;
        int cycleLength = 0;
        int x, cont;
        long long n;
        for (x = max; x >= min; x--)
        {
            cont = 1;
            n = x;
            while (n != 1)
            {
                if (n % 2 == 1)
                {
                    n = 3 * n + 1;
                }
                else
                {
                    n = n / 2;
                }
                cont++;
            }
            if (cont > cycleLength)
            {
                cycleLength = cont;
            }
        }

        printf("%d %d %d\n", i, j, cycleLength);
    }

    return 0;
}