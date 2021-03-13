#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
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
  double peso;
  bool operator<(const Edge &e)const{
    return peso<e.peso;
  }
}arista[MAX];
int V,E;
double Kruskal(){
  int origen,destino;
  double total=0,peso;
  MakeSet(V);
  sort(arista,arista+E);
  for(int i=0;i<E;++i){
    origen=arista[i].origen;
    destino=arista[i].destino;
    peso=arista[i].peso;
    if(!sameComponent(origen,destino)){
      total+=sqrt(peso);
      Union(origen,destino);
    }
  }
  return total;
}
main(){
  Edge a;
  int var=0;
  double r;
  while(scanf("%d",&V),V){
    int arr[1001][2];
    for(int i=0;i<V;i++){
      scanf("%d%d",&arr[i][0],&arr[i][1]);
    }
    E=0;
    
    for(int i=0;i<V;i++)
      for(int j=i+1;j<V;j++){
        a.origen=i;
        a.destino=j;
        a.peso=((arr[i][0]-arr[j][0])*(arr[i][0]-arr[j][0]))+((arr[i][1]-arr[j][1])*(arr[i][1]-arr[j][1]));
        arista[E++]=a;
      }
    r=Kruskal();
    int abc=(int)((r*100)+0.5);
    r=abc/100.0;
    if(var==0)printf("%.2lf",r);
    else printf("\n%.2lf",r);
    var++;
  }	



}
