#include <bits/stdc++.h>
using namespace std;
int numeros[10005];
int ST[100005];
int lazy[100005];
long long size;
bitset<10000010> bs;
vector<int> primes;
void construir(int index,int L,int R){
  if(L==R){
    ST[index]=numeros[L];
  }
  else{
    construir(index*2+1,L,(L+R)/2);
    construir(index*2+2,(L+R)/2+1,R);
    ST[index]=ST[index*2+1]+ST[index*2+2];
  }
}
void actualizar(int index){
  if(!index)return;
  int var;
  while(index){
    var=(index-1)/2;
    ST[var]=ST[var*2+1]+ST[var*2+2];
    index=var;
  }
  ST[index]=ST[index*2+1]+ST[index*2+2];
 
}
void aumentar(int index,int L,int R,int i,int j,int v){
  if(L>=i && R<=j){
    lazy[index]=v;
    ST[index]=((R-L)+1)*v;
    actualizar(index);
    return;
  } 
  if(R<i || L >j)
    return;
  if(lazy[index]!=2){
    ST[index*2+1]=((R+L)/2-L+1)*lazy[index];
    ST[index*2+2]=(R-((R+L)/2+1)+1)*lazy[index];
    lazy[index*2+1]=lazy[index];
    lazy[index*2+2]=lazy[index];
    lazy[index]=2;
  }
  aumentar(index*2+1,L,(R+L)/2,i,j,v);
  aumentar(index*2+2,(R+L)/2+1,R,i,j,v);
}
int consultar(int index,int L,int R,int i ,int j){
  if(L>=i&&R<=j)
    return ST[index];
  if(R<i || L>j)
    return 0;
  if(lazy[index]!=2){
    ST[index*2+1]=((R+L)/2-L+1)*lazy[index];
    ST[index*2+2]=(R-((R+L)/2+1)+1)*lazy[index];
    lazy[index*2+1]=lazy[index];
    lazy[index*2+2]=lazy[index];
    lazy[index]=2;
  }
  return consultar(index*2+1,L,(R+L)/2,i,j)+consultar(index*2+2,(R+L)/2+1,R,i,j);
}
void sieve(long long u){
	size = u+1;
	bs.set();
	bs[0]=bs[1]=0;
	for(long long i=2;i<=size;i++)if(bs[i]){
		for(long long j=i*i;j<=size ;j+=i)
			bs[j]=0;
		primes.push_back((int)i);
	}
}
bool isPrime(long long N){
	if(N<=size)return bs[N];
	for(int i=0;i<(int)primes.size();i++)
		if(!(N%primes[i]))return false;
	return true;
}
main(){
  int N,Q,opcion,a,b,v;
  int test;
  int var=0;
	sieve(1000005);
	scanf("%d",&test);
  while(test--){
    var++;
    scanf("%d%d",&N,&Q);
    for(int i=0;i<N;i++){
      scanf("%d",&v);
      numeros[i]=bs[v];
    }
    for(int i=0;i<100000;i++)
      lazy[i]=2;
    construir(0,0,N-1);
    printf("Case %d:\n",var);
    while(Q--){
      scanf("%d",&opcion);
      if(opcion){
        scanf("%d%d",&a,&b);
        printf("%d\n",consultar(0,0,N-1,a-1,b-1));
      }
      else{
        scanf("%d%d%d",&a,&b,&v);
        aumentar(0,0,N-1,a-1,b-1,bs[v]);
      }
    }
    
  }
}
