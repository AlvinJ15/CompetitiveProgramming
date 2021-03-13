#include <bits/stdc++.h>
using namespace std;
main(){
  int N,M,a,b,K;
  while(scanf("%d",&K),K){
    scanf("%d%d",&N,&M);
    while(K--){
      scanf("%d%d",&a,&b);
      if(a==N||b==M)
        printf("divisa");
      if(a>N && b>M)
        printf("NE");
      if(a<N&&b<M)
        printf("SO");
      if(a<N && b>M)
        printf("NO");
      if(a>N && b<M)
        printf("SE");
      printf("\n");
    }
  }	


}
