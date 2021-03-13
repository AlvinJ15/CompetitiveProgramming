#include <bits/stdc++.h>
using namespace std;
struct node{
  int a,b,c,d,distancia,C;
  node(){a=b=c=d=distancia=C=0;}
  node(int _a,int _b,int _c,int _d,int _distancia,int _C):a(_a),b(_b),c(_c),d(_d),distancia(_distancia),C(_C){}
};
int px[]={0,0,1,-1};
int py[]={-1,1,0,0};
char hash[4];
void imprimir(){
  
}
char grid[51][51];
bool marcados[51][51][51][51];
node ruta[51][51][51][51]; 
queue<node> colita;
pair<int,int> P[2];
node var,aux;
vector<char> resp;
main(){
  int N,M,test,num,x1,y1,x2,y2;
  hash[0]='W';
  hash[1]='E';
  hash[2]='S';
  hash[3]='N';
  scanf("%d",&test);
  while(test--){
    num=0;
    resp.clear();
    memset(marcados,0,sizeof marcados);
    while(!colita.empty())colita.pop();
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
      scanf("\n");
      for(int j=0;j<M;j++){
        scanf("%c",&grid[i][j]);
        if(grid[i][j]=='P'){
          P[num].first=i;
          P[num++].second=j;
        }

      }
    }
    var.a=P[0].first;
    var.b=P[0].second;
    var.c=P[1].first;
    var.d=P[1].second;
    var.distancia=0;
    marcados[var.a][var.b][var.c][var.d]=1;
    colita.push(var);
    while(!colita.empty()){
      var=colita.front();colita.pop();
      
      if(var.a==var.c&&var.b==var.d)break;
      for(int i=0;i<4;i++){
        x1=(var.a+px[i]+N)%N;
        y1=(var.b+py[i]+M)%M;
        x2=(var.c+px[i]+N)%N;
        y2=(var.d+py[i]+M)%M;
        if(marcados[x1][y1][x2][y2] || (grid[x1][y1]=='X'&&grid[x2][y2]=='X')|| grid[x1][y1]=='G'||grid[x2][y2]=='G')continue;
        if(grid[x1][y1]=='X'){
          x1=var.a;
          y1=var.b;
        }
        if(grid[x2][y2]=='X'){
          x2=var.c;
          y2=var.d;
        }
        if(marcados[x1][y1][x2][y2]||grid[x1][y1]=='G'||grid[x2][y2]=='G')continue;
        ruta[x1][y1][x2][y2].a=var.a;
        ruta[x1][y1][x2][y2].b=var.b;
        ruta[x1][y1][x2][y2].c=var.c;
        ruta[x1][y1][x2][y2].d=var.d;
        ruta[x1][y1][x2][y2].C=var.C;
        marcados[x1][y1][x2][y2]=1;
        colita.push(node(x1,y1,x2,y2,var.distancia+1,i));
      }
    }
    if(!(var.a==var.c&&var.b==var.d)){
      printf("IMPOSSIBLE\n");
      continue;
    }
    printf("%d ",var.distancia);
    while(!((var.a==P[0].first && var.b==P[0].second && var.c==P[1].first &&var.d==P[1].second))){
      resp.push_back(hash[var.C]);
      aux.a=ruta[var.a][var.b][var.c][var.d].a;
      aux.b=ruta[var.a][var.b][var.c][var.d].b;
      aux.c=ruta[var.a][var.b][var.c][var.d].c;
      aux.d=ruta[var.a][var.b][var.c][var.d].d;
      aux.C=ruta[var.a][var.b][var.c][var.d].C;
      var.a=aux.a;
      var.b=aux.b;
      var.c=aux.c;
      var.d=aux.d;
      var.C=aux.C;
    }
    for(int i=resp.size()-1;i>=0;i--)
      printf("%c",resp[i]);
    printf("\n");


  }
}
