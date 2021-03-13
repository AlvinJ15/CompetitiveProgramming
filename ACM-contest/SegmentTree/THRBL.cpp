#include <bits/stdc++.h>
using namespace std;
int ST[1000005];
int numeros[10000005];
void construir(int index,int L,int R){
  if(L==R)
    ST[index]=numeros[L];
  else{
    construir(index*2+1,L,(R+L)/2);
    construir(index*2+2,(R+L)/2+1,R);
    ST[index]=max(ST[index*2+1],ST[index*2+2]);
  }
}
int consultar(int index,int L,int R,int i,int j){
  if(L>=i && R<=j)
    return ST[index];
  if(R<i || L>j)
    return -1;
  return max(consultar(index*2+1,L,(R+L)/2,i,j),consultar(index*2+2,(R+L)/2+1,R,i,j));
}
main(){
  int N,Q,i,j,count=0;
  scanf("%d%d",&N,&Q);
  for(int i=0;i<N;i++)
    scanf("%d",&numeros[i]);
  construir(0,0,N-1);
  while(Q--){
    scanf("%d%d",&i,&j);
    if(consultar(0,0,N-1,i-1,j-2)<=numeros[i-1])
      count++;
  }
  printf("%d\n",count);


}
