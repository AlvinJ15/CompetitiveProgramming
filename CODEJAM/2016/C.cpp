#include <bits/stdc++.h>
using namespace std;
void imprimir(){cout<<"ERROR"<<endl;}
long long _sieve_size;
bitset<100000010> bs;
vector<int> primes;
void sieve(long long upperbound){
	_sieve_size=upperbound+1;
	bs.set();
	bs[0]=bs[1]=0;
	for(long long i=2;i<=_sieve_size;i++)if(bs[i]){
		for(long long j=i*i;j<=_sieve_size ;j+=i)bs[j]=0;
			primes.push_back((int)i);
	}
}
bool isPrime(long long N){
  if(N<0)cout<<"asdsadsa"<<endl;
	if(N<=_sieve_size)return bs[N];
	for(int i=0;i<(int)primes.size();i++)
		if(N%primes[i]==0)return false;
			return true;
}
int factor(long long N){
  for(int i=0;i<N;i++){
    if(N%primes[i]==0)return primes[i];
  }
  return 0;
}
long long powi(long long a,int b){
  if(b==1)return a;
  if(b%2==0)
    return powi(a,b/2)*powi(a,b/2);
  else{
    return powi(a,b/2+1)*powi(a,b/2);
  }
}
vector<int> bin;
vector<long long> resp[51];
long long ans[12];
	main(){
		sieve(10000000000000000);
		int T,cases=1,h,N,M;
		scanf("%d",&T);
		while(T--){
			scanf("%d%d",&N,&M);
			memset(ans,1,sizeof ans);
			int c=0;
			for(int i=0;i<(1<<(N-2))&&bin.size()<M;i++){
				for(int j=2;j<=10;j++)
					ans[j]=powi(j,N-1)+1;
				for(int j=0;j<N-2;j++){
					if((1<<j)&i){
						for(h=2;h<=10;h++){
							ans[h]+=powi(h,j+1);
						}
					}
				}
				for(h=2;h<=10;h++){
					if(isPrime(ans[h]))
						break;
				}
				if(h==11){
					bin.push_back(i);
					for(int h=2;h<=10;h++)
						resp[c].push_back(ans[h]);
					c++;
				}
			}
		}
    printf("Case #1:\n");
    for(int i=0;i<M;i++){
      if(i!=0)
        printf("\n");
      printf("1");
      for(int j=N-3;j>=0;j--){
        if(bin[i]&(1<<j))
          printf("1");
        else
          printf("0");
      }
      printf("1");
      for(int j=0;j<resp[i].size();j++)
        printf(" %d",factor(resp[i][j]));
    }
    
		
	}
