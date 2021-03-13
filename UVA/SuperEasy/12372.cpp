#include <bits/stdc++.h>
using namespace std;
main(){
	int T,cases=1,a,b,c;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&a,&b,&c);
    printf("Case %d: ",cases++);
    if(a<=20&&b<=20&&c<=20)
    printf("good");
    else
    printf("bad");
    printf("\n");
  }


}
