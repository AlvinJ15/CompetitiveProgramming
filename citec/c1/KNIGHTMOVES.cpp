#include <bits/stdc++.h>
using namespace std;
main(){
  char c;
  int px[]={-2,-2,-1,1,2,2,1,-1,0};
  int py[]={-1,1,2,2,1,-1,-2,-2,0};
  queue< pair<int,int> > colita;
  pair<int,int> var;
  int dis[8][8];
  bool marcados[8][8];
  int xx,yy,Ax,Ay,Bx,By;
  while(scanf("%c",&c)!=EOF){
    memset(marcados,0,sizeof marcados);
    memset(dis,0,sizeof dis);
    while(!colita.empty())colita.pop();
    Ax=c-'a';
    scanf("%c",&c);
    Ay=c-'1';
    scanf("%c",&c);
    scanf("%c",&c);
    Bx=c-'a';
    scanf("%c",&c);
    By=c-'1';
    scanf("\n");
    colita.push(make_pair(Ax,Ay));
    dis[Ax][Ay]=0;
    marcados[Ax][Ay]=1;
    while(!colita.empty()){
      var=colita.front();colita.pop();
      for(int i=0;i<9;i++){
        xx=var.first+px[i];
        yy=var.second+py[i];
        if(xx<0 || yy<0 || xx>=8 || yy >=8|| marcados[xx][yy])continue;
        colita.push(make_pair(xx,yy));
        dis[xx][yy]=dis[var.first][var.second]+1;
        marcados[xx][yy]=1;
        if(xx==Bx && yy==By)break;
      }
    }
    printf("To get from %c%d to %c%d takes %d knight moves.\n",(char)(Ax+'a'),Ay+1,(char)(Bx+'a'),By+1,dis[Bx][By]);
  }	

}
