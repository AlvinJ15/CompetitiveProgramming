#include <bits/stdc++.h>
using namespace std;
char palabra[10005];
int memo[1000][1000];
int dp(int i,int j){
  if(i==j)return 1;
  if(i>j)return 0;
  if(memo[i][j]!=-1)return memo[i][j];
  if(palabra[i]==palabra[j])return memo[i][j]=2+dp(i+1,j-1);
  return memo[i][j]=max(dp(i+1,j),dp(i,j-1));
}

main(){
  int test;
  int N;
  cin>>test;
  getc(stdin);
  while(test--){
    memset(memo,-1,sizeof memo);
    gets(palabra);
    N=strlen(palabra);
    if(N==0)
      printf("0\n");
    else
      printf("%d\n",dp(0,N-1));
  }
  


}
