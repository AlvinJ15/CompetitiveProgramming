#include <bits/stdc++.h>
using namespace std;
int arr[20];
int N;
int c=0;
pair<int,int> var;
pair<int,int> memo[1<<16][16];
void maxi(pair<int,int> &x,pair<int,int> b){
  if(x.first!=b.first)
    if(x.first>b.first){
    }
    else{
      x.first=b.first;
      x.second=b.second;
    }
  else{
    x.second+=b.second;
   }
  
}
pair<int,int> dp(int bitmask,int dif){
  if(bitmask==0){
    memo[bitmask][dif].first=arr[dif];
    memo[bitmask][dif].second=1;
    return memo[bitmask][dif];
  
  }
  if(memo[bitmask][dif].first!=-1){
    return memo[bitmask][dif];
  }
  for(int p1=0;p1<N;p1++){
    if(bitmask&(1<<p1)){
      var = dp(bitmask&~(1<<p1),p1);
      var.first+=abs(arr[dif]-arr[p1]);
      maxi(memo[bitmask][dif],var);
    }
  }
  return memo[bitmask][dif];

}
main(){
  pair<int,int> temp;
  while(scanf("%d",&N),N){
    for(int i=0;i<N;i++)
       scanf("%d",&arr[i]);
    memset(memo,-1,sizeof memo);
    arr[19]=0;
    temp=dp((1<<N)-1,15);
    printf("%d %d\n",temp.first+N*2,temp.second);
  }
}
