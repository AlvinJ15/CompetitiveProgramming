#include <bits/stdc++.h>
using namespace std;
main(){
  int T;
  scanf("%d",&T);
  int cnt,cnt2;
  int arr[10];
  printf("Lumberjacks:\n");
  while(T--){
    for(int i=0;i<10;i++){
      scanf("%d",&arr[i]);
    }
    cnt=cnt2=0;
    for(int i=1;i<10;i++){
      if(arr[i]>arr[i-1])
        cnt++;
      if(arr[i]<arr[i-1])
        cnt2++;
    }
    if(cnt==9 || cnt2==9)
      printf("Ordered\n");
    else
      printf("Unordered\n");
  }


}
