#include <bits/stdc++.h>
using namespace std;
int ST[1000005][3];
int lazy[1000005];
int N,Q;
void rotar(int index,int v){
  int a= v%3;
  if(a==1){
    swap(ST[index][1],ST[index][2]);
    swap(ST[index][1],ST[index][0]);
  }
  if(a==2){
    swap(ST[index][0],ST[index][2]);
    swap(ST[index][1],ST[index][0]);
  }
}
void push(int index){
  int L=index*2+1,R=index*2+2;
  rotar(L,lazy[index]);
  rotar(R,lazy[index]);
  lazy[L]+=lazy[index];
  lazy[R]+=lazy[index];
  lazy[index]=0;
}
void sumar(int index){
    ST[index][0]=ST[index*2+1][0]+ST[index*2+2][0];
    ST[index][1]=ST[index*2+1][1]+ST[index*2+2][1];
    ST[index][2]=ST[index*2+1][2]+ST[index*2+2][2];
}
void actualizar(int index){
  if(!index)return;
  int var;
  while(index){
    var=(index-1)/2;
    sumar(var);
    index=var;
  }
  sumar(index);
}
void construir(int index,int L,int R){
  if(L==R){
    ST[index][0]=1;
    ST[index][1]=0;
    ST[index][2]=0;
  }
  else{
    construir(index*2+1,L,(L+R)/2);
    construir(index*2+2,(R+L)/2+1,R);
    sumar(index);
  }
}
void aumentar(int index,int L,int R,int i,int j){
  if(L>=i && R<=j){
    rotar(index,1);
    //actualizar(index);
    lazy[index]+=1;
    return;
  }
  if(R<i || L>j)
    return;
  push(index);
  aumentar(index*2+1,L,(R+L)/2,i,j);
  aumentar(index*2+2,(R+L)/2+1,R,i,j);
  sumar(index);
}
int consultar(int index,int L,int R,int i ,int j){
  if(L>=i && R<=j)
    return ST[index][0];
  if(R<i || L>j)
    return 0;
  push(index);
  return consultar(index*2+1,L,(R+L)/2,i,j)+consultar(index*2+2,(L+R)/2+1,R,i,j);
}
main(){
  	scanf("%d%d",&N,&Q);
    construir(0,0,N-1);
    memset(lazy,0,sizeof lazy);
    int opcion,i,j;
    while(Q--){
      scanf("%d%d%d",&opcion,&i,&j);
      if(opcion)
        printf("%d\n",consultar(0,0,N-1,i,j));
      else
        aumentar(0,0,N-1,i,j);
      
        
    }

}
