#include <bits/stdc++.h>
using namespace std;
vector<int> adj_mat[501];
bool visited[501];
int ciclos;
int dfs(int u,int ant){
  int v,ans=0;;
  visited[u]=1;
  for(int i=0;i<adj_mat[u].size();i++){
    v=adj_mat[u][i];
    if(!visited[v])
      dfs(v,u);
    else
      if(ant!=v)ciclos=-1;
  }
}
main(){
	int V,E,a,b,sum,var=1;
  while(scanf("%d%d",&V,&E),V|E){
    for(int i=0;i<501;i++)
      adj_mat[i].clear();
    memset(visited,0,sizeof visited);
    printf("Case %d: ",var++);
    sum=0;
      for(int i=0;i<E;i++){
        scanf("%d%d",&a,&b);
        adj_mat[a-1].push_back(b-1);
        adj_mat[b-1].push_back(a-1);
      }
      for(int i=0;i<V;i++){
        if(!visited[i]){
          sum++;
          ciclos=0;
          sum+=dfs(i,-1);
          sum+=ciclos;
        }
      }
    if(sum==0)
      printf("No trees.\n");
    if(sum==1)
      printf("There is one tree.\n");
    if(sum>1)
      printf("A forest of %d trees.\n",sum);
  }

}
