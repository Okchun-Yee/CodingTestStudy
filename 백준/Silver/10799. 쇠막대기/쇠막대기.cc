#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    stack<char>st;
    char nnn[100001];
    int i;
    int siz=0;
    scanf("%s",nnn);

    for(i=0;nnn[i]!='\0';i++){
        if(nnn[i]=='('){
           st.push(nnn[i]);
        }
        else if(nnn[i]==')'){
            if(nnn[i-1]=='('){
                st.pop();
                siz=siz+st.size();
               }
               else{
                st.pop();
                siz++;
            }
        }

    }
    printf("%d",siz);
}
