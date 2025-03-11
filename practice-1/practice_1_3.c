// Підрахувати суму елементів кожного масиву, підрахувати середньо арифметичне значення двох масивів
#include <stdio.h>

#define N 10

int main() {

    int i_array[N] = {8, 7, 5, 2, 9, 2, 4, 2, 7, 4};
    float f_array[N] = {.1, .4, .6, .7, .8, .9, .2, .3, .5, .6};
    
    int *i_ptr, *i_ptr_end;
    float *f_ptr, *f_ptr_end;

    printf("Using pointers: \n");
    i_ptr = &i_array[0];
    f_ptr = &f_array[0];
    i_ptr_end=i_ptr+N; //задається адреса за останнім елементом масиву
    f_ptr_end=f_ptr+N;
    
    printf("Array_i: ");
    for (; i_ptr < i_ptr_end; i_ptr++) {
        printf("%4d |", *i_ptr);
    }
    printf("\nArray_f: ");
    for (; f_ptr < f_ptr_end; f_ptr++) {
        printf("%4.1f |", *f_ptr);
    }

    i_ptr = &i_array[0];
    f_ptr = &f_array[0];
    float Sum = 0, Average = 0;
    for (; i_ptr<i_ptr_end && f_ptr<f_ptr_end; ){
        Sum = Sum + (*i_ptr++) + (*f_ptr++);
    }
    
    Average = Sum / (2*N);
    printf("\nSUM = %.2f | Average = %.2f \n", Sum, Average);

    return 0;
    
}