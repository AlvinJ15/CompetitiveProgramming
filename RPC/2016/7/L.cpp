#include <bits/stdc++.h>
using namespace std;
long long _sieve_size;
bitset<10000010> bs;
vector<int> primes;
void sieve(long long upperbound){
  _sieve_size = upperbound;
  bs.set();
  bs[0]=bs[1]=1;
  for(long long i=2;i<=_sieve_size;i++){
    if(bs[i]){
      for(long long j=i*i;j<=_sieve_size;j+=i){
        bs[j]=0;
      }
      primes.push_back((int)i);
    }
  }
  
}
vector<int> primeFactors(long long N){
  vector<int> factors;
  long long PF_idx=0,PF=primes[PF_idx];
  while(PF*PF<=N){
    while(N%PF==0){
      N/=PF;
      factors.push_back(PF);
    }
    PF=primes[++PF_idx];
  }
  if(N!=1)factors.push_back(N);
  return factors;
}
main(){
	int T;
  sieve(10000005);
  cin>>T;
  int num;
  vector<int> vA,vB;
  int cases=1;
  bool marcados[1000];
  bool flag;
  int digitos,A,B;
  set<int> myset;
  while(T--){
    printf("Ticket #%d:\n",cases++);
    scanf("%d",&num);
    digitos= (int)(floor(log10(num)))+1;
    int pot=pow(10,digitos-1);
    int i;
    for(i=digitos-1;i>=1;i--){
      A=num/pow(10,i);
      B=num-A*pow(10,i);
      vA=primeFactors(A);
      vB=primeFactors(B);
      myset.clear();
      for(int j=0;j<vA.size();j++){
        myset.insert(vA[j]);
      }
      flag=true;
      for(int j=0;j<vB.size();j++){
        const bool is_in = myset.find(vB[j])!=myset.end();
        if(is_in){
          flag=false;
        }
      }
      if(flag){
        printf("%d %d\n",A,B);
        break;
      }
    }
    if(i==0)
      printf("Not relative\n");
  }
}
