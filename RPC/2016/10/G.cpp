#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000003
map<int,long long> memo;
map<int,long long>::iterator it;
int a,c,m,x;
long long DP(int n){
  if(n==1)return x;
  it=memo.find(n);
  if(it!=memo.end()){
    return memo[n];
  }
  long long aux=(a*DP(n-1)+c)%m;
  memo.insert(make_pair(n,aux));
  return aux;
}
main(){
  int N,q,n;
	while(scanf("%d%d%d%d%d%d",&a,&c,&m,&x,&q,&N)!=EOF){
    memo.clear();
    while(q--){
      scanf("%d",&n);
      vector<long long> elems;
      for(int i=1;i<=N;i++){
        elems.push_back(DP(i));
      }
      for(int i=0;i<elems.size();i++)
        printf("%lld ",elems[i]);
      cout<<endl;
      sort(elems.begin(),elems.end());
      for(int i=0;i<elems.size();i++)
        printf("%lld ",elems[i]);
      cout<<endl;
      printf("%lld\n",DP(n));
    }
  }


}
