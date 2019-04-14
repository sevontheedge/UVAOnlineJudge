#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void atualiza_vizinho(char **campo, int l, int c)
{
    if (campo[l][c] != '*')
    {
        if (campo[l][c] == '.')
        {
            campo[l][c] = '1';
        }
        else
        {
            campo[l][c] = (char)(((int)(campo[l][c])) + 1);
        }
    }
}

int main()
{
    int linhas, colunas, linha_atual, field = 1, i, j, l, c;
    char **campo;
    char *atual;

    scanf("%d %d", &linhas, &colunas);

    while (1)
    {
        

        

        linha_atual = 0;
        campo = (char **)malloc(sizeof(char *) * linhas);

        while (linha_atual < linhas)
        {
            atual = (char *)malloc(sizeof(char) * colunas);
            scanf("%s", atual);
            campo[linha_atual] = atual;
            linha_atual++;
        }

        for (i = 0; i < linhas; i++)
        {
            for (j = 0; j < colunas; j++)
            {
                if (campo[i][j] == '*')
                {
                    for (l = max(0, i - 1); l < min(linhas, i + 2); l++)
                    {
                        for (c = max(0, j - 1); c < min(colunas, j + 2); c++)
                        {
                            atualiza_vizinho(campo, l, c);
                        }
                    }
                }
            }
        }

        printf("Field #%d:\n", field);
        field++;
        for (i = 0; i < linhas; i++)
        {
            for (j = 0; j < colunas; j++)
            {
                printf("%c", campo[i][j] == '.' ? '0' : campo[i][j]);
            }

            printf("\n");
            
        }

        scanf("%d %d", &linhas, &colunas);
        if (linhas == 0 && colunas == 0)
        {
            break;
        }
        printf("\n");
    }

    return 0;
}
