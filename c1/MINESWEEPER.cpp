#include <bits/stdc++.h>
using namespace std;
int px[]= {1,1,0,-1,-1,-1,0,1};
int py[]= {0,1,1,1,0,-1,-1,-1};
int N,M;
int grid [21][21];
bool comprobar(int x,int y){
  int xx,yy;
  int sum=0;
  for(int i=0;i<8;i++){
    xx=x+px[i];
    yy=y+py[i];
    if(xx<0 || yy<0 || xx>=N || yy>=M)continue;
    if(grid[xx][yy]==9)
      sum++;
  }
  return sum==grid[x][y];
}
int main(){
  int test,flags;
  bool resp=1;
  char c;
  scanf("%d",&test);
  while(test--){
    resp=1;
    flags=0;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
      scanf("\n");
      for(int j=0;j<M;j++){
        scanf("%c",&c);
        if(c=='F')
          grid[i][j]=9;
        else
          grid[i][j]=c-'0';
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(grid[i][j]==9){flags++;continue;}
        if(!comprobar(i,j)){
          resp=0;
        }
      }
    }
    if(resp&&flags!=N*M)
      printf("Well done Clark!\n");
    else
      printf("Please sweep the mine again!\n");
  }


}
