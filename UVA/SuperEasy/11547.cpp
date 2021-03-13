#include <bits/stdc++.h>
using namespace std;
main(){
  int T,n;
  long long R;
  scanf("%d",&T);
  
  while(T--){
    scanf("%d",&n);
    R=(((n*567)/9+7492)*235)/47-498;
    R=abs(R);
    printf("%d\n",(int)((R%100)/10));
  }


}
