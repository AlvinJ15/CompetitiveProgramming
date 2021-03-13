#include <bits/stdc++.h>
using namespace std;
main(){
	int T,val;
  char palabra[10][102];
  int valores[10];
  int cases=1;
  scanf("%d",&T);
  int maximo;
  while(T--){
    maximo=-1;
    for(int i=0;i<10;i++){
      scanf("%102s%d",palabra[i],&valores[i]);
      maximo=max(maximo,valores[i]);
    }
    printf("Case #%d:\n",cases++);
    for(int i=0;i<10;i++){
      if(valores[i]==maximo)
        printf("%s\n",palabra[i]);
    }
  }


}
