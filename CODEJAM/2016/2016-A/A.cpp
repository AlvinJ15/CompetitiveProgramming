#include <bits/stdc++.h>
using namespace std;
main(){
  char resp[3000];
  int T,cases=1,a,b;
  string palabra;
  scanf("%d",&T);
  while(T--){
    a=b=1002;
    cin>>palabra;
    resp[a]=palabra[0];
    for(int i=1;i<palabra.size();i++){
      if(palabra[i]>=resp[a]){
        resp[a-1]=palabra[i];
        a--;
      }
      else{
        resp[b+1]=palabra[i];
        b++;
      }
    }
   // cout<<a<<" "<<b<<endl;
    if(cases!=1)printf("\n");
    printf("Case #%d: ",cases++);
    for(int i=a;i<b+1;i++)
      printf("%c",resp[i]);
  }


}
