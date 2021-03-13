#include <bits/stdc++.h>
using namespace std;
int padre[10005];
int makeset(int n){
  for(int i=0;i<n+1;i++){
    padre[i]=i;
  }
}
int find(int x){
  if(x==padre[x])return x;
  else
    return padre[x]=find(padre[x]);
}
void unir(int x,int y){
  int xx=find(x);
  int yy=find(y);
  padre[xx]=padre[yy];
}
bool same(int x,int y){
  return find(x)==find(y);
}
main(){
  int N,M,Q;
  int a,b;
  while(scanf("%d%d%d",&N,&M,&Q)!=EOF){
    makeset(N+1);
    for(int i=0;i<M;i++){
      scanf("%d%d",&a,&b);
      unir(b,a);
    }
    while(Q--){
      scanf("%d%d",&a,&b);
      printf(same(a,b)?"Y":"N");
      printf("\n");
    }
    printf("-\n");

  }	


}
