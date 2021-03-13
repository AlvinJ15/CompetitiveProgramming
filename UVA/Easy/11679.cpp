#include <bits/stdc++.h>
using namespace std;
main(){
  int arr[21];
  bool flag;
  int B,N,a,b,c;
	 while(scanf("%d%d",&B,&N),B|N){
     memset(arr,0,sizeof arr);
     flag=1;
    for(int i=0;i<B;i++){
      scanf("%d",&arr[i+1]);
    }
    while(N--){
      scanf("%d%d%d",&a,&b,&c);
      arr[a]-=c;
      arr[b]+=c;
    }
    for(int i=0;i<B;i++){
      if(arr[i+1]<0)
        flag=0;
    }
    printf(flag?"S\n":"N\n");
   }


}
