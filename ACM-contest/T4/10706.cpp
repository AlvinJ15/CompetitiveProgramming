#include <bits/stdc++.h>
using namespace std;
main(){
	int T;
  long long n;
  scanf("%d",&T);
  int R,r;
  while(T--){

    scanf("%lld",&n);
    r=(-1+sqrt(1+8*n))/2;

    R=(r*(r+1))/2;
    R=n-R;
    if(!R)R=r;    
    cout<<R<<endl;

  }


}
