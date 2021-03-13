#include <bits/stdc++.h>
using namespace std;
main(){
	
  int T;
  int maximo;
  int var,N,cases=1;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    maximo=-1;
    while(N--){
      scanf("%d",&var);
      maximo=max(maximo,var);
    }
    printf("Case %d: %d\n",cases++,maximo);
  }

}
