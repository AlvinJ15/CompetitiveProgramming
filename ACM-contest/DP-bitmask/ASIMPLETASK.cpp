#include <bits/stdc++.h>
using namespace std;
int N,M;
int adj[20][20];
long long memo[20][1<<20];
long long dp(int act,int bitmask){
  if(!bitmask)return 0;
  if(memo[act][bitmask]!=-1)return memo[act][bitmask];
  long long ans=0;
  for(int i=0;i<N;i++){
    if(bitmask&(1<<i)){
      if(adj[i][act]){
        ans+=1+(dp(act,bitmask^(1<<i)));
      }
      else
        ans+=dp(act,bitmask^(1<<i));
    }
  }
  return memo[act][bitmask]=ans;
}
main(){
  int a,b;
  scanf("%d%d",&N,&M);
  memset(adj,0,sizeof adj);
  for(int i=0;i<M;i++){
    scanf("%d%d",&a,&b);
    a--;b--;
    adj[a][b]=1;
    adj[b][a]=1;
  }
  memset(memo,-1,sizeof memo);
  long long resp=0;
  int bitmask=(1<<N)-1;
  for(int i=0;i<N;i++){
    resp+=dp(i,bitmask^(1<<i));
  }
  printf("%lld",resp);
 


}
