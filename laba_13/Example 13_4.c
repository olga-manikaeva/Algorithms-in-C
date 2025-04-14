#include <stdio.h>
#include <stdlib.h>

int main() {

    char address1 [] = "/Users/olga/Documents/xcode/lab_13/lab_13/lab_13/A1.txt";
    char address2 [] = "/Users/olga/Documents/xcode/lab_13/lab_13/lab_13/A2.txt";
    char en[300];
    FILE *f1, *f2;

    if((f1= fopen(address1, "r"))==NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    if((f2= fopen(address2, "w"))==NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }

    // пока не дойдем до конца, считываем по 256 байт
    while((fgets(en, 300, f1))!=NULL)
    {
        // записываем строку
        fputs(en, f2);
        printf("%s", en);
    }

    fclose(f1);
    fclose(f2);

    return 0;
}


