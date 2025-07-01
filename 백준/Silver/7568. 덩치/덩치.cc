#include <stdio.h>
#include <queue>

using namespace std;


int main()
{
    queue<int>qu;

    int i,j,sum;
    int hei[50]={0};
    int wei[50]={0};
    int cnt=1;

    scanf("%d",&sum);

    for(i=0;i<sum;i++){
        scanf("%d",&hei[i]);
        scanf("%d",&wei[i]);
    }

    for(i=0;i<sum;i++){
        for(j=0;j<sum;j++){
            if(hei[i]<hei[j]&&wei[i]<wei[j]){
                cnt++;
            }
        }
        qu.push(cnt);
        cnt=1;
    }

    for(i=0;i<sum;i++){
        printf("%d ",qu.front());
        qu.pop();
    }
}
