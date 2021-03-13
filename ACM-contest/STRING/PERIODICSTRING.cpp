#include <bits/stdc++.h>
using namespace std;
main(){
  int test;
  int var=1;
  cin>>test;
  string palabra;
  scanf("\n");
  int h;
  while(test--){
    if(var!=1)
      printf("\n");
    var++;
    cin>>palabra;
    for(int i=1;i<=palabra.size();i++){
      h=0;
      for(h=0;h<palabra.size();h++){
        if(palabra[h]!=palabra[h%i])
          break;
      }
      if(h==palabra.size()&& palabra.size()%i==0){
        printf("%d\n",i);
        break;
      }
    }

  }


}
