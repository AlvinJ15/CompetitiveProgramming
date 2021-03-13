#include <bits/stdc++.h>
using namespace std;
main(){
	int test;
  scanf("%d",&test);
  int var=1;
  long long A,B;
  while(test--){
    scanf("%lld%lld",&A,&B);
    if(A==B)
      printf("Case %d: %lld %lld\n",var++,A,A);
    else{
      printf("Case %d: %lld %lld\n",var++,A|(2<<(int)(ceil(log(B-A+1)+0.0000000001))-1),A&~((2<<(int)(ceil(log(B-A+1)+0.0000000001)+1))-1));

    }
  }

}
