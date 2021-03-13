#include <bits/stdc++.h>
using namespace std;
int N,K;
int memo[10005][102];
int arr[10005];
bool dp(int pos,int sum){
  if(pos==N)
    return (sum==0)?true:false;
  if(memo[pos][sum]!=-1)return memo[pos][sum];
  return memo[pos][sum]=dp(pos+1,(sum+arr[pos]%K)%K)||dp(pos+1,(sum-arr[pos]%K+K)%K);
}
main(){
  int test;
  cin>>test;
  while(test--){
    memset(memo,-1,sizeof memo);
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
      scanf("%d",&arr[i]);
    printf(dp(0,0)?"Divisible\n":"Not divisible\n");
  }


}
