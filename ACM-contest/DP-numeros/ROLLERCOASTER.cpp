#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> > arr;
int N,K,L;
map<pair<int,int>,long long> mapa;
map<pair<int,int>,long long>::iterator it;
int posiciones[300002];
int cnt;
long long dp(int pos,int D){
  if(D>L)return -1000000;
  if(posiciones[D]==-1)posiciones[D]=cnt++;
  if(pos==N)return 0;
  it=mapa.find(make_pair(pos,D));
  if(it!=mapa.end())
    return mapa[make_pair(pos,D)];

  long long ans;
  if(D>K )
    ans= dp(pos+1,D-K);
  else
    ans=dp(pos+1,0);
  ans=max(ans,arr[pos].first+dp(pos+1,D+arr[pos].second));
  mapa.insert(make_pair(make_pair(pos,D),ans));
  return ans;
  
}
main(){
  
  int a,b;
  int var=0;
  long long resp;
  while(scanf("%d%d%d",&N,&K,&L),N|K|L){
    mapa.clear();
    arr.clear();
    for(int i=0;i<N;i++){
      scanf("%d%d",&a,&b);
      arr.push_back(make_pair(a,b));
    }
    resp=dp(0,0);
    if(var)printf("\n");
    var++;
    printf("%lld",(resp<0)?0:resp);
  }


}
