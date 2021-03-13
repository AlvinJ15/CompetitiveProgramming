#include <bits/stdc++.h>
using namespace std;
vector<int> arr[15];
bool marcados[15];
void dfs(int v){
  marcados[v]=true;
  for(int i=0;i<arr[v].size();i++){
    if(!marcados[arr[v][i]])
      dfs(arr[v][i]);
  }
}
main(){
  int T;
  int N,M;
  cin>>T;
  int cases=1;
  int count,A,S;
  string P;
  while(T--){
    for(int i=0;i<15;i++)
      arr[i].clear();
    memset(marcados,0,sizeof marcados);
    scanf("%d%d",&N,&M);
    count=1;
    for(int i=0;i<M;i++){
      scanf("%d%d",&A,&S);
      cin>>P;
      arr[A-1].push_back(S-1);
      arr[S-1].push_back(A-1);
    }
    for(int i=0;i<N;i++){
      if(!marcados[i]){
        dfs(i);
        count*=2;
      }
    }
    printf("Case #%d: %d\n",cases++,count);
    
  }


}
