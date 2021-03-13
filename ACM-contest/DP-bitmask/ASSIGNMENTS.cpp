#include <bits/stdc++.h>
using namespace std;
int N;
long long memo[1<<21];
int arr[21][21];
long long  dp(int bitmask,int pos){
  if(!bitmask)
    return 1;
  if(memo[bitmask]!=-1)return memo[bitmask];
  long long ans=0;
  for(int i=0;i<N;i++){
    if(arr[pos][i]&&bitmask&(1<<i)){
      ans+=dp(bitmask^(1<<i),pos+1);
    }
  }
  return memo[bitmask]=ans;
}
main(){
  int test;
  scanf("%d",&test);
  int var;
  while(test--){
    scanf("%d",&N);
    memset(memo,-1,sizeof memo);
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        scanf("%d",&arr[i][j]);
      }  
    }
    printf("%lld\n",dp((1<<N)-1,0));
  }


}
