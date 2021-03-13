#include <bits/stdc++.h>
using namespace std;
main(){
  int R,n,v,cases=1;;
  while(scanf("%d",&n),n){
    R=0;
    while(n--){
      scanf("%d",&v);
      v?R++:R--;
    }
    printf("Case %d: %d\n",cases++,R);
  }	


}
