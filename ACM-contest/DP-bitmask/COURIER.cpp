#include <bits/stdc++.h>
using namespace std;
int edges;
int vertex;
int inicio;
int AdjMat[101][101];
int arr[15][2];
int Z;
int N;
int memo[1<<12][101];
int dp(int bitmask,int act){
  if(!bitmask){
    return AdjMat[act][inicio];}
  if(memo[bitmask][act]!=-1)
    return memo[bitmask][act];
  int ans=1<<30;
  for(int p1=0;p1<N;p1++){
    if(bitmask&(1<<p1)){
      ans=min(ans,AdjMat[act][arr[p1][0]]+AdjMat[arr[p1][0]][arr[p1][1]]+dp(bitmask&~(1<<p1),arr[p1][1]));
    }
  }
  return memo[bitmask][act]=ans;
}
main(){
	int test;
  int x,y,z;
  cin>>test;
  while(test--){
    memset(memo,-1,sizeof memo);
    for(int i=0;i<101;i++)
      for(int j=0;j<101;j++)
        if(i==j)AdjMat[i][j]=0;
        else AdjMat[i][j]=1<<20;
    scanf("%d%d%d",&vertex,&edges,&inicio);
    for(int i=0;i<edges;i++){
      scanf("%d%d%d",&x,&y,&z);
      AdjMat[x][y]=z;
      AdjMat[y][x]=z;
    }
    N=0;
    scanf("%d",&Z);
    for(int k=0;k<=vertex;k++)
      for(int i=0;i<=vertex;i++)
        for(int j=0;j<=vertex;j++)
          AdjMat[i][j]=min(AdjMat[i][j],AdjMat[i][k]+AdjMat[k][j]);
    int var=0;
    for(int i=0;i<Z;i++){
      scanf("%d%d%d",&x,&y,&z);
      N+=z;
      for(var;var<N;var++){
        arr[var][0]=x;
        arr[var][1]=y;
      }
    }
    printf("%d\n",dp((1<<N)-1,inicio));
  }

}
