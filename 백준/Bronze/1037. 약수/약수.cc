#include <stdio.h>

int check[1000000];
int main() {
    int divisor=0;
    scanf("%d",&divisor);
    int num[divisor];
    if(divisor<=50){
        for(int i=0;i<divisor;i++){
            scanf("%d",&num[i]);
            if(check[num[i]]!=0 || num[i]<2)
                do{
                    printf("다시 입력해주세요 : ");
                    scanf("%d",&num[i]);
                    if(check[num[i]]==0&&num[i]>=2&&num[i]<=1000000)
                        break;
                }while(check[num[i]]!=0||num[i]<=2);
            if(check[num[i]]==0&&num[i]>=2&&num[i]<=1000000)
                check[num[i]]++;
        }
        int temp=0;
        for(int i=0;i<divisor;i++)
            for(int j=i+1;j<divisor;j++)
                if(num[i]>num[j]){
                    temp=num[i];
                    num[i]=num[j];
                    num[j]=temp;
                }
        int cnt=0;
        int sum=0;
        sum=num[0]*num[divisor-1];
        for(int i=0;i<divisor;i++){
            if(num[i]*num[divisor-1-i]==sum) cnt++;
            else {
            printf("약수가 아닙니다. 종료합니다.");
            return 0;
            }
        }
        if(cnt==divisor){
            printf("%d",sum);
            return 0;
        }
        
    }
}