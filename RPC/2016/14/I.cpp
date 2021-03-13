#include <bits/stdc++.h>
using namespace std;
int n;
long long memo[100][3];
int dp(int pos,int flag){
  if(pos==n)return flag;
  if(memo[pos][flag]!=-1)return memo[pos][flag];
  long long ans=0;
  for(int i=0;i<10;i++){
    if(i==9 ||i==8){
      ans+=dp(pos+1,0);
    }
    else{
      ans+=dp(pos+1,flag);
    }
  }
  return memo[pos][flag]=ans;
}
int dp2(int pos,int flag){
  if(pos==n)return flag;
  if(memo[pos][flag]!=-1)return memo[pos][flag];
  long long ans=0;
  for(int i=0;i<10;i++){
    if(i==7 ||i==1 ||i==8 || i==6){
      ans+=dp(pos+1,0);
    }
    else{
      ans+=dp(pos+1,flag);
    }
  }
  return memo[pos][flag]=ans;
  
}
main(){
  memset(memo,-1,sizeof memo);
  cin>>n;
  long long a=8;
  printf("%lld\n",(long long)pow(a,n));

}
