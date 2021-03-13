#include <bits/stdc++.h>
using namespace std;
int N,C;
int memo[2][200005];
int values[200005];

int dp(int flag, int n){
    if(n==N)return 0;
    if(memo[flag][n]!=-1)
        return memo[flag][n];

    if(flag){
        return memo[flag][n]=max(values[n]+dp(!flag,n+1), dp(flag,n+1));
    }
    else{
        return memo[flag][n]=max(dp(!flag, n+1)-C-values[n], dp(flag,n+1));
    }
}
int main(){
    scanf("%d%d",&N,&C);
    memset(memo,-1,sizeof(memo));
    for(int i=0;i<N;i++){
        scanf("%d",&values[i]);
    }

    for(int current=0;current<2;current++){
        memo[current][N] = 0;
    }

    for(int n=N-1;n>=0;n--){
        for(int current=0;current<2;current++){
            if(current){
                memo[current][n]=max(values[n]+memo[!current][n+1],memo[current][n+1]);
            }
            else{
                memo[current][n]=max(memo[!current][n+1]-C-values[n],memo[current][n+1]);
            }
        }
    }

    printf("%d\n",memo[0][0]);
}
