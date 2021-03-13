#include <bits/stdc++.h>
using namespace std;
main(){
  int T;
  int a,b,c;
  int N;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    double R=0;
    while(N--){
      scanf("%d%d%d",&a,&b,&c);
      R+=((double)a/(double)b)*c*b;
    }
    printf("%d\n",(int)R);
  }
    


}
