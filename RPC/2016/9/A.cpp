#include <bits/stdc++.h>
using namespace std;
long long memo[9][101];
int arr[9];
long long dp(int pos,int sum){
  if(pos==8){
    if(sum==arr[pos])return 1;
    else return 0;
  }
  if(sum>100)return 0;
  if(memo[pos][sum]!=-1)return memo[pos][sum];
  long long ans=0;
  for(int i=0;i<101;i++){
    ans+=dp(pos+1,sum+i*arr[pos]);
  }
  return memo[pos][sum]=ans;
}
main(){
  int T;
  int cases=1;
  cin>>T;
  while(T--){
    
    memset(memo,-1,sizeof memo);
    for(int i=0;i<9;i++){
      scanf("%d",&arr[i]);
    }
    printf("Equation #%d: %lld\n",cases++,dp(0,0));
  }


}
