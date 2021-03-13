#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
typedef pair<int,int> ii;
int N;
int dfs_low[MAX_N];
int dfs_parent[MAX_N];
int dfs_num[MAX_N];
vector<int> adj[MAX_N];
int numero,dfsRoot,rootChildren;

vector<pair<int,int> > respuestas;
void bridges(int u){
  int v;
  dfs_low[u]=dfs_num[u]=numero++;
  for(int i=0;i<adj[u].size();i++){
    v=adj[u][i];
    if(dfs_num[v]==-1){
      dfs_parent[v]=u;
      bridges(v);
      if(dfs_low[v]>dfs_num[u])
        respuestas.push_back(make_pair(min(u,v),max(u,v)));
     dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }
    else if(v!=dfs_parent[u])
      dfs_low[u]=min(dfs_low[u],dfs_num[v]);
  }
  
}
bool comp(ii a,ii b){
  if(a.first==b.first)
    return a.second<b.second;
  return a.first<b.first;
}
main(){
  int u,v,var,cases=0;
  char num[100];
	while(scanf("%d",&N)!=EOF){
    numero=0;
    respuestas.clear();


    for(int i=0;i<N;i++){
      scanf("%d",&u);
      scanf("%100s",num);
      int tam=strlen(num);
      var=0;
      for(int j=1;j<tam-1;j++){
        var=var*10+num[j]-'0';
      }
      for(int j=0;j<var;j++){
        scanf("%d",&v);
        adj[u].push_back(v);
      }
    }
    numero=0;
    memset(dfs_parent,0,sizeof dfs_parent);
    memset(dfs_low,0,sizeof dfs_low);
    memset(dfs_num,-1,sizeof dfs_num);
    for(int i=0;i<N;i++){
      if(dfs_num[i]==-1){
        dfsRoot=i;rootChildren=0;bridges(i);
      }
    }
    sort(respuestas.begin(),respuestas.end(),comp);
    printf("%d critical links\n",(int)respuestas.size());
    for(int i=0;i<respuestas.size();i++){
      printf("%d - %d\n",respuestas[i].first,respuestas[i].second);
    }
    printf("\n");
    for(int i=0;i<N;i++)
      adj[i].clear();
  }
  


}
