#include <bits/stdc++.h>
using namespace std;
int N,Q;
int ST[50000];
int lazy[50000];
void push(int index,int L,int R){
  int L1=index*2+1,R1=index*2+2;
  int a=lazy[index]%2;
  if(a==1){
    ST[L1]=(R+L)/2+1-L-ST[L1];
    ST[R1]=R-((R+L)/2+1)+1-ST[R1];
  }
  lazy[L1]+=lazy[index];
  lazy[R1]+=lazy[index];
  lazy[index]=0;
}
void encender(int index,int L,int R,int i,int j){
  if(L>=i && R<=j){
    lazy[index]++;
    ST[index]=R-L+1-ST[index];
    return;
  }
  if(R<i || L>j)
    return;
  push(index,L,R);
  encender(index*2+1,L,(R+L)/2,i,j);
  encender(index*2+2,(R+L)/2+1,R,i,j);
  ST[index]=ST[index*2+1]+ST[index*2+2];
}
int consultar(int index,int L,int R,int i,int j){
  if(L>=i && R<=j)
    return ST[index];
  if(R<i || L>j)
    return 0;
  push(index,L,R);
  return consultar(index*2+1,L,(R+L)/2,i,j)+consultar(index*2+2,(R+L)/2+1,R,i,j);

}
main(){
	scanf("%d%d",&N,&Q);
  memset(ST,0,sizeof ST);
  memset(lazy,0,sizeof lazy);
  int opcion,i,j;
  while(Q--){
    scanf("%d%d%d",&opcion,&i,&j);
    if(opcion)
      printf("%d\n",consultar(0,0,N-1,i-1,j-1));
    else
      encender(0,0,N-1,i-1,j-1);
  }


}
