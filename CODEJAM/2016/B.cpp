#include <bits/stdc++.h>
using namespace std;
string pila;
int N;
int memo[1<<12];
int cicles[1<<12];
int dp(int bitmask){
  cout<<"B: "<<bitmask<<endl;
  if(!bitmask)return 0;
  if(cicles[bitmask])return 100000000;
  cicles[bitmask]=1;
  if(memo[bitmask]!=-1)return memo[bitmask];
  int ans=100000000;
  int inv_bit=0;
  for(int i=0;i<N;i++){
    inv_bit=(inv_bit<<1)|(((~((1<<i)&bitmask))>>i)&1);
    cout<<bitmask<<" "<<i<<" "<<inv_bit<<endl;
    ans=min(ans,1+dp((bitmask&~((1<<(i+1))-1))|inv_bit));
  }
  cicles[bitmask]=0;
  return memo[bitmask]=ans;
}
vector<int> adj[1<<12];
bool marcados[1<<12];
int dis[1<<12];
main(){
  int T,cases=1,bitmask,inv_bit;
  scanf("%d",&T);

  queue<int> colita;
  while(T--){
    
    memset(memo,-1,sizeof memo);

    memset(marcados,0,sizeof marcados);
    memset(dis,0,sizeof dis);
    memset(cicles,0,sizeof cicles);
    if(cases!=1)printf("\n");
    cin>>pila;
    N=pila.size();
    
    
    for(int j=0;j<(1<<N);j++){
       bitmask=j;
       inv_bit=0;
      for(int i=0;i<N;i++){
       inv_bit=(inv_bit<<1)|(((~((1<<i)&bitmask))>>i)&1);
       adj[j].push_back((bitmask&~((1<<(i+1))-1))|inv_bit);
      }
    }
    bitmask=0;
    for(int i=pila.size()-1;i>=0;i--)
      bitmask=(bitmask<<1)|(pila[i]=='+'?0:1);
    colita.push(bitmask);
    marcados[bitmask]=1;
    while(!colita.empty()){
      int v=colita.front();colita.pop();
      for(int i=0;i<adj[v].size();i++){
        if(!marcados[adj[v][i]]){
          colita.push(adj[v][i]);
          marcados[adj[v][i]]=1;
          dis[adj[v][i]]+=dis[v]+1;
        }
      }

    }
 //   cout<<bitmask<<endl;
    printf("Case #%d: %d",cases++,dis[0]);
    for(int i=0;i<1<<N;i++)
      adj[i].clear();
  }


}
