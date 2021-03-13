#include <bits/stdc++.h>
using namespace std;
main(){
	int T;
  scanf("%d",&T);
  string palabra;
  while(T--){
    cin>>palabra;
    int N=palabra.size();
    if(palabra.size()==1&&(palabra[0]=='1'||palabra[0]=='4')){
      printf("+\n");
    }
    else if(palabra.size()==2 && palabra[0]=='7' && palabra[1]=='8')
       printf("+\n");
    else if(palabra.size()>=2&&palabra[N-1]=='5' && palabra[N-2]=='3')
      printf("-\n");
    else if(palabra.size()>=2&& palabra[0]=='9' && palabra[N-1]=='4')
      printf("*\n");
    else
      printf("?\n");

    
    
  }
}
