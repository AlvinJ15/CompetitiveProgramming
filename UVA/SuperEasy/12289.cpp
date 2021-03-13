#include <bits/stdc++.h>
using namespace std;
main(){
  int T,A;
  scanf("%d",&T);
  string palabra;
  while(T--){
    cin>>palabra;
    if(palabra.size()==5)
      printf("%d\n",3);
    else{
      A=0;
      A+=palabra[0]=='o';
      A+=palabra[1]=='n';
      A+=palabra[2]=='e';
      if(A>1)
        printf("%d\n",1);
      else
        printf("%d\n",2);

      

    }
  }

}
