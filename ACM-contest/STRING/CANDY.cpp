#include <bits/stdc++.h>
using namespace std;
int A,B;
int N,M;
vector<vector<int> > arr;
map<int,int> memoM[2];
map<int,int>::iterator it;
long long memo[100005][2];
long long ans;
int dp1(int pos,int flag){
  if(pos==M)return 0;
  it = memoM[flag].find(pos);
  if(it!=memoM[flag].end())return memoM[flag][pos];
  if(flag){
    ans=max(dp1(pos+1,1),arr[A][pos]+dp1(pos+1,0));
    memoM[flag].insert(make_pair(pos,ans));
    return ans;
  }
  else{
    ans=dp1(pos+1,1);
    memoM[flag].insert(make_pair(pos,ans));
    return ans;
  }
}
vector<int> res;
long long dp2(int pos,int flag){
  if(pos==N)return 0;
  if(memo[pos][flag]!=-1)return memo[pos][flag];
  if(flag){
    return memo[pos][flag]=max(res[pos]+dp2(pos+1,0),dp2(pos+1,1));
  }
  else{
    return memo[pos][flag]=dp2(pos+1,1);
  }
}
main(){
  vector<int> var;
  while(scanf("%d%d",&N,&M),N|M){
    int x;
    res.clear();
    arr.clear();
    for(int i=0;i<N;i++){
      var.clear();
      for(int j=0;j<M;j++){
        scanf("%d",&x);
        var.push_back(x);
      }
      arr.push_back(var);
    }
    for(int i=0;i<N;i++){
      A=i;
      memoM[0].clear();
      memoM[1].clear();
      res.push_back(dp1(0,1));
    }
    memset(memo,-1,sizeof memo);
    long long resultado=dp2(0,1);
    printf("%lld\n",resultado);
  }


}
