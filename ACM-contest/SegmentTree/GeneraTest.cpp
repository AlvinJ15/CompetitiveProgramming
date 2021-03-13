#include <bits/stdc++.h>
using namespace std;
main(){
  int N,M,a,b;
	scanf("%d%d",&N,&M);
  printf("%d %d\n",N,M);
  for(int i=0;i<N;i++){
    printf("%d ",rand()%(1<<30)+1);
  }
  while(M--){
    a=(rand()%45000)+1;
    b=a+3566;
    printf("%d %d\n",a,b);
  }


}
