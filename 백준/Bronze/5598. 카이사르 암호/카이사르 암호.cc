#include <stdio.h>
#define SIZE 26

void read_line(char buffer[]);

int main()
{
    char alp[SIZE] = {'A','B','C','D','E','F','G',
    'H','I','J','K','L','M','N','O','P','Q','R','S',
    'T','U','V','W','X','Y','Z'};
    char text[1000]={'\0'};
    int temp=0;
    scanf("%s",text);
    
    for(int i=0;text[i]!='\0';i++){
        for(int j=0;j<SIZE;j++){
            if(text[i]==alp[j]){
                if(j-3<0){
                    temp=SIZE-3+j;
                    printf("%c",alp[temp]);
                }
                else if(j-3 >=0){
                    printf("%c",alp[j-3]);
                }
            }
        }
    }
}