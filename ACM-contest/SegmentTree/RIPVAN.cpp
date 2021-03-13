#include <bits/stdc++.h>
using namespace std;
#define II *2+1
#define DD *2+2
#define mid (R+L)/2
typedef long long ll;
long long ST[2000010];
long long lazyA[2000010][2];
long long lazyB[2000010][2];
long long lazyC[2000010];
long long A(ll index,ll L,ll R,ll i,ll j,ll v);
long long B(ll index,ll L,ll R,ll i,ll j,ll v);
long long C(ll index,ll L,ll R,ll i,ll j,ll v);
void push(ll index,ll L,ll R){
  long long n,m,total=R-L+1;
  if(lazyC[index]!=1<<30){
    ST[index II]=C(index II,L,mid,L,mid,lazyC[index]);
    ST[index DD]=C(index DD,mid+1,R,mid+1,R,lazyC[index]);
    ST[index]=ST[index II]+ST[index DD];
    lazyC[index]=1<<30;
  } if(lazyA[index][0]!=0){
    ST[index]=
    /*ST[index II]=*/ A(index II,L,mid,L,mid,lazyA[index][0])+
   /* ST[index DD]=*/ A(index DD,mid+1,R,mid+1,R,lazyA[index][0]+(mid-L+1));
    total=((total-1)*total)/2;
    n=mid-L+1;
    m=R-(mid+1)+1;
    ST[index II]+=(((n-1)*n)/2)*(lazyA[index][1]-1);
    ST[index DD]+=(total-(((n-1)*n)/2))*(lazyA[index][1]-1);
    ST[index]=ST[index II]+ST[index DD];
    lazyA[index DD][0]+=n*(lazyA[index][1]-1);
    lazyA[index][0]=0;
    lazyA[index II][1]+=lazyA[index][1]-1;
    lazyA[index DD][1]+=lazyA[index][1]-1;
    lazyA[index][1]=0;
      //cout<<"0: "<<lazyA[index][0]<<" 1: "<<lazyA[index][1]<<endl;
  }
  total=R-L+1;
    if(lazyB[index][0]!=0&&lazyB[index][1]!=0){
      n=mid-L+1;
    ST[index]=    B(index II,L,mid,L,mid,lazyB[index][0])+B(index DD,mid+1,R,mid+1,R,lazyB[index][0]-n);
    total=((total-1)*total)/2;
    n=mid-L+1;
    ST[index II]-=(((n-1)*n)/2)*(lazyB[index][1]-1);
    ST[index DD]-=(total-(((n-1)*n)/2))*(lazyB[index][1]-1);
    ST[index]=ST[index II]+ST[index DD];
    lazyB[index DD][0]-=n*(lazyB[index][1]-1); 
    lazyB[index][0]=0;
    lazyB[index II][1]+=lazyB[index][1]-1;
    lazyB[index DD][1]+=lazyB[index][1]-1;
    lazyB[index][1]=0;
      //cout<<"0: "<<lazyB[index][0]<<" 1: "<<lazyB[index][1]<<endl;
    }
}
//1 2 3 4
long long A(ll index,ll L,ll R,ll i,ll j,ll v){
  long long n;
  if(L>=i && R<=j){
    lazyA[index][0]+=v;
    lazyA[index][1]++;
    n=R-L+1;
    return ST[index]+=((n)*(v))+((n*(n-1))/2);
  }
  if(R< i || L>j)return ST[index];
  push(index,L,R);
  return ST[index]=A(index II ,L, mid ,i,j,v)+A(index DD, mid +1,R,i,j,mid-i+2);
}
//4 3 2 1
long long B(ll index,ll L,ll R,ll i,ll j,ll v){
  long long n;
  if(L>=i && R<=j){
    lazyB[index][0]+=v;
    lazyB[index][1]++;
    n=R-L+1;
    return ST[index]+=((n)*(v-(n)))+((n*(n+1))/2);
  }
  if(R<i || L>j)return ST[index];
  push(index,L,R);
  return ST[index]=(long long)B(index II ,L, mid ,i,j,v)+(long long)B(index DD , mid +1,R,i,j,j-mid);
}
long long C(long long index,long long L,long long R,long long i,ll j,long long v){
  if(L>=i && R<=j){
    lazyC[index]=v;
    lazyA[index][0]=0;
    lazyA[index][1]=0;
    lazyB[index][0]=0;
    lazyB[index][1]=0;
    ST[index]=(R-L+1)*lazyC[index];
    return ST[index];
  }
  if(R<i || L>j)return ST[index];
  push(index,L,R);
  return ST[index]=C(index II ,L, mid ,i,j,v)+ C(index DD , mid +1,R,i,j,v);
}
long long consultar(ll index,ll L,ll R,ll i,ll j){
  if(L>=i && R<=j){
    return ST[index];}
  if(R<i || L>j)return 0;
  push(index,L,R);
  return consultar(index II ,L, mid ,i,j)+consultar(index DD , mid +1,R,i,j);
}
main(){
  long long Q,i,j,v;
  scanf("%lld",&Q);
  char c;
  memset(ST,0,sizeof ST);
  memset(lazyA,0,sizeof lazyA);
  memset(lazyB,0,sizeof lazyB);
  for(int i=0;i<2000005;i++){
    lazyC[i]=1<<30;
  }
  while(Q--){
    scanf("\n");
    scanf("%c",&c);
    if(c=='A'){
      scanf("%lld%lld",&i,&j);
      A(0,0,250000,i,j,1);
    }
    if(c=='B'){
      scanf("%lld%lld",&i,&j);
      B(0,0,250000,i,j,j-i+1);

    }
    if(c=='C'){
      scanf("%lld%lld%lld",&i,&j,&v);
      C(0,0,250000,i,j,v);
    
    }
    if(c=='S'){
      scanf("%lld%lld",&i,&j);
      printf("%lld\n",consultar(0,0,250000,i,j));
    
    }
  }
	


}
