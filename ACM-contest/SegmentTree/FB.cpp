#include <bits/stdc++.h>
using namespace std;
long long ST[1000005];
int numeros[100005];
void construir(int index,int L,int R){
  if(L==R)
    ST[index]=numeros[R];
  else{
    construir(index*2+1,L,(R+L)/2);
    construir(index*2+2,(L+R)/2+1,R);
    ST[index]=ST[index*2+1]+ST[index*2+2];
  }
}
long long consulta(int index,int L,int R,int i ,int j){
  if(L>=i && R<=j)
    return ST[index];
  if(R<i || L>j)
    return 0;
  return consulta(index*2+1,L,(R+L)/2,i,j)+consulta(index*2+2,(L+R)/2+1,R,i,j);
}
main(){
	int test;
  int var=0;
  int N,P;
  long long count;
  scanf("%d",&test);
  while(test--){
    var++;
    count=0;
    memset(ST,0,sizeof ST);
    scanf("%d%d",&N,&P);
    for(int i=0;i<N;i++)
      scanf("%d",&numeros[i]);
    construir(0,0,N-1);
    for(int i=0;i<N;i++)
      for(int j=i;j<N;j++)
        if(consulta(0,0,N-1,i,j)<=P){
          count++;}
   printf("Case #%d: %lld\n",var,count);

  }


}
