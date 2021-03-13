#include <bits/stdc++.h>
using namespace std;
int N;
long long ST[1000005];
long long lazy[1000005];
void actualizar(int index){
  if(!index)return;
  int var;
  while(index!=0){
    var=(index-1)/2;
    ST[var]=ST[var*2+1]+ST[var*2+2];
    index=var;
  }
  ST[index]=ST[index*2+1]+ST[index*2+2];
}
void aumentar(int index,int L, int R,int i,int j,long long val){
  if(L>=i && R<=j){
    ST[index]+=(R-L+1)*val;
    lazy[index]+=val;
    actualizar(index);
    return;
  }
  if(R<i || L>j)
    return;

  ST[index*2+1]+=((R+L)/2-L+1)*lazy[index];
  ST[index*2+2]+=(R-((R+L)/2+1)+1)*lazy[index];
  lazy[index*2+1]+=lazy[index];
  lazy[index*2+2]+=lazy[index];
  lazy[index]=0;
  aumentar(index*2+1,L,(L+R)/2,i,j,val);
  aumentar(index*2+2,(L+R)/2+1,R,i,j,val);
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
  return consultar(index*2+1,L,(R+L)/2,i,j)+consultar(index*2+2,(R+L)/2+1,R,i,j);
}
main(){
  int test;
  int Q,opcion,i,j;
  long long v;
	scanf("%d",&test);
  while(test--){
    memset(ST,0,sizeof ST);
    memset(lazy,0,sizeof lazy);
    scanf("%d%d",&N,&Q);
  //  if(N==1)
    //  N=2;
    while(Q--){
      scanf("%d",&opcion);
      if(opcion){
        scanf("%d%d",&i,&j);
        printf("%lld\n",consultar(0,0,N-1,i-1,j-1));
      }
      else{
        scanf("%d%d%lld",&i,&j,&v);
        aumentar(0,0,N-1,i-1,j-1,v);
      }
    }
  }

}
