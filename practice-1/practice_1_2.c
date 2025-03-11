#include <stdio.h>

#define N 10

int main() {

    int i_array[N] = {8, 7, 5, 2, 9, 2, 4, 2, 7, 4};
    float f_array[N] = {.1, .4, .6, .7, .8, .9, .2, .3, .5, .6};
    
    int *i_ptr;
    float *f_ptr;
    int i;
    
    for(i = 0; i < N; i++){
        printf("%d | %.1f \n", i_array[i],f_array[i]);
    }
    printf("Using pointers: \n");
    i_ptr = &i_array[0];
    f_ptr = &f_array[0];
    
    for(i = 0; i < N; i++){
        printf("%d | %.1f \n", *i_ptr++,*f_ptr++);
    }


    return 0;
    
}