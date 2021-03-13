#include <bits/stdc++.h>
using namespace std;
int N,M,K;
int numeros[100005];
long long ST[1000005];
long long ST2[1000005];
long long lazy2[1000005];
long long lazy[1000005];
void actualizar2(int index){
  if(index==0)return;
  int var;
  while(index!=0){
    var=(index-1)/2;
    ST2[var]=ST2[var*2+1]+ST2[var*2+2];
    index=var;
  }
  ST2[index]=ST2[index*2+1]+ST2[index*2+2];
}
void actualizar(int index){
  if(index==0)return;
  int var;
  while(index!=0){
    var=(index-1)/2;
    ST[var]=ST[var*2+1]+ST[var*2+2];
    index=var;
  }
  ST[index]=ST[index*2+1]+ST[index*2+2];
}
void construir(int index,int L,int R){
  if(L==R)
    ST[index]=numeros[L];
  else{
    construir(index*2+1,L,(L+R)/2);
    construir(index*2+2,(L+R)/2+1,R);
    ST[index]=ST[index*2+1]+ST[index*2+2];
  }
}
void aumentar(int index,int L,int R,int i,int j,long long v){
  if(L>=i && R<=j){
    ST[index]+=(R-L+1)*v;
    lazy[index]+=v;
    actualizar(index);
    return;
  }
  if(R<i || L>j){
    return;
  }
  ST[index*2+1]+=((R+L)/2-L+1)*lazy[index];
  ST[index*2+2]+=(R-((R+L)/2+1)+1)*lazy[index];
  lazy[index*2+1]+=lazy[index];
  lazy[index*2+2]+=lazy[index];
  lazy[index]=0;
  aumentar(index*2+1,L,(L+R)/2,i,j,v);
  aumentar(index*2+2,(L+R)/2+1,R,i,j,v);

}
long long consultar(int index,int L,int R,int i,int j){
  if(L>=i && R<=j){
    return ST[index];
  }
  if(R<i || L>j)
    return 0;
  ST[index*2+1]+=((R+L)/2-L+1)*lazy[index];
  ST[index*2+2]+=(R-((R+L)/2+1)+1)*lazy[index];
  lazy[index*2+1]+=lazy[index];
  lazy[index*2+2]+=lazy[index];
  lazy[index]=0;
  return consultar(index*2+1,L,(L+R)/2,i,j)+ consultar(index*2+2,(R+L)/2+1,R,i,j);
}
void aumentar2(int index,int L,int R,int i,int j,long long v){
  if(L>=i && R<=j){
    ST2[index]+=(R-L+1)*v;
    lazy2[index]+=v;
    actualizar2(index);
    return;
  }
  if(R<i || L>j){
    return;
  }
  ST2[index*2+1]+=((R+L)/2-L+1)*lazy2[index];
  ST2[index*2+2]+=(R-((R+L)/2+1)+1)*lazy2[index];
  lazy2[index*2+1]+=lazy2[index];
  lazy2[index*2+2]+=lazy2[index];
  lazy2[index]=0;
  aumentar2(index*2+1,L,(L+R)/2,i,j,v);
  aumentar2(index*2+2,(L+R)/2+1,R,i,j,v);

}
long long consultar2(int index,int L,int R,int i,int j){
  if(L>=i && R<=j){
    return ST2[index];
  }
  if(R<i || L>j)
    return 0;
  ST2[index*2+1]+=((R+L)/2-L+1)*lazy2[index];
  ST2[index*2+2]+=(R-((R+L)/2+1)+1)*lazy2[index];
  lazy2[index*2+1]+=lazy2[index];
  lazy2[index*2+2]+=lazy2[index];
  lazy2[index]=0;
  return consultar2(index*2+1,L,(L+R)/2,i,j)+ consultar2(index*2+2,(R+L)/2+1,R,i,j);
}
main(){
  memset(ST,0,sizeof ST);
  memset(lazy,0,sizeof lazy);
  memset(ST2,0,sizeof ST2);
  memset(lazy2,0,sizeof lazy2);
  scanf("%d%d%d",&N,&M,&K);
  int operaciones[100005][3];
  for(int i=0;i<N;i++)
    scanf("%d",&numeros[i]);
  construir(0,0,N-1);
  for(int i=0;i<M;i++){
    scanf("%d%d%d",&operaciones[i][0],&operaciones[i][1],&operaciones[i][2]);
  }
  int a,b;
  while(K--){
    scanf("%d%d",&a,&b);
    aumentar2(0,0,M-1,a-1,b-1,1);
  }
  for(int i=0;i<M;i++){
    aumentar(0,0,N-1,operaciones[i][0]-1,operaciones[i][1]-1,operaciones[i][2]*consultar2(0,0,M-1,i,i));
  }
  for(int i=0;i<N;i++)
    printf("%I64d ",consultar(0,0,N-1,i,i));
  

}
