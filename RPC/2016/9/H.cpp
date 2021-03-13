#include <bits/stdc++.h>
using namespace std;
int arr[5];
main(){
  int T;
  int cases=1;
  cin>>T;
  while(T--){
    for(int i=0;i<5;i++){
      scanf("%d",&arr[i]);
    }
    for(int j=0;j<1000;j++){
      int mini=100000;
      int ind=0;

      for(int i=0;i<5;i++){
        if(mini>arr[i]){
          ind=i;
          mini=arr[i];
        }
      }
      if(mini>0)break;
      arr[ind]*=-1;
      arr[(ind-1+5)%5]-=(-mini);
      arr[(ind+1)%5]-=(-mini);
    }
    printf("Pentagon #%d:\n",cases++);
    printf("%d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4]);
  }


}
