#include <bits/stdc++.h>
using namespace std;
int ST[1000005];
int numeros[1000005];
int aux[1000005];
int N;
int K;
void build(int index,int L,int R){
  if(L==R){
    ST[index]=numeros[L];
    aux[L]=index;
  }
  else{
    build(index*2+1,L,(L+R)/2);
    build(index*2+2,(L+R)/2+1,R);
    ST[index]=ST[index*2+1]*ST[index*2+2];
  }
}
int consulta(int index,int L,int R,int i,int j){
  if(L>=i&&R<=j)
    return ST[index];
  if(R<i || L>j)
    return 1;
  return consulta(index*2+1,L,(L+R)/2,i,j)*consulta(index*2+2,(L+R)/2+1,R,i,j);
}
void actualizar(int  a,int b){
  numeros[a]=b;
  if(b>0)
    b=1;
  if(b<0)
    b=-1;
  ST[aux[a]]=b;
  a=aux[a];
  while(a!=0){
    a=(a-1)/2;
    ST[a]=ST[a*2+1]*ST[a*2+2];
  }
  ST[a]=ST[a*2+1]*ST[a*2+2];
}
main(){
  char c;
  int a,b,r;
  while(scanf("%d%d",&N,&K)!=EOF){
    for(int i=0;i<N;i++){
      scanf("%d",&numeros[i]);
      if(numeros[i]==0)
        numeros[i]=0;
      if(numeros[i]>0)
        numeros[i]=1;
      if(numeros[i]<0)
        numeros[i]=-1;
    }
    build(0,0,N-1);
    for(int i=0;i<K;i++){
      scanf("\n");
      scanf("%c",&c);
      if(c=='C'){
        scanf("%d%d",&a,&b);
        actualizar(a-1,b);
      }
      if(c=='P'){
        scanf("%d%d",&a,&b);
        r=consulta(0,0,N-1,a-1,b-1);
        if(r>0)
          printf("%c",'+');
        if(r<0)
          printf("%c",'-');
        if(!r)
          printf("%c",'0');
      }
    
    }
    printf("\n");
  }
  

}
