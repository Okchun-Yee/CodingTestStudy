#include <stdio.h>

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        for(j=1;j<=n+i;j++){
            if(j>=n-i&&j<=n+i) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    for(i=n-1;i>=0;i--){
        for(j=1;j<=n+i;j++){
            if(j>=n-i&&j<=n+i) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}