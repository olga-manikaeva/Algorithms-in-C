//Example 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Input(int *ptrN, int *ptrM);

int main()

{
    int N, M;
    // Введення розмірів через окрему функцію
    Input(&N, &M);

    int K = N * M;
    int *Array = (int*)malloc(K * sizeof(int));
    if (Array == NULL)
    {
        printf("Memory not allocated\n");
        return 1;
    }

    int *n_array;  // вказівник на поточний елемент
    int *f_array;  // перший елемент масиву
    int *l_array;  // останній елемент масиву

    f_array = &Array[0];
    l_array = Array + K;

    // Заповнення випадковими числами
    srand(time(NULL));
    for(n_array = f_array; n_array < l_array; n_array++)
    {
        *n_array = rand() % 101;
    }

    // Вивід як двовимірного масиву
    printf("\nMatrix:\n");
    int count = 0;
    for(n_array = f_array; n_array < l_array; n_array++)
    {
        printf("%4d", *n_array);
        count++;
        if (count % M == 0)
            printf("\n");
    }

    // Вивід у зворотному порядку
    printf("\nMatrix elements in reverse order:\n");
    count = 0;
    for(n_array = l_array - 1; n_array >= f_array; n_array--)
    {
        printf("%4d", *n_array);
        count++;
        if (count % M == 0)
            printf("\n");
    }

    free(Array);
    return 0;
}

// Функція для введення розмірів матриці
void Input(int *ptrN, int *ptrM) {
    printf("Enter number of rows: ");
    scanf("%d", ptrN);
    printf("Enter number of columns: ");
    scanf("%d", ptrM);
}

