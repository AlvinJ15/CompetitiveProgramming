#include <bits/stdc++.h>
using namespace std;
double AdjMat[20][20];
double memo[1<<18][18];
int N,V;
int hammin(int x){
  x=(x&0x55555555)+((x>>1)&0x55555555);
  x=(x&0x33333333)+((x>>2)&0x33333333);
  x=(x&0x0F0F0F0F)+((x>>4)&0x0F0F0F0F);
  x=(x&0x0000FFFF)+((x>>8)&0x0000FFFF);
  return x;
}
double dp(int bitmask,int act){
  if(bitmask==0)
    return AdjMat[act][0];
  if(memo[bitmask][act]!=-1)
    return memo[bitmask][act];
  double ans =0;
  for(int p1=0;p1<=N;p1++)
    if(bitmask&(1<<p1)){
        ans= max(ans,AdjMat[act][p1]*dp(bitmask&~(1<<p1),p1));
    }
  return memo[bitmask][act]=ans;
}
main(){
	while(scanf("%d%d",&N,&V),N|V){
  int maxi= 1<<18;
  for(int i=0;i<maxi;i++)
    for(int j=0;j<18;j++)
      memo[i][j]=-1;
  int x,y;
  double z;
  for(int i=0;i<20;i++)
    for(int j=0;j<20;j++)
      if(i==j)
        AdjMat[i][j]=1;
      else
        AdjMat[i][j]=0;
  for(int i=0;i<V;i++){
    scanf("%d%d%lf",&x,&y,&z);
    AdjMat[x][y]=1-z;
    AdjMat[y][x]=AdjMat[x][y];
  }
  for(int k=0;k<=N+1;k++)
    for(int i=0;i<=N+1;i++)
      for(int j=0;j<=N+1;j++)
        AdjMat[i][j]=max(AdjMat[i][j],AdjMat[i][k]*AdjMat[k][j]);
  //double ans = ((int)(dp((1<<(N+1))-1,0)*1000+0.5))/(double)1000;
  printf("%.3lf\n",dp((1<<(N+1))-1,0));
  }
}
