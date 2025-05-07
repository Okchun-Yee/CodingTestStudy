#include <stdio.h>
#include <queue>>

using namespace std;

queue<int>q;
int i,j;
int n,w,L,a;
int now,sum;

int plz()
{
    sum=0;
    for(j=0;j<w-1;j++){
        now=q.front();
        q.pop();
        sum=sum+now;
        q.push(now);
    }
    return sum;
}

int main()
{
    int cnt=0;

    scanf("%d %d %d",&n,&w,&L);

    int qu[1000];

    for(i=0;i<n;i++){
        scanf("%d",&qu[i]);
    }

    for(i=0;i<w;i++){
        q.push(0);
    }
    i=0;
    while(1){
        q.pop();
        plz();
        if(sum+qu[i]<=L){
            q.push(qu[i]);
            i++;
            if(i==n){
                break;
            }
        }
        else {
            q.push(0);
        }
        cnt++;
    }
    printf("%d",cnt+w+1);
}
