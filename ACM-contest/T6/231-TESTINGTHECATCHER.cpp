#include <bits/stdc++.h>
using namespace std;
vector<int> elems;
int memo[1000][1000];
int N;
int dp(int index,int ant){
  if(index==N)return 0;
  if(memo[index][ant]!=-1)return memo[index][ant];
  if(elems[index]<=elems[ant]){
    return memo[index][ant]=max(1+dp(index+1,index),dp(index+1,ant));
  }
  else{
    return memo[index][ant]=dp(index+1,ant);
  }
}
int main(){
  int var;
  int cases=1;
  elems.push_back(400000);
  while(true){
    scanf("%d",&var);
    if(elems.size()==1 && var ==-1)return 0;
    if(var!=-1){

      elems.push_back(var);
    }
    else{
      if(cases!=1)printf("\n");
      N=elems.size();
      memset(memo,-1,sizeof memo);
      printf("Test #%d:\n",cases++);
      printf("  maximum possible interceptions: %d\n",dp(1,0));
      elems.clear();
      elems.push_back(400000);
    }
  }	


}
