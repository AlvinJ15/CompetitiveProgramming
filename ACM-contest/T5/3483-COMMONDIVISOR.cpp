#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100010
bool mark[MAX_N];
vector<int> primes;
void genPrimes(int n){
  for(long long i=2;i<n;i++){
    if(!mark[i]){
      primes.push_back(i);
      for(long long j=i*i;j<n;j+=i){
        mark[j]=1;
      }
    }
  }
}
main(){
  int T;
  cin>>T;
  memset(mark,0,sizeof mark);
  genPrimes(MAX_N-10);
 /* for(int i=0;i<100;i++){
    cout<<primes[i]<<" ";
  }
  cout<<endl;
  */
  long long N,M;
  int hA[MAX_N];
  int hB[MAX_N];
  while(T--){
    scanf("%lld%lld",&N,&M);
    int i=0;
    memset(hA,0,sizeof hA);
    memset(hB,0,sizeof hB);
    while(N!=1){
      while(!(N%primes[i])){
        hA[primes[i]]++;
        N/=primes[i];
      }
      i++;
    }
    i=0;
    while(M!=1){
      while(!(M%primes[i])){
        hB[primes[i]]++;
        M/=primes[i];
      }
      i++;
    }
    vector<int> resp;
    for(i=2;i<MAX_N;i++){
      if(hA[i] && hB[i]){
        resp.push_back(min(hA[i],hB[i])+1);
      }
    }
    long long total=1;
    for(i=0;i<resp.size();i++){
      total*=resp[i];
    }
    printf("%lld\n",total);
  }


}
