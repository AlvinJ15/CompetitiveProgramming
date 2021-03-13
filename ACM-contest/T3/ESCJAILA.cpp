#include <bits/stdc++.h>
using namespace std;
bool marcados[101][101][2];
struct node{
  int x,y,z;
};
int px[] = {0,0,-1,1};
int py[] = {-1,1,0,0};
int dis[101][101][2];
main(){
  queue<node> colita;
  int N,M,a,b,xx,yy,ant;
  char grid[105][105];
  node var,aux;
  while(scanf("%d%d",&N,&M),N!=-1 && M!=-1){
    while(!colita.empty())colita.pop();
    memset(dis,0,sizeof dis);
    memset(marcados,0,sizeof marcados);
    for(int i=0;i<N;i++){
      scanf("\n");
      for(int j=0;j<M;j++){
        scanf("%c",&grid[i][j]);
        if(grid[i][j]=='H'){
          a=i;b=j;
        }

      }
    }
    var.x=a;var.y=b;var.z=0;
    marcados[var.x][var.y][var.z]=1;
    colita.push(var);
    while(!colita.empty()){
      var=colita.front();colita.pop();
      if(var.x==0 || var.y==0||var.x==N-1 || var.y==M-1)break;
    //  cout<<"IT"<<endl;
      for(int i=0;i<4;i++){
        xx=var.x+px[i];
        yy=var.y+py[i];
        if(marcados[xx][yy][var.z]||(grid[xx][yy]=='D'&&var.z==0)||grid[xx][yy]=='W')continue;
        ant=var.z;
        marcados[xx][yy][var.z]=1;
        dis[xx][yy][var.z]=dis[var.x][var.y][var.z]+1;
        aux.z=var.z;
        if(grid[xx][yy]=='C'){
          if(!marcados[xx][yy][0])
            dis[xx][yy][0]=dis[xx][yy][var.z];
          aux.z=0;
        
        }
        if(grid[xx][yy]=='O'){
          if(!marcados[xx][yy][1])
            dis[xx][yy][1]=dis[xx][yy][var.z];
          aux.z=1;
        }
  //      cout<<xx<<yy<<"   "<<dis[xx][yy][var.z]<<endl;
        marcados[xx][yy][aux.z]=1;
        aux.x=xx;
        aux.y=yy;
        colita.push(aux);
      }
    }
    
    if(!(var.x==0 || var.y==0||var.x==N-1 || var.y==M-1))
      printf("%d\n",-1);
    else
      printf("%d\n",dis[var.x][var.y][var.z]+1);
  }	


}
