#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include <windows.h>

int main() {

const int N = 10;

    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    int i, A[N];
    FILE *fp; // Вказівник на файл
    fp = fopen("/Users/olga/Documents/xcode/lab_13/lab_13/lab_13/input.txt","r");
    if(fp!=NULL)
    {
        printf("Файл input.txt успішно прочитано\n");
    }
    else
    {
        fprintf(stderr,"Файл не знайдено\n");
        return 1;
    }

    for(i=0; i<N; i++)
    {
        if(1!=fscanf(fp,"%d",&A[i]))
        {
            printf("Не вистачає даних в файлі");
            return 1;
        }
        else
        fprintf(stdout,"A[%d]=%d \n",i,A[i]);
    }
    fclose(fp);

    for(i=0; i<N; i++)
    {
        A[i]=A[i]*2;
    }
    fp=fopen("/Users/olga/Documents/xcode/lab_13/lab_13/lab_13/output.txt","w");
    for(i=0; i<N; i++)
    {
        fprintf(fp,"%d\n",A[i]);
        fprintf(stdout,"A new[%d]=%d \n",i,A[i]);
    }

    fclose(fp);
}

