#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,A,D,H;
  scanf("%d%d%d%d",&N,&A,&D,&H);
  int arr[N][3];
  for(int i=0;i<N;i++){
    scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
  }
  int a,b,c;
  for(int i=0;i<(1<<N);i++){
    if(!(i&(i-1)))continue;
    a=b=c=0;
    for(int j=0;j<N;j++){
      if(i&(1<<j)){
        a+=arr[j][0];
        b+=arr[j][1];
        c+=arr[j][2];
      }
    }
    if(a==A && D==b && c==H){
      printf("Y\n");
      return 0;
    }
  }
  printf("N\n");


}
