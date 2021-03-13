#include <bits/stdc++.h>
using namespace std;
bool compar(pair<int,int> a,pair<int,int> b){
  return a.second<b.second;
}
bool com2(int a,int b){
  return a>b;
}
vector<pair<int,int> > obj;
vector<int> fam;
int N,G;
int total;
int memo[1000][31];
int dp(int n,int w,int i){
  if(w>fam[i])return -10000000;
  if(n==N)return 0;
  if(memo[n][w]!=-1)return memo[n][w];
  return memo[n][w]=max(obj[n].first+dp(n+1,w+obj[n].second,i),dp(n+1,w,i));
}
main(){
  int var,var2;
  int T;
  cin>>T;
  while(T--){
    memset(memo,-1,sizeof memo);
    obj.clear();
    fam.clear();
    scanf("%d",&N);
    for(int i=0;i<N;i++){
      scanf("%d%d",&var,&var2);
      obj.push_back(make_pair(var,var2));
    }
    scanf("%d",&G);
    total=0;
    for(int i=0;i<G;i++){
      scanf("%d",&var);
      fam.push_back(var);
    }
    for(int i=0;i<G;i++){
      memset(memo,-1,sizeof memo);
      total+=dp(0,0,i);
    }
    printf("%d\n",total);
  }


}
