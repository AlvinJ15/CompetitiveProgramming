#include <bits/stdc++.h>
using namespace std;
int N,M,X,Y,C;
long long memo[2][1000005];
int  values[100000];
#define INFINITE 1e15

int random_number(int low,int h){
    return rand()%(h-low + 1) + low;
}

int main(){
    srand((unsigned)time(0));
    int M;
    memset(values,0,sizeof(values));
    scanf("%d",&M);
    int N = random_number(0,M-2);
    while(N--){
        values[random_number(2,M-1)]=1;
    }

    int contador=0;
    for(int i=2;i<=M-1;i++){
        if(values[i]==1)
            contador++;
    }

    printf("%d %d\n", contador, M);
    for(int i=2;i<=M-1;i++)
        if(values[i]==1)
            printf("%d ",i);
    cout<<endl;
    int X = random_number(1,M-150);
    int Y = random_number(X+1,M);
    printf("%d %d\n", X,Y);

}
