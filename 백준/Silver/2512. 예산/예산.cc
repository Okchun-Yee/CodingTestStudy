#include <stdio.h>

using namespace std;

int main()
{
    int i,con, sum=0, all;
    int bud[10000]={0};
    int big = -1000000001;
    scanf("%d",&con);
    for(i=0;i<con;i++){
        scanf("%d",&bud[i]);
        if(big<=bud[i]){
            big = bud[i];
        }
    }

    scanf("%d",&all);

    int hig = big;
    int low = 0;
    int mid;
    int mmm=1;
    int sma = 1000000001;
    int sav;

    while(low<=hig){
        mid = (hig+low)/2;
        for(i=0;i<con;i++){
            if(mid >= bud[i]){
                sum = sum+bud[i];
            }
            if(mid < bud[i]){
                sum = sum + mid;
            }
        }
        if(sum > all){
            hig = mid-1;
        }
        if(sum < all){
            low = mid +1;
        }
        mmm = all - sum;
        if(mmm <= sma&&mmm>=0){
            sma = mmm;
            sav = mid;
        }
        if(mmm==0){
            break;
        }
        sum=0;
    }
    printf("%d",sav);
}
