#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pairs;
map<pair<int,int>, long long> memo;
map<pair<int,int>,long long>::iterator it;
int L;
vector<int> cosas[4];
long long dp(int dinero,int pos){
  if(pos==4)return 1;
  if(dinero<=0)return 0;
  it=memo.find(make_pair(dinero,pos));
  if(it!=memo.end()){
    return memo.find(make_pair(dinero,pos))->second;
  }
  else{
    long long ans=0;
    for(int i=0;i<cosas[pos].size();i++){
      if(dinero>=cosas[pos][i])
      ans+=dp(dinero-cosas[pos][i],pos+1);
    }
    memo.insert(make_pair(make_pair(dinero,pos),ans));
    return ans;
  }
}
main(){
	int S,M,D,B,val;
  while(scanf("%d%d%d%d%d",&L,&S,&M,&D,&B),L|S|M|D|B){
    for(int i=0;i<4;i++)
      cosas[i].clear();
    for(int i=0;i<S;i++){
      scanf("%d",&val);
      cosas[0].push_back(val);
    }
    for(int i=0;i<M;i++){
      scanf("%d",&val);
      cosas[1].push_back(val);
    }
    for(int i=0;i<D;i++){
      scanf("%d",&val);
      cosas[2].push_back(val);
    }
    for(int i=0;i<B;i++){
      scanf("%d",&val);
      cosas[3].push_back(val);
    }
    memo.clear();
    printf("%lld\n",dp(L,0));
  }

}
