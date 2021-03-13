#include <bits/stdc++.h>
using namespace std;
main(){
  int T;
  long long a,b;
  scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&a,&b);
    if(a==b)
      printf("=\n");
    if(a>b)
      printf(">\n");
    if(a<b)
      printf("<\n");
  }


}
