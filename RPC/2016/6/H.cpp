#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int memo[51][51][6];
int N,inicio;
int dp(int pos,int actual,int paper){
 // cout<<pos<<" "<<actual<<" "<<paper<<endl;
  if(pos==N)return 0;
  if(memo[pos][actual][paper]!=-1)return memo[pos][actual][paper];
  if(actual==N)return memo[pos][actual][paper]=1+abs(arr[N]-arr[pos])+dp(pos+1,pos,4);
  if(paper==0)return memo[pos][actual][paper]=abs(arr[actual]-arr[N])+dp(pos,N,5);
  return memo[pos][actual][paper]=min(1+abs(arr[pos]-arr[actual])+dp(pos+1,pos,paper-1),abs(arr[actual]-arr[N])+dp(pos,N,5));
}
bool op(int x,int y){
  return abs(inicio-x)<abs(inicio-y);
}
main(){
  int x;
  while(scanf("%d",&N)!=EOF){
    arr.clear();
    memset(memo,-1,sizeof memo);
    scanf("%d",&inicio);
    for(int i=0;i<N;i++){
      scanf("%d",&x);
      arr.push_back(x);
    }
    sort(arr.begin(),arr.end(),op);
    arr.push_back(inicio);
    cout<<dp(0,N,5)<<endl;
  }
}
