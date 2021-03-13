#include <bits/stdc++.h>
using namespace std;
vector<int> adj_mat[30001];
int cnt;
bool visited[30001];
void dfs(int u){
  cnt++;
  int v;
  visited[u]=1;
  for(int i=0;i<adj_mat[u].size();i++){
    v=adj_mat[u][i];
    if(!visited[v])
      dfs(v);
  }
}
main(){
	int N,M,groups,a,b;
  vector<int> elem;
  while(scanf("%d%d",&N,&M),N|M){
    memset(visited,0,sizeof visited);
    for(int i=0;i<30001;i++)
      adj_mat[i].clear();
    for(int i=0;i<M;i++){
      scanf("%d",&groups);
      elem.clear();
      while(groups--){
        scanf("%d",&a);
        elem.push_back(a);
      }
      for(int i=1;i<elem.size();i++){
        adj_mat[elem[i-1]].push_back(elem[i]);
        adj_mat[elem[i]].push_back(elem[i-1]);
      }
    }
    cnt=0;
    dfs(0);
    printf("%d\n",cnt);
  }

}
