#include <stdio.h>

using namespace std;

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=1;j<=n+i;j++){
            if(j>=n-i&&j<=n+i)
                printf("*");
            else 
                printf (" ");
        }
        printf("\n");
    }
}