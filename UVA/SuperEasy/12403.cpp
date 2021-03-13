#include <bits/stdc++.h>
using namespace std;
main(){ 
  int T,v;
  char palabra[20];
  scanf("%d",&T);
  int R=0;
  while(T--){

    scanf("%6s",palabra);
    if(palabra[0]=='r')
      printf("%d\n",R);
    else{
      scanf("%d",&v);
      R+=v;
    }
      
  }


}
