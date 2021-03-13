#include <bits/stdc++.h>
using namespace std;
main(){
  int N,x,max=0;
  while(scanf("%d",&N)!=EOF){
    max=0;
    for(int i=0;i<N;i++){
      scanf("%d",&x);
      if(max<x)max=x;
    }
    printf("%.5f",(float)((float)max)/100.0);
    cout<<endl;
  }
}
