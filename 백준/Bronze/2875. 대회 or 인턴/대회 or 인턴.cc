#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Man,Woman,Ship;
    int cnt = 0;

    scanf("%d %d %d",&Woman,&Man,&Ship);

    while(1){
        if(Man>=1&&Woman>=2){
            Man=Man-1;
            Woman=Woman-2;
            if(Man+Woman>=Ship){
                cnt++;
            }
        }
        else{
            printf("%d",cnt);
            return 0;
        }
    }
}