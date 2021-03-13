#include <bits/stdc++.h>
using namespace std;
main(){
  int T,n;
  cin>>T;
  int arr[20000];
  int cases=1;
  while(T--){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
      scanf("%d",&arr[i]);
    }
    int sum=0,ans=0;
    int in=0,rin=0;
    int fin=0;
    for(int i=0;i<n-1;i++){
      sum+=arr[i];
      if(sum>=ans){
        if(sum==ans){
          if(i-in>fin-rin){
            fin=i;
            rin=in;
          }
        }
        else{
          ans=sum;
          fin=i;
          rin=in;
        }
      }
      if(sum<0){
        in=i+1;
        sum=0;
      }
    }
    if(ans==0){
      printf("Route %d has no nice parts\n",cases++);
    }
    else{
      printf("The nicest part of route %d is between stops %d and %d\n",cases++,rin+1,fin+2);
    }
  }


}
