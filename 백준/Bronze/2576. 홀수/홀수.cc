#include <stdio.h>
#define SIZE 7

int main(){
    int num=0;
    int arr[SIZE]={0};
    int cnt=0;
    for (int i=0;i<SIZE;i++){
        scanf("%d",&num);
        if(num%2==1){
            arr[cnt]=num;
            cnt++;
        }
    }
    int sum=0;
    int min=arr[0];
    for(int i=0;i<cnt;i++){
        sum+=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }
    if(arr[0]!=0){
        printf("%d\n",sum);
        printf("%d",min);
    }
    else printf("-1");
}
