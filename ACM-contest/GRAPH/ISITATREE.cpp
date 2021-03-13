#include <bits/stdc++.h>
using namespace std;
bool marcados[10004];
vector<int> adj[10004];
void dfs(int u){
  int v;
  marcados[u]=1;
  for(int i=0;i<adj[u].size();i++){
    v=adj[u][i];
    if(!marcados[v])
      dfs(v);
  }
}
main(){
	int N,M,a,b,cnt;
  cnt=0;
  for(int i=0;i<10004;i++)
    adj[i].clear();
  scanf("%d%d",&N,&M);
  memset(marcados,0,sizeof marcados);
  for(int i=0;i<M;i++){
    scanf("%d%d",&a,&b);
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=0;i<M;i++){
    if(!marcados[i]){
      dfs(i);
      cnt++;
    }
  }
  if(cnt==1 && N==M+1)
    printf("YES\n");
  else
    printf("NO\n");

}
