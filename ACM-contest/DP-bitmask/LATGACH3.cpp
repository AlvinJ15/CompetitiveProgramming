#include <bits/stdc++.h>
using namespace std;
int N;
int memo[31];
long  dp(int num){
  if(num==0)return 1;
  if(num<0)return 0;
  if(memo[num]!=-1)return memo[num];
  long  ans= 3*dp(num-2);
  for(int i=4;i<=N;i+=2)
    ans+=2*dp(num-i);
  return memo[num]=ans;

}
main(){
	while((scanf("%d",&N)),N!=-1){
    memset(memo,-1,sizeof memo);
    cout<<dp(N)<<endl;
  }
  

}
