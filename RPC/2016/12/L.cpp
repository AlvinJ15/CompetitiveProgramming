#include <bits/stdc++.h>
using namespace std;
int main(){
  int arr[100005];
  int N,K;
  scanf("%d%d",&N,&K);
  for(int i=0;i<K;i++)
    scanf("%d",&arr[i]);
  
  for(int i=0;i<K;i++){
    if(i>0){
      if(arr[i]==arr[i-1]){
        printf("N\n");
        return 0;
      }
      if(!(arr[i]==arr[i-1]+1 || arr[i]==arr[i-1]+2 || arr[i]==arr[i-1]-1 || arr[i]==arr[i-1]-2)){
        printf("N\n");
        return 0;
      }
      if(arr[i]+arr[i-1]==2 || arr[i]+arr[i-1]==3){
        printf("N\n");
        return 0;
      }
    }
    if(i>1){
      if(arr[i]==arr[i-2]){
        printf("N\n");
        return 0;
      }
    }
  }
printf("S\n");


}
