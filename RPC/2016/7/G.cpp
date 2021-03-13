#include <bits/stdc++.h>
using namespace std;
main(){
  int N,var,suma,total;
  char s[100];
  while(true){
    memset(s,0,sizeof s);
    scanf("%100s",s);
    if(s[0]=='E')break;
    N=0;

    for(int i=0;i<100;i++){
      if(s[i]==0)break;
      N=N*10+s[i]-'0';

    }
    total=0;
    var=N;
    while(var!=0){
      total+=var%10;
      var/=10;
    }
    for(int i=N;i>=0;i--){
      var=i;
      suma=0;
      while(var!=0){
        suma+=var%10;
        var/=10;
      }
      if(suma<total){
        printf("%d\n",i);
      break;       
     }
      
    }
  }

}
