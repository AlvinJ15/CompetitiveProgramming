#include <bits/stdc++.h>
#define mid (R+L)/2
#define II *2+1
#define DD *2+2
using namespace std;
char grid[501][501];
int ST[501][2005];
int lazy[501][2005];
int N,M,Q;
int aumentar(int index,int L,int R,int i,int j,int v,int D);

void push(int index,int L,int R,int D){
  ST[D][index II]=aumentar(index II,L,mid,L,mid,lazy[D][index],D);
  ST[D][index DD]=aumentar(index DD,mid+1,R,mid+1,R,lazy[D][index],D);
  lazy[D][index]=0;
}
int aumentar(int index,int L,int R,int i,int j,int v,int D){
  if(L>=i && R<=j){
    lazy[D][index]+=v;
    return ST[D][index]+=(R-L+1)*v;
  }
  if(R<i || L>j)return ST[D][index];
  push(index,L,R,D);
  return ST[D][index]=aumentar(index II ,L,mid,i,j,v,D)+aumentar(index DD,mid+1,R,i,j,v,D);
}
int consultar(int index,int L,int R,int i,int j,int D){
  if(L>=i && R<=j)
    return ST[D][index];
  if(R<i || L>j)return 0;
  push(index,L,R,D);
  return consultar(index II,L,mid,i,j,D)+consultar(index DD,mid+1,R,i,j,D);
}
void sw(int &a,int &b){
  int temp= b;
  b=a;
  a=N-temp+1;
}
main(){
  int T,a,b,c,d;
  int NR,NB;
  scanf("%d",&T);
  while(T--){
    NR=NB=0;
    memset(ST,0,sizeof ST);
    memset(lazy,0,sizeof lazy);
    scanf("%d%d%d",&N,&M,&Q);
    for(int i=0;i<N;i++){
      scanf("\n");
      for(int j=0;j<M;j++){
        scanf("%c",&grid[i][j]);
      }
    }
    while(Q--){
      scanf("%d%d%d%d",&a,&b,&c,&d);
      sw(a,b);sw(c,d);
      a--;b--;c--;d--;
      for(int i=c;i<=a;i++){
        aumentar(0,0,M-1,b,d,1,i);
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(consultar(0,0,M-1,j,j,i)){
          if(grid[i][j]=='R')
            NR++;
          if(grid[i][j]=='B')
            NB++;
        }
      }
    }
    printf("%d %d\n",NB,NR);
  }


}
