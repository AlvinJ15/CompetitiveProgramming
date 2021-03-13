#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1<<20
int arr[MAX_N];
int memo[MAX_N][30];
int N,M;
int RMQ(int i,int j){
  if(!j)return arr[i];
  if(memo[i][j]!=-1)return memo[i][j];
  return memo[i][j]=max(RMQ(i,j-1),RMQ(i+(1<<(j-1)),j-1));
}
main(){
  scanf("%d%d",&N,&M);
  int i,j,tam,R;
  memset(arr,-1,sizeof arr);
  memset(memo,-1,sizeof memo);
  int logs[N+1];
  for(int i=1;i<N+1;i++){
    logs[i]=log2(i);
  }
  for(i=0;i<N;i++){
    scanf("%d",&arr[i]);
    memo[i][0]=arr[i];
  }
  tam=ceil(log2(N));
  for(int i=N-1;i>=0;i--){
    for(int j=1;j<=tam;j++)
      memo[i][j]=max(memo[i][j-1],memo[i+(1<<(j-1))][j-1]);
  }
  int cnt=0,var;

  while(M--){
    scanf("%d%d",&i,&j);
    i--,j-=2;
    tam=j-i+1;
    R=logs[tam];
   // var=max(RMQ(i,R),RMQ(i+tam-(1<<R),R));
    var=max(memo[i][R],memo[i+tam-(1<<R)][R]);
    if(var<=arr[i])cnt++;
  }
  printf("%d\n",cnt);


}
