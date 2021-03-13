#include <bits/stdc++.h>
using namespace std;
main(){
  int A,B,C,D;
  vector<int> divisores;
  while(scanf("%d%d%d%d",&A,&B,&C,&D)!=EOF){
    int sq = sqrt(C);
    int div;
    divisores.clear();
    for(int i=1;i<=sq;i++){
      if(!(C%i)){
        div =i;
        if(div%A==0&&div%B!=0&&D%div!=0){
          divisores.push_back(div);
        }
        div=C/i;
        if(div%A==0&&div%B!=0&&D%div!=0){
          divisores.push_back(div);
        }
      }
    }
    if(divisores.size()==0)printf("-1\n");
    else{
      sort(divisores.begin(),divisores.end());
      printf("%d\n",divisores[0]);
    }
  }


}
