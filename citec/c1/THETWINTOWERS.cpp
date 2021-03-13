#include <bits/stdc++.h>
using namespace std;
int N,M;
int memo[200][200];
int A[200],B[200];
int dp(int i,int j){
  if(i==N || j==M)return 0;
  if(memo[i][j]!=-1)return memo[i][j];
  if(A[i]==B[j])return memo[i][j]=1+dp(i+1,j+1);
  else{
    return memo[i][j]=max(dp(i+1,j),dp(i,j+1));
  }
}
main(){
  int var=1;
	while(scanf("%d%d",&N,&M),N|M){
    memset(memo,-1,sizeof memo);
    for(int i=0;i<N;i++)
      scanf("%d",&A[i]);
    for(int i=0;i<M;i++)
      scanf("%d",&B[i]);
    printf("Twin Towers #%d\n",var++);
    printf("Number of Tiles : %d\n\n",dp(0,0));
  }
 

}
