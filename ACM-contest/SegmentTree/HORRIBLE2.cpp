#include <bits/stdc++.h>
using namespace std;
#define mid (R+L)/2
#define II *2+1
#define DD *2+2
long long ST[400000];
long long lazy[400000];

long long aumentar(int index,int L,int R,int i,int j,long long val);
void push(int index,int L,int R){
  ST[index II]=aumentar(index II,L,mid,L,mid,lazy[index]);
  ST[index DD]=aumentar(index DD,mid+1,R,mid+1,R,lazy[index]);
  lazy[index]=0;
}
long long aumentar(int index,int L,int R,int i,int j,long long val){
  if(L>=i &&R<=j){
    lazy[index]+=val; 
    return ST[index]+=(R-L+1)*val;
  }
  if(R<i || L>j)
    return ST[index];
  push(index,L,R);
  return ST[index]=aumentar(index II,L,mid,i,j,val)+aumentar(index DD,mid+1,R,i,j,val);
}
long long consultar(int index,int L,int R,int i,int j){
  if(L>=i && R<=j)
    return ST[index];
  if(R<i || L>j)return 0;
  push(index,L,R);
  return consultar(index II,L,mid,i,j)+consultar(index DD,mid+1,R,i,j);
}
main(){
  int T,N,C;
  scanf("%d",&T);
  int opcion,a,b,v;
  while(T--){
    memset(ST,0,sizeof ST);
    memset(lazy,0,sizeof lazy);
    scanf("%d%d",&N,&C);
    for(int i=0;i<C;i++){
      scanf("%d",&opcion);
      if(!opcion){
        scanf("%d%d%d",&a,&b,&v);
        aumentar(0,0,N-1,a-1,b-1,v);
      }
      else{
        scanf("%d%d",&a,&b);
        printf("%lld\n",consultar(0,0,N-1,a-1,b-1));
      }
    }
  }


}
