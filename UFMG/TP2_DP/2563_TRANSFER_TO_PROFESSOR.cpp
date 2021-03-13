#include <bits/stdc++.h>
using namespace std;
int N,K;
int memo[10005][105];
int D[105];
int P[105];
#define NEG_INF -1e8
/*int dp(int k, int n){
    if(k>K)return NEG_INF;
    if(n==N)return 0;
    if(memo[k][n]!=-1)
        return memo[k][n];
    return memo[k][n] = max(D[n]+dp(k+P[n],n+1), dp(k,n+1));
}*/
int main(){
    
    while(scanf("%d%d",&N,&K)!=EOF){
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<N;i++){
            scanf("%d",D+i);
        }
        for(int i=0;i<N;i++){
            scanf("%d",P+i);
        }

        for(int i=0;i<=K;i++)
            memo[i][N]=0;
        for(int n=N-1;n>=0;n--){
            for(int k=0;k<=K;k++){
                if(k+P[n]<=K){
                    memo[k][n] = max(D[n]+memo[k+P[n]][n+1], memo[k][n+1]);
                }else{
                    memo[k][n] = memo[k][n+1];
                }
            }
        } 
        printf("%d\n",max(0,memo[0][0]));
    }
}
