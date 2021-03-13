#include <bits/stdc++.h>
using namespace std;
vector<int> adj[201];
bool color[201];
bool marcados[201];
bool flag;
int num;
int nV;
void dfs(int u){
  marcados[u]=1;
  nV++;
  if(color[u])num++;
  int v;
  for(int i=0;i<adj[u].size();i++){
    v=adj[u][i];
    if(!marcados[v]){
      color[v]=!color[u];
      dfs(v);
    }
    else{
      if(color[u]==color[v])
        flag=0;
    }
  }
}
main(){
	int test,a,b,V,E,n;
  scanf("%d",&test);
  while(test--){
    memset(marcados,0,sizeof marcados);
    for(int i=0;i<201;i++)
      adj[i].clear();
    scanf("%d%d",&V,&E);
    flag=1;
    for(int i=0;i<E;i++){
      scanf("%d%d",&a,&b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    n=0;
    for(int i=0;i<V;i++){
      if(!marcados[i]){
        nV=0;
        num=0;
        color[i]=0;
        dfs(i);
        if(nV>1)
          n+=min(num,nV-num);
        else
          n++;

      }
    }
    if(flag){
      printf("%d\n",n);
    }
    else{
      printf("-1\n");
    }
  }
  
  

}
