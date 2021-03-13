#include <bits/stdc++.h>
using namespace std;
int numeros[70];
int N;
long long memo[65][10][2];
long long dp(int pos,int ant,int cnt){
  if(pos==N)
    return cnt==1?1:0;
  if(memo[pos][ant][cnt]!=-1)return memo[pos][ant][cnt];
  long long ans=0;
  if(cnt==0){
    for(int i=0;i<10;i++){
      ans+=dp(pos+1,i,0);
    }
  }
  else{
    for(int i=0;i<10;i++){
      if(ant>i)
        ans+=dp(pos+1,i,0);
      else
        ans+=dp(pos+1,i,1);
    }
  }
  return memo[pos][ant][cnt]=ans;
}
main(){
	int test,T;
  cin>>test;
  while(test--){
    scanf("%d%d",&T,&N);
    for(int i=0;i<N;i++)
      numeros[i]=9;
    memset(memo,-1,sizeof memo);
    printf("%d %lld\n",T,dp(0,0,1));
  }


}
