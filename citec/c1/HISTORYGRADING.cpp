#include <bits/stdc++.h>
using namespace std;
int N;
int memo[50][50];
int R[50];
int A[50];
int dp(int i,int j){
  if(i==N || j==N)return 0;
  if(memo[i][j]!=-1)return memo[i][j];
  if(R[i]==A[j])return memo[i][j]=1+dp(i+1,j+1);
  return memo[i][j]=max(dp(i+1,j),dp(i,j+1));
}
main(){
   cin>>N;int v;
   for(int i=0;i<N;i++)
     scanf("%d",&R[i]);
   int cnt=0;
   while(scanf("%d",&v)!=EOF){
     A[cnt%N]=v;
     if(cnt%N==N-1){
      memset(memo,-1,sizeof memo);
      printf("%d\n",dp(0,0));
     }
     cnt++;
   }

}
