#include <bits/stdc++.h>
using namespace std;
int ST[100000];
int numeros[10005];
int construir(int index,int L,int R){
  if(L==R)
    ST[index]=numeros[L];
  else{
    construir(index*2+1,L,(R+L)/2);
    construir(index*2+2,(R+L)/2+1,R);
    ST[index]=ST[index*2+1]+ST[index*2+2];
  }
}
int consultar(int index,int L,int R,int i,int j){
  if(L>=i && R<=j)
    return ST[index];
  if(R<i || L>j)
    return 0;
  return   consultar(index*2+1,L,(R+L)/2,i,j)+consultar(index*2+2,(R+L)/2+1,R,i,j);
}
main(){
  int N,Q;
	scanf("%d",&N);
  int i=0,j;
  int n=N;
  while(n--){
    scanf("%d",&numeros[i++]);
  }
  construir(0,0,N-1);
  scanf("%d",&Q);
  while(Q--){
    scanf("%d%d",&i,&j);
    printf("%d\n",consultar(0,0,N-1,i-1,j-1));
  }

}
