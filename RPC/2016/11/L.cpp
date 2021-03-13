#include <bits/stdc++.h>
using namespace std;
int x4[]={-1,0,0,1};
int y4[]={0,-1,1,0};
	int N,M;
  int grid[300][300];
  bool mark[300][300];
  int contador;
int dfs(int x,int y,int c){
  mark[x][y]=true;
  contador++;
  for(int i=0;i<4;i++){
    int xx=x+x4[i];
    int yy=y+y4[i];
    if(xx>=0 && xx<N && yy>=0 && yy<M && !mark[xx][yy]&&grid[xx][yy]==c){
      dfs(xx,yy,c);
    }
  }
}
main(){
  while(scanf("%d%d",&N,&M)!=EOF){
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        scanf("%d",&grid[i][j]);
      }
    }
    memset(mark,0,sizeof mark);
    int minimo= 10000000;
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(!mark[i][j]){
          contador=0;
          dfs(i,j,grid[i][j]);
          minimo = min(contador,minimo);
        }
      }
    }
    printf("%d\n",minimo);
  }
  

}
