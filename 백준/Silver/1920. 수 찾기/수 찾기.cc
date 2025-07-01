#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int num,aaa;
    int nnn[100000]={0};
    int bbb[100000]={0};
    int i,j=0;

    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&nnn[i]);
    }
    sort(nnn,nnn+num);

    scanf("%d",&aaa);
    for(i=0;i<aaa;i++){
        scanf("%d",&bbb[i]);
    }

    int low = 0;
    int hig = num-1;
    int mid;
    int flo=0;

    for(i=0;i<aaa;i++){
        while(low<=hig){
            mid = (low+hig)/2;

            flo = 0;

            if(nnn[mid]>bbb[i]){
                hig = mid-1;
            }

            if(nnn[mid]<bbb[i]){
                low = mid+1;
            }

            if(nnn[mid]==bbb[i]){
                printf("1\n");
                flo = 1;
                break;
            }
        }
        low = 0;
        hig = num-1;

        if(flo==0){
            printf("0\n");
        }
    }
}
