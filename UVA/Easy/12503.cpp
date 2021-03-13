#include <bits/stdc++.h>
using namespace std;
main(){
	
  int T;
  char ins[100][20];
  char temp[100];
  scanf("%d",&T);
  int x,N,pos;
  while(T--){
    x=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
      scanf("%20s",ins[i]);
      
      if(ins[i][0]=='S'){
        scanf("%100s",temp);
        scanf("%d",&pos);
        pos--;
        if(ins[pos][0]=='R')
          x++;
        else
          x--;
        strcpy(ins[i],ins[pos]);
      }
      else{
        if(ins[i][0]=='R')
          x++;
        else
          x--;
      }

    }
    printf("%d\n",x);
  }

}
