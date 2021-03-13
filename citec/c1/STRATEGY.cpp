#include <bits/stdc++.h>
using namespace std;
int J[501];
main(){
  int j,r;
  int x,m,pos;

  while(scanf("%d%d",&j,&r)!=EOF){
    m=-1;
    pos=0;
    memset(J,0,sizeof J);
    for(int i=0;i<j*r;i++){
      scanf("%d",&x);
      J[i%j]+=x;
      if(J[i%j]>=m){
        m=J[i%j];
        pos=i%j;
      }
    }
    printf("%d\n",pos+1);
  
  }


}
