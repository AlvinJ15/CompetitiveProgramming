#include <bits/stdc++.h>
using namespace std;
main(){
   int test;
   int R,S,X,Y,W;
   int var=0;
   long long a,temp;
   long long total;
   cin>>test;
   while(test--){
      cin>>R>>S>>X>>Y>>W;
      total = pow(S,Y);
      var = S-R+1;
      a= pow(var,Y);
      temp=pow(var,X);
      if(Y!=X)
        temp*=pow(S-var,Y-X);
      else temp=0;
      temp*=Y;
      temp+=a;
    if(temp*W>total)
      printf("yes\n");
    else
      printf("no\n");
   }


}
