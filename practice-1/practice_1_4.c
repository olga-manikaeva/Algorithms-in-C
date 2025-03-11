// Підрахувати суму елементів головної і побочної діагоналі, використовуючи вказівники

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 5

int main() {
    int A[N][M];
    int i, j;
    srand(time(0));

    // Заповнюємо матрицю випадковими числами
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            A[i][j] = rand() % 50;
        }
    }
    // Виводимо матрицю

    printf("Array:\n");
    int ptr_A = (int)A;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%4d ", *(*(A + i) + j));
            // A: Це вказівник на перший елемент двовимірного масиву.
            // A + i: Це вказівник на i-й рядок масиву A.
            // *(A + i): Це вказівник на перший елемент i-го рядка.
            // *(A + i) + j: Це вказівник на j-й елемент i-го рядка.
            // *(*(A + i) + j): Це значення j-го елемента i-го рядка.
        }
        printf("\n");
    }

    int SUM_primary = 0;
    int SUM_secondary = 0;

    for (int i = 0; i < N; i++) {
        SUM_primary += *(*(A + i) + i);
    // A - це вказівник на масив (матрицю).
    // A + i - це вказівник на i-й рядок матриці.
    // *(A + i) - це сам i-й рядок матриці.
    // *(A + i) + i - це вказівник на i-й елемент i-го рядка (елемент головної діагоналі).
    // *(*(A + i) + i) - це значення i-го елемента i-го рядка.
        SUM_secondary += *(*(A + i) + (N - i - 1));
    }

    printf("Sum of primary diagonal: %d\n", SUM_primary);
    printf("Sum of secondary diagonal: %d\n", SUM_secondary);

    return 0;
}