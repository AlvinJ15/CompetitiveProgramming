#include <bits/stdc++.h>
using namespace std;
int N;
int hash[100005];
vector<int> adj[100005];
int p[100005];
int rango[100005];
bool marcados[100005];
void makeSet(int n){
  for(int i=0;i<n;i++){
    p[i]=i;
    rango[i]=0;
    hash[i]=i;
  }
}
int find(int x){
  if(p[x]==x)return x;
  return p[x]=find(p[x]);
}
void unir(int x,int y){
  int xx= find(x);
  int yy=find(y);
  if(rango[xx]>rango[yy]){
    p[yy]=xx;
  }
  else{
  
  p[xx]=yy;
  if(rango[xx]==rango[yy])
    rango[yy]++;
  }
}
bool same(int u,int v){
  return find(u)==find(v);
}
void dfs(int u){
  cout<<u<<endl;
  int v;
  marcados[u]=1;
  for(int i=0;i<adj[u].size();i++){
    v=adj[u][i];
    if(!marcados[v]&&marcados[hash[v]])
        dfs(v);
    else{
      if(!marcados[v])
    }
  }
}
main(){
  int a,b,M,K;
  while(scanf("%d%d%d",&N,&K,&M),N!=-1){
    makeSet(N);
    
    while(K--){
      scanf("%d%d",&a,&b);
      hash[b-1]=a-1;
    }
    while(M--){
      scanf("%d%d",&a,&b);
      unir(b,a);
      adj[a-1].push_back(b-1);
      adj[b-1].push_back(a-1);
    }
    memset(marcados,0,sizeof marcados);
    dfs(0);
    printf(marcados[N-1]?"Y\n":"N\n");
    for(int i=0;i<N;i++)
      adj[i].clear();
  }	


}
