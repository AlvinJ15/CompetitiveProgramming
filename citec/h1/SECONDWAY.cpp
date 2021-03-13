#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
void imprimir(){
  cout<<"llego\n";
}
int padre[ MAX];
int rango[MAX];
void MakeSet( int n ){
      for( int i = 0 ; i < n ; ++i ){
                padre[ i ] = i; 
                        rango[ i ] = 0;
                            }
}

int Find( int x ){
      if( x == padre[ x ] ){    
                return x;      
                    }
          else return padre[ x ] = Find( padre[ x ] ); 
}
void Union( int x , int y ){
      int xRoot = Find( x );    //Obtengo la raiz de la componente del vértice X
          int yRoot = Find( y );    //Obtengo la raiz de la componente del vértice Y
              if( rango[ xRoot ] > rango[ yRoot ] ){ //en este caso la altura de la componente del vértice X es
                                                           //mayor que la altura de la componente del vértice Y.
                        padre[ yRoot ] = xRoot;            //el padre de ambas componentes será el de mayor altura
                            }
                  else{                    //en este caso la altura de la componente del vértice Y es mayor o igual que la de X
                            padre[ xRoot ] = yRoot;            //el padre de ambas componentes será el de mayor altura
                                    if( rango[ xRoot ] == rango[ yRoot ] ){ //si poseen la misma altura
                                                  rango[ yRoot ]++;              //incremento el rango de la nueva raíz
                                                          }
                                        }
}
bool sameComponent( int x , int y ){
      if( Find( x ) == Find( y ) ) return true;
          return false;
}
struct Edge{
  int origen;
  int destino;
  int peso;
  int pos;
  bool operator<(const Edge &e)const{
    return peso<e.peso;
  }
  bool operator==(const Edge &e)const{
    return origen==e.origen&&destino==e.destino&&peso==e.peso&&pos==e.pos;
  }
}arista[MAX];


int V,E;
int cnt;
bool marcados[101];
vector<Edge> edges;
vector<Edge> Kedges;
vector<int> adj[101];


long long Kruskal(bool flag){
  int origen,destino,peso;
  long long total=0;
  MakeSet(V);
  sort(arista,arista+E);
  for(int i=0;i<E;++i){
    origen=arista[i].origen;
    destino=arista[i].destino;
    peso=arista[i].peso;
    if(!sameComponent(origen,destino)){
      if(flag)Kedges.push_back(arista[i]);
      total+=peso;
      Union(origen,destino);
    }
  }
  return total;
}
void dfs(int u){
  marcados[u]=1;
  int v;
  for(int i=0;i<adj[u].size();i++){
    v=adj[u][i];
    if(!marcados[v])
      dfs(v);
  }
}
main(){
  int test,caseNumber=1;
  long long firstway,secondway;
  Edge var;
  bool SW;
  scanf("%d",&test);
  while(test--){
    edges.clear();
    for(int i=0;i<101;i++)
      adj[i].clear();
    
    SW=0;
    memset(marcados,0,sizeof marcados);
    scanf("%d%d",&V,&E);
    for(int i=0;i<E;i++){
      scanf("%d%d%d",&var.origen,&var.destino,&var.peso);
      var.origen--;var.destino--;
      var.pos=i;
      edges.push_back(var);    
    }
    for(int i=0;i<edges.size();i++){
      var=edges[i];
      adj[var.origen].push_back(var.destino);
      adj[var.destino].push_back(var.origen);
    }
    cnt=0;
    for(int i=0;i<V;i++){
      if(!marcados[i]){
        dfs(i);
        cnt++;
      }
    }
    secondway=1<<30;
    if(cnt==1){
       for(int i=0;i<edges.size();i++){
          arista[i]=edges[i];
       }
       Kedges.clear();
       firstway=Kruskal(1);
       for(int i=0;i<Kedges.size();i++){
         E=edges.size();
         for(int j=0;j<101;j++)
           adj[j].clear();
         memset(marcados,0,sizeof marcados);
          for(int j=0;j<E;j++){
            if(j==Kedges[i].pos)continue;
            var=edges[j];
            adj[var.origen].push_back(var.destino);
            adj[var.destino].push_back(var.origen);
          }
          cnt=0;
          for(int j=0;j<V;j++){
            if(!marcados[j]){
              dfs(j);
              cnt++;
            }
          }
          if(cnt==1){
            SW=1;
            for(int j=0,k=0;j<E;j++){
              if(j==Kedges[i].pos)continue;
              arista[k++]=edges[j];
            }
            E--;
            secondway=min(secondway,Kruskal(0));
          }
       }
       if(SW){
         printf("Case #%d : %lld\n",caseNumber++,secondway);
       }
       else{
         printf("Case #%d : No second way\n",caseNumber++);
       }
       
    }
    else{
      printf("Case #%d : No way\n",caseNumber++);
    }
      
    
  }


}
