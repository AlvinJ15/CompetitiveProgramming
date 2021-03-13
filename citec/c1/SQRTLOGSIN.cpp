#include <bits/stdc++.h>
using namespace std;
#define M 1000000
int pre[1000005][3];
int memo[1000005];
int dp(int x){
  if(x==0)return 1;
  if(memo[x]!=-1)return memo[x];
  return memo[x]=(dp(pre[x][0])%M+dp(pre[x][1])%M+dp(pre[x][2])%M)%M;
}
main(){
  int x;
  memset(memo,-1,sizeof memo);
  for(int i=0;i<1000005;i++){
    pre[i][0]=floor(i-sqrt(i));
    pre[i][1]=floor(log(i));
    pre[i][2]=floor(i*pow(sin(i),2));
  }
  while(scanf("%d",&x),x^-1){
    printf("%d\n",dp(x));
  }	


}
