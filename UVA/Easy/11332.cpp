#include <bits/stdc++.h>
using namespace std;
main(){
	int N,suma;
  while(scanf("%d",&N),N){
    while(N>=10){
      suma=0;
      while(N){
        suma+=N%10;
        N/=10;
      }
      N=suma;
    }
    printf("%d\n",N);
  }

}
