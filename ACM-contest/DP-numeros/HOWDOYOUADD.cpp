#include <bits/stdc++.h>
using namespace std;
#define M 1000000
int N,K;
int memo[105][105];
int DP(int pos,int sum){
  if(sum>N)return 0;
  if(pos==K)
    return sum==N?1:0;
  if(memo[pos][sum]!=-1)return memo[pos][sum];
  int ans=0;
  for(int i=0;i<=N;i++){
    ans+=DP(pos+1,sum+i)%M;
  }
  return memo[pos][sum]=ans%M;
}
main(){
  	while(scanf("%d%d",&N,&K),N|K){
      memset(memo,-1,sizeof memo);
      printf("%d\n",DP(0,0));
    }


}
