#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Для sleep()
#include <string.h> // Для memmove()

int main() {
    int N;
    printf("Enter the array size: ");
    scanf("%d", &N);

    // Виділення пам’яті для масиву
    int *Array = (int*)malloc(N * sizeof(int));
    if (Array == NULL) {
        printf("Memory not allocated\n");
        return 1;
    }

    int *n_array; // Вказівник на поточний елемент
    int *f_array = Array; // Перший елемент масиву
    int *l_array = Array + N; // Останній елемент масиву

    // Заповнення масиву випадковими числами від -100 до 100
    srand(time(NULL));
    for (n_array = f_array; n_array < l_array; n_array++) {
        *n_array = (rand() % 201) - 100;
    }

    // Вивід початкового масиву
    for (n_array = f_array; n_array < l_array; n_array++) {
        printf("%4d", *n_array);
    }
    printf("\nPress Enter to start animation...");
    getchar(); getchar(); // Очікуємо Enter перед початком

    // Анімація видалення першого елемента на кожній ітерації
    while (N > 0) {
        // Зсуваємо всі елементи вліво, видаляючи перший
        memmove(Array, Array + 1, (N - 1) * sizeof(int));

        // Зменшуємо розмір масиву через realloc()
        int *temp = (int*)realloc(Array, (N - 1) * sizeof(int));
        if (temp == NULL && N > 1) {
            printf("Memory reallocation failed\n");
            break;
        }

        Array = temp; // Оновлюємо вказівник
        N--; // Зменшуємо розмір масиву
        l_array = Array + N; // Оновлюємо кінець масиву

        // Вивід оновленого масиву
        for (n_array = Array; n_array < l_array; n_array++) {
            printf("%4d", *n_array);
        }
        printf("\n");

        sleep(1); // Затримка 1 секунда
    }

    // Звільнення пам’яті
    free(Array);
    return 0;
}
