#include <bits/stdc++.h>
using namespace std;
int K,N,M;
string A,B;
int memo[1001][1001];
int  comp(int i,int j){
  int a,b,c,d;
  c=i+K;
  for(a=i,b=j;a<c;a++,b++){
    if(a>=N || b>=M)return -1;
    if(A[a]!=B[b])
      return -1;
  }
  d=K;
  while(a<N&&b<M&&A[a]==B[b]){
    d++;
    a++;
    b++;
  }
  return d;
}
int dp(int i,int j){
  if(i>=N||j>=M)return 0;
  if(memo[i][j]!=-1)return memo[i][j];
  int var=comp(i,j);
  int ans=-1;
  if(var!=-1){
    ans=max(ans,var+dp(i+var,j+var));
    ans=max(ans,K+(dp(i+K,j+K)));
    ans=max(ans,max(dp(i+1,j),dp(i,j+1)));
    return memo[i][j]=ans;
  }
  else{
    return memo[i][j]=max(dp(i+1,j),dp(i,j+1));
  }
}

main(){
  int res;
  string dum;
  while(scanf("%d",&K),K){
    getline(cin,dum);
    memset(memo,-1,sizeof memo);
    getline(cin,A);
    getline(cin,B);
    N=A.size();
    M=B.size();
    res=dp(0,0);
    if((A.size()==0 || B.size()==0) && K==1)printf("1\n");
    else
      printf("%d\n",res);
  }




}
