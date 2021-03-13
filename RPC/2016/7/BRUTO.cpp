#include <bits/stdc++.h>
using namespace std;
main(){
  int N;
  while(scanf("%d",&N)!=EOF){
    int var=N;
    int s=0;
    while(var){
      s+=var%10;
      var/=10;
    }
    s=abs(s);
    for(int i=N;true;i--){
      var=i;
      int s2=0;
      while(var){
        s2+=var%10;
        var/=10;
      }
      s2=abs(s2);
      if(s2==s+1){

        printf("%d\n",i);
        break;
      }
    }
  }	


}
