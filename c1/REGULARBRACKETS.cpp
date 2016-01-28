#include <bits/stdc++.h>
using namespace std;
main(){
  int sum,maximo,cnt;
  char c;
  cnt=0;
  maximo=sum=0;
  while((c=getchar())!=EOF){
    if(c=='('){
      sum++;
     }
     if(c==')'){
       if(sum>0){
         sum--;
         cnt++;
       }
       else{
         sum=0;
       }
     }
  }	
  printf("%d\n",cnt*2);


}
