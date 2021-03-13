#include <bits/stdc++.h>
using namespace std;
main(){
  long long M,Z;
  int cases=1;
  long long suma=0;
  while(scanf("%lld",&M),M){
    suma+=M;
    if(suma>=100){
      printf("Input #%d: Totally Sweet!\n",cases);
      suma%=50;
    }
    if(suma<100 && suma>= 50){
      printf("Input #%d: Sweet!\n",cases);
      suma=suma-=50;
    }
    cases++;
  }


}
