#include <bits/stdc++.h>
using namespace std;
main(){
  int arr[20];
	  int N,M,F,pos,bitmask,C,maximo,cases=1;
    while(scanf("%d%d%d",&N,&M,&F),N|M|F){
      printf("Sequence %d\n",cases++);
      for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
      }
      bitmask=0;
      C=0,maximo=-1;
      while(M--){
        scanf("%d",&pos);
        pos--;
        if(bitmask&(1<<pos))
          C-=arr[pos];
        else
          C+=arr[pos];
        maximo=max(maximo,C);
        bitmask^=(1<<pos);
      }
      if(maximo>F)
        printf("Fuse was blown.\n");
      else{
        printf("Fuse was not blown.\n");
        printf("Maximal power consumption was %d amperes.\n",maximo);
      }
      printf("\n");
    }


}
