#include <bits/stdc++.h>
using namespace std;
main(){
  int test,p,q,cases=1;
  long long minimo,maximo,var;
  scanf("%d",&test);
  while(test--){
    scanf("%d%d",&p,&q);
    maximo=-1;
    minimo=1000000000000000000;
    for(int i=0;i<(1<<p);i++){
      var=0;
      for(int j=0;j<p;j++){
        if(i&(1<<j)){
          var=var*10+1;
        }
        else
          var=var*10+2;
      }
      if(!(var%(1<<q))){
        minimo=min(minimo,var);
        maximo=max(maximo,var);
      }
    }
    if(maximo==-1)
      printf("Case %d: impossible\n",cases++);
    else
      if(maximo==minimo)
        printf("Case %d: %lld\n",cases++,minimo);
      else
      printf("Case %d: %lld %lld\n",cases++,minimo,maximo);
  

    
  }


}
