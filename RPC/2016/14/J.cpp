#include <bits/stdc++.h>
using namespace std;
int C,M;
int memo[200][200];
int E[200][200];
int dp(int cpu,int m){
  if(m==M)return 0;
  if(cpu==0)return 0;
//  if(cpu<0)return -100000000;
  if(memo[cpu][m]!=-1)return memo[cpu][m];
  int ans=-100000000;
  for(int i=0;i<cpu;i++){
    ans=max(ans,E[m][i]+dp(cpu-(i+1),m+1));
  }
  ans=max(ans,dp(cpu,m+1));
  return memo[cpu][m]=ans;
}
main(){
	scanf("%d%d",&C,&M);
  for(int i=0;i<M;i++){
    for(int j=0;j<C;j++){
      scanf("%d",&E[i][j]);
    }
  }
  memset(memo,-1,sizeof memo);
  printf("%d\n",dp(C,0));


}
