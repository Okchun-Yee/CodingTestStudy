#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int i;
    int save;
    int num;

    scanf("%d",&num);
    queue<int>qu;

    for(i=1;i<=num;i++){
        qu.push(i);
    }

    while(qu.size() !=1){
        qu.pop();
        save = qu.front();
        qu.pop();
        qu.push(save);
    }

    printf("%d",qu.front());
}
