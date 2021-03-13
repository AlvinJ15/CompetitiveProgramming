#include <bits/stdc++.h>
using namespace std;
struct node{
  int f,c,t,p;
  node(int _f,int _c,int _t,int _p):f(_f),c(_c),t(_t),p(_p){}
};
bool foo(node a,node b){
  return a.t<b.t;
}
int P;
int N,M;
vector<node> arr;
int memo[501][501];
int dp(int act,int pos){
  if(pos==P+1)return 0;
  if(memo[act][pos]!=-1)return memo[act][pos];
  if(abs(arr[act].f-arr[pos].f)+abs(arr[act].c-arr[pos].c)+arr[act].t<=arr[pos].t){
    return memo[act][pos]=max(arr[pos].p+dp(pos,pos+1),dp(act,pos+1));
  }
  return memo[act][pos]=dp(act,pos+1);
}
main(){
	int T;
  cin>>T;
  int f,c,t,p;
  while(T--){
    scanf("%d%d%d",&N,&M,&P);
    scanf("%d%d",&f,&c);
    arr.clear();
    arr.push_back(node(f,c,0,0));
    for(int i=0;i<P;i++){
      scanf("%d%d%d%d",&f,&c,&t,&p);
      arr.push_back(node(f,c,t,p));
    }
    memset(memo,-1,sizeof memo);
    sort(arr.begin(),arr.end(),foo);
    printf("%d\n",dp(0,1));
  }


}
