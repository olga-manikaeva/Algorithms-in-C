#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

const int M = 2;

int main() {
    {
        
        //SetConsoleCP(1251);
        //SetConsoleOutputCP(1251);
        
        int j,i;
        FILE *fp; // вказівник на файл
        fp = fopen("/Users/olga/Documents/xcode/lab_13/lab_13/lab_13/input.txt","r");
        
        int N = 0;
        
        while(fscanf(fp,"%*[^\n]%*c")!=EOF)
        {
            N++;
        }
        printf("k= %d \n",N);
        
        int *A = (int*)malloc(N*M*sizeof(int));
        int *B = (int*)malloc(N*sizeof(int));
        
        rewind(fp);
        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                fscanf(fp,"%d",(A+i*M+j));
                printf("A[%1d][%1d] = %2d  ",i+1,j+1,*(A+i*M+j));
                B[i] = *(A+i*M)+*(A+i*M+j);
                
            }
            printf(" | B[%d] = %d",i+1,B[i]);
            printf("\n");
            
        }
        
        fp=fopen("/Users/olga/Documents/xcode/lab_13/lab_13/lab_13/output.txt","w");
        for(i=0; i<N; i++)
        {
            fprintf(fp,"%d\n",B[i]);
            
        }
        
        fclose(fp);
        free(A);
        free(B);
        
    }
}
