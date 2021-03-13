#include <bits/stdc++.h>
using namespace std;
int py[]={ -1,0 ,1 ,-1,1,-1, 0,1};
int px[]={-1 ,-1,-1,0 ,0,1 ,1,1};
int N,M,cnt;
bool marcados[101][101];
char grid[101][101];
int var=0;
void dfs(int x,int y,char c){
  int xx,yy;
  var++;
  for(int i=0;i<8;i++){
    xx=x+px[i];
    yy=y+py[i];
    if(xx<0 || yy<0 ||xx>=M||yy>=N || marcados[xx][yy]|| grid[xx][yy]!=c)continue;
    marcados[xx][yy]=1;
    dfs(xx,yy,c);
  }
  
}
main(){
  while(scanf("%d%d",&M,&N),M){
    memset(marcados,0,sizeof marcados);
    for(int i=0;i<M;i++){
      scanf("\n");
      for(int j=0;j<N;j++){
        scanf("%c",&grid[i][j]);
      }
    }
    cnt=0;
    for(int i=0;i<M;i++){
      for(int j=0;j<N;j++){
        if(!marcados[i][j] && grid[i][j]=='@'){
          marcados[i][j]=1;
          var=0;
          dfs(i,j,'@');
          //cout<<var<<endl;
          cnt++;
        }

      }
    }
    printf("%d\n",cnt);
  }
	


}
