#include <bits/stdc++.h>
using namespace std;
vector<int> adj[101];
int flag;
int marcados[101];
void dfs(int u,int ant){
  int v;
  marcados[u]=1;
  for(int i=0;i<adj[u].size();i++){
    v=adj[u][i];
    if(!marcados[v]){
      dfs(v,u);
    }
  }
}
main(){
  int cnt=0;
	flag=0;
  int N,M,a,b;
  memset(marcados,0,sizeof marcados);
  scanf("%d%d",&N,&M);
  int d=M;
  while(d--){
    scanf("%d%d",&a,&b);
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }
  for(int i=0;i<N;i++){
    if(!marcados[i]){
      dfs(i,-1);
      cnt++;
    }
  }
  if(M==N && cnt==1)
    printf("FHTAGN!\n");
  else
    printf("NO\n");

}
