#include <bits/stdc++.h>
using namespace std;
int points[12][2];
int memo[1<<11][11];
int N;
int dp(int b,int ant){
  if(!b)return abs(points[ant][0]-points[0][0])+abs(points[0][1]-points[ant][1]);
  if(memo[b][ant]!=-1)return memo[b][ant];
  int ans=10000000;
  for(int i=0;i<N+1;i++){
    if(b&(1<<i)){
      ans=min(ans,abs(points[ant][0]-points[i][0])+abs(points[ant][1]-points[i][1])+dp(b&(~(1<<i)),i));
    }
  }
  return memo[b][ant]=ans;
}
main(){
  int T;
  int F,C;
  cin>>T;
  while(T--){
    scanf("%d%d",&F,&C);
    scanf("%d%d",&points[0][0],&points[0][1]);
    scanf("%d",&N);
    memset(memo,-1,sizeof memo);
    for(int i=0;i<N;i++){
      scanf("%d",&points[i+1][0]);
      scanf("%d",&points[i+1][1]);
    }
    printf("The shortest path has length %d\n",dp(((1<<(N+1))-1)-1,0));

  }


}
