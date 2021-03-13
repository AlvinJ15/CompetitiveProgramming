#include <bits/stdc++.h>
using namespace std;
int N,M,X,Y,C;
long long memo[2][1000005];
int  values[100000];
#define INFINITE 1e15
long long dp(int flag,int n){
    if(n==M)return 0;
    if(n>M)return INFINITE;
    if(values[n]==0)return INFINITE;
    if(memo[flag][n] != -1)return memo[flag][n];
    long long minimo = INFINITE;
    if(flag){
        for(int i=n+1;i<=n+X;i++){
            minimo = min(minimo,1+dp(0,i));
        }
    }
    else{
        for(int i=n+1;i<=n+X;i++){
            minimo = min(minimo,1+dp(0,i));
        }

        for(int i=n+1;i<=n+Y;i++){
            minimo = min(minimo,1+dp(1,i));
        }
    }

    return memo[flag][n] = minimo;
}
/*int dp(int flag, int n){
    if(n==N-1)return 0;
    if(memo[flag][n]!=-1)
        return memo[flag][n];
    
    if(flag){
        int lower_index = lower_bound(values.begin(),values.end(), values[n]+X)-values.begin();
        if(values[lower_index] != values[n]+X)lower_index--;
        if(lower_index==n)
            return INFINITE;
        return memo[flag][n]=1+dp(!flag,lower_index);
    }
    else{
        int lower_index_X = lower_bound(values.begin(),values.end(), values[n]+X)-values.begin();
        if(values[lower_index_X] != values[n]+X)lower_index_X--;
        int lower_index_Y = lower_bound(values.begin(), values.end(), values[n]+Y)-values.begin();
        if(values[lower_index_Y] != values[n]+Y)lower_index_Y--;
        if(lower_index_X == n){
            if(lower_index_Y == n){
                return INFINITE;       
            }
            else{
                return memo[flag][n] = 1+dp(!flag,lower_index_Y);
            }
        }
        else{
            if(lower_index_Y == n){
                return memo[flag][n] = 1+dp(flag,lower_index_X);
            }
            else{
                return memo[flag][n]=1+min(dp(flag,lower_index_X),dp(!flag,lower_index_Y));
            }
        }
    }
}*/
int main(){
    int val;
    scanf("%d%d",&N,&M);
    memset(memo,-1,sizeof(memo));
    memset(values,0,sizeof(values));
    values[1]=1;
    values[M]=1;
    for(int i=0;i<N;i++){
        scanf("%d",&val);
        values[val]=1;
    }
    N=N+2;
    scanf("%d%d",&X,&Y);

    long long resp = dp(0,1);
    if(resp<1 || resp>= 1e12){
        resp=-1;
    }
    printf("%lld\n", resp);
}
