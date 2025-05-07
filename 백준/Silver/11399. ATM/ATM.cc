#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int a,i,j;
    int swp = 0;
    int sum = 0;

    scanf("%d",&a);
    int p[a];

    for(i=0;i<a;i++){
        scanf("%d",&p[i]);
    }

    for(i=0;i<a-1;i++){
        for(j=0;j<(a-i)-1;j++){
            if(p[j]>p[j+1]){
                swp = p[j];
                p[j] = p[j+1];
                p[j+1] = swp;
            }
        }
    }

    for(i=0;i<a;i++){
        for(j=0;j<=i;j++){
            sum = sum + p[j];
        }
    }
    printf("%d",sum);
}