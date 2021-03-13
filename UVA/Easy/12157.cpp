#include <bits/stdc++.h>
using namespace std;
main(){
	int T,val,M,J,N,cases=1;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    J=0;
    M=0;
    for(int i=0;i<N;i++){
      scanf("%d",&val);
      val++;
      M+=ceil(val/(double)30)*10;
      J+=ceil(val/(double)60)*15;
    }
    if(J==M)
      printf("Case %d: Mile Juice %d\n",cases++,M);
    else if(J<M)
      printf("Case %d: Juice %d\n",cases++,J);
    else
      printf("Case %d: Mile %d\n",cases++,M);
  }
    


}
