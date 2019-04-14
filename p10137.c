#include <stdio.h>
#include <stdlib.h>



int main()
{
    int numeros, i;
    float media, positivo, negativo, diff;
    float *valores;

    while (1)
    {
        scanf("%d", &numeros);

        if (numeros == 0){
            break;
        }
        media = 0;
        positivo = negativo = 0;
        valores = (float *)malloc(sizeof(float) * numeros);

        for (i = 0; i < numeros; i++){
            scanf("%f", &valores[i]);
            media += valores[i];
        }

        media /= (float)numeros;

        for (i = 0; i < numeros; i++){
            diff = (double) (long) ((valores[i] - media) * 100.0) / 100.0;
            if (diff > 0) positivo += diff;
            else negativo += diff;
        }
        negativo = -negativo;
        
        printf("$%.2f\n", positivo > negativo ? positivo : negativo);
        
    }

    return 0;
}

