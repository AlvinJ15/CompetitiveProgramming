#include <bits/stdc++.h>
using namespace std;
main(){
  int T,N,K;
  cin>>T;
  while(T--){
    scanf("%d%d",&N,&K);

    int raiz = floor(sqrt(N));
    long long sum=0;
    for(int i=1;i<=raiz;i++){
        if(N%i==0){
          if(i%K)
            sum+=i;
          if((N/i)%K)
            sum+=(N/i);

        }
    }
    if(raiz*raiz==N && raiz%K)sum-=raiz;
    printf("%lld\n",sum);
  }


}
