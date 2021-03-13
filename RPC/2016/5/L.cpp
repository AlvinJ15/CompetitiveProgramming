#include <bits/stdc++.h>
using namespace std;
struct node{
  int f,c,p;
  node(){f=c=p=0;}
  node(int x,int y,int z):f(x),c(y),p(z){}
};
bool marcados[100][100][100];
int dis[100][100][100];
int px[] ={0,0,-1,1};
int py[]={1,-1,0,0};
int pz[]={1,-1};
main(){
  char grid[100][100][100];
  int P,C,F,cases=1;
  queue<node> cola;	
  node inicio,var,fin;
  while(scanf("%d%d%d",&F,&C,&P),F|C|P){
    memset(marcados,0,sizeof marcados);
    memset(dis,0,sizeof dis);
    /*for(int i=0;i<P;i++){
      for(int j=0;j<F;j++){
        scanf("\n");
        for(int h=0;h<C;h++){
          scanf("%c",&grid[i][j][h]);
        }
      }
      scanf("\n");
    }*/
    for(int i=0;i<P;i++){
      for(int j=0;j<F;j++){
        cin>>grid[i][j];
      }
    }
    for(int i=0;i<P;i++){
      for(int j=0;j<F;j++){
        for(int h=0;h<C;h++){
    //      cout<<grid[i][j][h];
          if(grid[i][j][h]=='S')
            inicio=node(j,h,i);
          if(grid[i][j][h]=='E')
            fin=node(j,h,i);
        }
     //   cout<<endl;
      }
     // cout<<endl;
    }
   // cout<<inicio.f<<" "<<inicio.c<<" "<<inicio.p<<endl;
   // cout<<fin.f<<" "<<fin.c<<" "<<fin.p<<endl;
    bool flag=false;
    while(!cola.empty())cola.pop();
    cola.push(inicio);
    marcados[inicio.f][inicio.c][inicio.p]=1;
    while(!cola.empty()){
      var = cola.front();cola.pop();
      if(var.f==fin.f && var.c==fin.c&&var.p==fin.p){
        flag=true;
        break;
      }
      for(int i=0;i<4;i++){
        int ff=var.f+px[i];
        int cc=var.c+py[i];
        if(ff>=0&&ff<F&&cc>=0&&cc<C&&!marcados[ff][cc][var.p]&&grid[var.p][ff][cc]!='#'){
          cola.push(node(ff,cc,var.p));
          dis[ff][cc][var.p]=dis[var.f][var.c][var.p]+1;
          marcados[ff][cc][var.p]=1;
        }
      }
      if(grid[var.p][var.f][var.c]=='-'){
        for(int i=0;i<2;i++){
          int pp=var.p+pz[i];
          if(pp>=0&&pp<P&&!marcados[var.f][var.c][pp]&&grid[pp][var.f][var.c]=='-'){
            cola.push(node(var.f,var.c,pp));
            dis[var.f][var.c][pp]=dis[var.f][var.c][var.p]+1;
          }
        }
      }
    }
    if(flag){
      printf("%d\n",dis[fin.f][fin.c][fin.p]);
    }
    else
      printf("%d\n",-1);
  
  }

}
