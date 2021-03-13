#include <bits/stdc++.h>
using namespace std;
main(){
	int N,ant,act;
  int U,T,D,cases=1;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    ant=-1;
    U=D=0;
    for(int i=0;i<N;i++){
      scanf("%d",&act);
      if(ant<act)U++;
      if(ant>act)D++;
      ant=act;
    }
    printf("Case %d: %d %d\n",cases++,U-1,D);
  }


}
