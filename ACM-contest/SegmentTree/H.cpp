#include <bits/stdc++.h>
#define mid (R+L)/2
#define II *2+1
#define DD *2+2
using namespace std;
int M;
int ST[100000];
long long arr[5005];
void build(int index,int L,int R){
  if(L==R){
    ST[index]=L;
  }
  else{
    build(index II,L,mid);
    build(index DD,mid+1,R);
    ST[index] =arr[ST[index II]]<arr[ST[index DD]]?ST[index II]:ST[index DD];
  }
}
int cambiar(int index,int L,int R,int i,int j,int val){
  if(L>=i&& R<=j){
    arr[i]+=val;
    return i;
  }
  if(R<i || L>j)
    return ST[index];
  return ST[index]= arr[cambiar(index II,L,mid,i,j,val)]<arr[cambiar(index DD,mid+1,R,i,j,val)]?ST[index II]:ST[index DD];
}
int consultar(int index,int L,int R,int i,int j){
  if(L>=i&&R<=j)
    return ST[index];
  if(R<i || L>j)
    return 5000;
  int A=consultar(index II,L,mid,i,j);
  int B=consultar(index DD,mid+1,R,i,j);
  return arr[A]<arr[B]?A:B;
}
int hash[20];
main(){
  int menor,Q,a,b;
	while(scanf("%d",&M),M){
    scanf("%d",&Q);
    memset(hash,0,sizeof hash);
    for(int i=0;i<Q;i++){
      scanf("%d%d",&a,&b);
      hash[(int)log2(a)]=b;
    }
    memset(arr,0,sizeof arr);
    arr[5000]=10000000000000000;
    arr[4999]=0;
    build(0,0,M-1);
    for(int i=18;i>=0;i--){
      for(int j =0;j<hash[i];j++){
        menor=consultar(0,0,M-1,0,M-1);
        cambiar(0,0,M-1,menor,menor,1<<i);
      }
    }
    long long men;
    for(int i=0;i<M;i++){
      men=max(men,arr[i]);
    }
    printf("%lld\n",men);
  }



}
