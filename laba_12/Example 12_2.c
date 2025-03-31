#include <stdio.h>

void add(int x, int y);
void subtract(int x, int y);
void multiply(int x, int y);
void delitiply(int x, int y);

int main()
{
    int a, b;
    printf("Enter two numbers: \n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("\n");
    // масив вказівників на функцію
    void (*operations[4])(int, int) = {add, subtract, multiply,delitiply};
    
    // отримуємо довжину масиву
    int length = sizeof(operations)/sizeof(operations[0]);
    
    for(int i=0; i < length; i++)
    {
        operations[i](a, b);    // виклик функції через вказівник
    }
    
    return 0;
}

void add(int x, int y){
    printf("x + y = %d \n", x + y);
}
void subtract(int x, int y){
    printf("x - y = %d \n", x - y);
}
void multiply(int x, int y){
    printf("x * y = %d \n", x * y);
}
void delitiply(int x, int y){
    printf("x / y = %d \n", x / y);
}
