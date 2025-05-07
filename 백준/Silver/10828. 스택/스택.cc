#include <stdio.h>
#include <string.h>
#define NUM 6

void pop();
void push(int);
void size();
void empty();
void top();

int stack[10000];
int top_st=-1;

int main()
{
    int test_case;
    scanf("%d",&test_case);
    char text[test_case][NUM];
    int num[test_case];
    int cnt=0;
    for(int i=0;i<test_case;i++){
        scanf("%s",text[i]);
        if(!strcmp(text[i],"push")){
            scanf("%d",&num[cnt]);
            cnt++;
        }
    }
    int check=0;
    for(int i=0;i<test_case;i++){
        if(!strcmp(text[i],"push")){
            if(cnt>check){
                push(num[check]);
                check++;
            }
        }
        else if(!strcmp(text[i],"pop")){
            pop();
        }
        else if(!strcmp(text[i],"size")){
            size();
        }
        else if(!strcmp(text[i],"empty")){
            empty();
        }
        else if(!strcmp(text[i],"top")){
            top();
        }
    }
    
}

void pop(){
    if(top_st<0)
        printf("-1\n");
    else 
        printf("%d\n",stack[top_st--]);
}

void push(int data){
    stack[++top_st]=data;
}

void size(){
    if(top_st<0)
        printf("0\n");
    else{
        int cnt=0;
        for(int i=0;i<top_st;i++)
            if(stack[i]>0)
                cnt++;
        printf("%d\n",cnt+1);
    }
}

void empty(){
    if(top_st>=0)
        printf("0\n");
    else
        printf("1\n");
}

void top(){
    if(top_st<0)
        printf("-1\n");
    else    
        printf("%d\n",stack[top_st]);
}