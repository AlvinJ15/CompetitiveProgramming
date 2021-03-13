#include <bits/stdc++.h>
using namespace std;
string p1,p2;
int n,m;
int memo[105][105];
int dp(int i,int j){
  if(i==n && j==m)return memo[i][j]=0;
  if(i>n || j>m)return memo[i][j]=1<<30;
  if(memo[i][j]!=-1)return memo[i][j];
  int ans=1<<30;
  if(p1[i]==p2[j])return memo[i][j]=dp(i+1,j+1);
  else{
    ans=min(ans,1+dp(i,j+1));
    ans=min(ans,1+(dp(i+1,j)));
    ans=min(ans,1+dp(i+1,j+1));
  }
  return memo[i][j]=ans;
}
int numero;
int deletes;
int inserts;
void imp(int i,int j){
  if(i==n&&j==m)return;
  if(i>n || j>m )return;
  int mini = 1<<30;
  if(p1[i]==p2[j])return imp(i+1,j+1);
  mini=min(mini,memo[i][j+1]);
  mini=min(mini,memo[i+1][j]);
  mini=min(mini,memo[i+1][j+1]);
  printf("%d ",numero++);
  if(mini==memo[i][j+1]){
    printf("Insert %d,%c\n",i+1-deletes+inserts,p2[j]);
    inserts++;
    imp(i,j+1);
    return;
  }else if(mini==memo[i+1][j]){
    printf("Delete %d\n",i+1-deletes+inserts);
    deletes++;
    imp(i+1,j);
    return;
  }
  else if(mini==memo[i+1][j+1]){
    printf("Replace %d,%c\n",i+1-deletes+inserts,p2[j]);
    imp(i+1,j+1);
    return;
  }
   
}
main(){
  int cases=1;
	while(getline(cin,p1)&&getline(cin,p2)){
    if(cases!=1)printf("\n");
    cases++;
    memset(memo,-1,sizeof memo);  
    numero=1;
    deletes=0;
    inserts=0;
    n=p1.size();
    m=p2.size();
    cout<<dp(0,0)<<endl;
    imp(0,0);
  }


}
