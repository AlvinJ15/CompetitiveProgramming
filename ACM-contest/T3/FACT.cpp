#include <bits/stdc++.h>
using namespace std;
bool prime(int x){
  for(int i=2;i<x;i++){
    if(x%i==0)return false;
  }
  return true;
}
int arr[501][200000];
int arr2[900000000];
main(){
  vector<int> primos;
  int N;
  for(int i=2;i<10002;i++){
    if(prime(i))
      primos.push_back(i);
  }
  int hash[10002],var;
  while(scanf("%d",&N)!=EOF){
    memset(hash,0,sizeof hash);
    for(int i=2;i<=N;i++){
      var=i;
      for(int j=0;j<primos.size()&&var!=1;j++){
        while(var%primos[j]==0)  
        if(var%primos[j]==0){
            var/=primos[j];
            hash[primos[j]]++;
          }
      }
    }
    hash[2]-=hash[5];
    hash[5]=0;
    int prod=1;
    for(int i=2;i<10002;i++){
      for(int j=0;j<hash[i];j++){
        prod*=i;
        prod%=10;
      }
    }
    int tam=log10(N)+1;
    for(int i=0;i<5-tam;i++)
      printf(" ");
    printf("%d -> %d\n",N,prod);
  }


}
