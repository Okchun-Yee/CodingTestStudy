#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *text=(char*)malloc(101);
    scanf("%s",text);
    int len = strlen(text);
    int k='z';
    int cnt[k+1]={0,};
    for(int i='a';i<='z';i++){
        int check=0;
        for(int j=0;j<len;j++)
            if(text[j]==i&&cnt[i]==0){
                printf("%d ",j);
                cnt[i]++;
                check=1;
            }
        if(check==0) printf("-1 ");
    }
    free(text);
}
