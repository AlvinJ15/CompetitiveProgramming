#include <bits/stdc++.h>
using namespace std;
int numeros[100005];
int ST[1000005];
int arr[100005];
void construir(int index,int L,int R){
  if(L==R){
    ST[index]=numeros[L];
    arr[L]=index;
  }
  else{
    construir(index*2+1,L,(R+L)/2);
    construir(index*2+2,(R+L)/2+1,R);
    ST[index]=min(ST[index*2+1],ST[index*2+2]);
  }
}
void actualizar(int index){
  if(!index)return;
  int var;
  while(index){
    var=(index-1)/2;
    ST[var]=min(ST[var*2+1],ST[var*2+2]);
    index=var;
  }
  ST[index]=min(ST[index*2+1],ST[index*2+2]);
}
int consultar(int index,int L,int R,int i ,int j){
  if(L>=i && R<=j)
    return ST[index];
  if(R<i || L>j)
    return 10000000;
  return min(consultar(index*2+1,L,(R+L)/2,i,j),consultar(index*2+2,(R+L)/2+1,R,i,j));
}
main(){
	int N,Q;
  char operaciones[100],c;
  int opeIndex[100];
  int indice,i,j,k,temp,var,pos;
  scanf("%d%d",&N,&Q);
  for(int i=0;i<N;i++)
    scanf("%d",&numeros[i]);
  construir(0,0,N-1);
  while(Q--){
    scanf("\n");
    indice=0;
    while(scanf("%c",&c),c!='\n'&&c!=EOF){
       operaciones[indice++]=c;
    }
    pos=0;
    if(operaciones[0]=='q'){
      for(i=6;i<indice;i++){
        var=0;
        while(operaciones[i]!=','&&operaciones[i]!=')'){
          var=var*10+operaciones[i++]-'0';
        }
        opeIndex[pos++]=var;
      }
      i=opeIndex[0]-1;
      j=opeIndex[1]-1;
      printf("%d\n",consultar(0,0,N-1,i,j));
    }
    else{
      for(i=6;i<indice;i++){
        var=0;
        while(operaciones[i]!=','&&operaciones[i]!=')'){
          var=var*10+operaciones[i++]-'0';
        }
        opeIndex[pos++]=var;
      }
      temp=ST[arr[opeIndex[0]-1]];
      for(k=1;k<pos;k++){
        i=opeIndex[k-1]-1;
        j=opeIndex[k]-1;
        ST[arr[i]]=ST[arr[j]];
        actualizar(arr[i]);
      }
      i=opeIndex[k-1]-1;
      ST[arr[i]]=temp;
      actualizar(arr[i]);
    }
  }


}
