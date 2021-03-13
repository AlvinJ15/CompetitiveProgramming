#include <bits/stdc++.h>
using namespace std;
main(){
  int T;
  int arr[1000];
  int arr2[1000];
  cin>>T;
  int W,N;
  while(T--){
    scanf("%d%d",&W,&N);
    for(int i=0;i<N;i++){
      scanf("%d%d",&arr[i],&arr2[i]);
    }
    long long total=0;
    int actual=0;
    int ant=0;
    int i;
    for(i=0;i<N;i++){
      total+=arr[i]-ant;
      if(arr2[i]>W){
        total+=arr[i];
        break;
      }
      if(actual+arr2[i]>W){
        total+=arr[i]*2;
        actual=arr2[i];
        if(actual==W){
          total+=arr[i]*2;
          actual=0;
          if(i==N-1){total-=arr[i];break;}
        }
        ant=arr[i];
        continue;
      }
      if(actual+arr2[i]==W){
        actual=0;
        total+=arr[i]*2;
        ant=arr[i];
        if(i==N-1){total-=arr[i];break;}
        continue;
      }
      if(actual+arr2[i]<W){
        actual+=arr2[i];
        ant=arr[i];
      }
    }
    if(i==N)total+=arr[N-1];
    printf("%lld\n",total);
  }


}
