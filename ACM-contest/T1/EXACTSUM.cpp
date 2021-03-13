#include <bits/stdc++.h>
using namespace std;
main(){
  int hash[1000009];
  int N,M,x,rx;
  int ans;
  while(scanf("%d",&N)!=EOF){
    ans=100000000;
    memset(hash,0,sizeof hash);
    for(int i=0;i<N;i++){
      scanf("%d",&x);
      hash[x]++;
    }
    scanf("%d",&M);
    for(int i=0;i<1000009;i++){
      if(i==M-i)continue;
      if(hash[i]>0){
        if(M-i<0 || M-i>1000005)continue;
        if(hash[M-i]>0){
          if(ans>abs(i-(M-i))){
            x=i;
            ans=abs(M-2*i);
          }
        }
      }
    }
    if(!(M%2))
      if(hash[M/2]>2)
        x=M/2;
     
    printf("Peter should buy books whose prices are %d and %d.\n\n",x,M-x);

  }	


}
