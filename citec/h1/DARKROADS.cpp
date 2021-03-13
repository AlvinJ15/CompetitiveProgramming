#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
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
  bool operator<(const Edge &e)const{
    return peso<e.peso;
  }
}arista[MAX];
int V,E;
long long Kruskal(){
  int origen,destino,peso;
  long long total=0;
  MakeSet(V);
  sort(arista,arista+E);
  for(int i=0;i<E;++i){
    origen=arista[i].origen;
    destino=arista[i].destino;
    peso=arista[i].peso;
    if(!sameComponent(origen,destino)){
      total+=peso;
      Union(origen,destino);
    }
  }
  return total;
}
main(){
  Edge a;
  int var=0,x,y,z,suma;
  long long r;
  while(scanf("%d%d",&V,&E),V|E){
    suma=0;
    for(int i=0;i<E;i++){
      scanf("%d%d%d",&x,&y,&z);
      a.origen=x;
      a.destino=y;
      a.peso=z;
      suma+=z;
      arista[i]=a;
    }
    
    r=Kruskal();
    printf("%lld\n",suma-r);
  }	



}
