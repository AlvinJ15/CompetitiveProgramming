#include <bits/stdc++.h>
using namespace std;
int N;
int baby[16];
int AC[16];
int memo[1<<16];
int hammin(int x){
  x=(x&0x55555555) +( (x>>1)&0x55555555);
  x=(x&0x33333333) +( (x>>2)&0x33333333);
  x=(x&0x0F0F0F0F) + ((x>>4)&0x0F0F0F0F);
  x=(x&0x00FF00FF) + ((x>>8)&0x00FF00FF);
 
  return x;
}
int dp(int bitmask){
  if(bitmask==0)
    return 0;
  if(memo[bitmask]!=-1){
    return memo[bitmask];}
  int ans=1<<30;
  int index=N-hammin(bitmask);
  for(int p1=0;p1<N;p1++){
    if(bitmask&(1<<p1)){
      ans=min(ans,abs(baby[p1]-AC[index])+abs(p1-index)+dp(bitmask&~(1<<p1)));
    }
  }
  return memo[bitmask]=ans;
}
main(){
	while(scanf("%d",&N),N){
    memset(memo,-1,sizeof memo);
    for(int i=0;i<N;i++)
      scanf("%d",&baby[i]);
    for(int i=0;i<N;i++)
      scanf("%d",&AC[i]);
    printf("%d\n",dp((1<<N)-1));
  }


}
