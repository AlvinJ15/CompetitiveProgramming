#include <bits/stdc++.h>
using namespace std;
bool marcados[4][4];
bool encontrados[101];
string palabras [101];
int px[]={1,1,0,-1,-1,-1,0,1};
int py[]={0,1,1,1,0,-1,-1,-1};
char grid[4][4];

void recursion(int x,int y,int pos,int M,int p){
  //cout<<x<<" "<<y<<" "<<pos<<" "<<M<<" "<<p<<endl;
  int xx,yy;
  if(encontrados[p])return;
  if(pos==M){
    encontrados[p]=1;
    return;
  }
  for(int i=0;i<8;i++){
    xx=x+px[i];
    yy=y+py[i];
    if(xx<0 || yy<0 || xx>=4 || yy >=4)
      continue;
    else{

      if(marcados[xx][yy]!=1 && grid[xx][yy]==palabras[p][pos]){
        marcados[xx][yy]=1;
        recursion(xx,yy,pos+1,M,p);
        marcados[xx][yy]=0;
      }
    }
  }

}
main(){
  int test,cases=1,M,score;	
  int puntos[]={1,1,1,1,1,2,3,5,11,11,11,11,11,11,11,11,11,11,11,11,11,11};
  cin>>test;
  while(test--){
    memset(encontrados,0,sizeof encontrados);
    score=0;
        scanf("\n");
       for(int i=0;i<4;i++){
        scanf("\n");
        for(int j=0;j<4;j++){
          scanf("%c",&grid[i][j]);
        }
       }
       scanf("%d",&M);
       for(int i=0;i<M;i++){
         cin>>palabras[i];
         for(int h=0;h<4;h++){
          for(int k=0;k<4;k++){
            if(!encontrados[i])
              if(grid[h][k]==palabras[i][0]){
                memset(marcados,0,sizeof marcados);
                marcados[h][k]=1;
                recursion(h,k,1,palabras[i].size(),i);
                marcados[h][k]=0;
              }
          }
         }
        if(encontrados[i]){
          score+=puntos[palabras[i].size()];
        }

       }
       printf("Score for Boggle game #%d: %d\n",cases++,score);


         
  }

}

