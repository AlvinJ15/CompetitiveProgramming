#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
struct node{
  int pos,num,hijos,costo;
  bool operator < (node other)const{
    return hijos<other.hijos;
  } 
};
void imprimir(){
  cout<<"aa"<<endl;
}
int N,M,total;
bool marcados[201];
vector<string> inp[201];
vector<int> sp;
map<string,int> mapa;
vector<int> adj[201];
int posiciones[201];
int costo[201];
int numeros[201];
int memo[203][300];
void contarHijos(int u){
  total++;
  for(int i=0;i<adj[u].size();i++){
    contarHijos(adj[u][i]);
  }
}
int contador;
vector<node> noditos;
void dfs(int u){
  marcados[u]=1;
  costo[contador]=noditos[posiciones[u]].costo;
  numeros[contador]=noditos[posiciones[u]].hijos;
  noditos[posiciones[u]].num=contador++;
  int v;
  for(int i=0;i<adj[u].size();i++){
    if(!marcados[adj[u][i]])
      dfs(adj[u][i]);
  }

}
int dp(int pos,int m){
  if(pos==N)
    if(m>=M)return 0;
    else return 1<<30;
  if(memo[pos][m]!=-1)return memo[pos][m];
  return memo[pos][m]=min(dp(pos+1,m),costo[pos] + dp(pos+numeros[pos]+1,m+numeros[pos]+1));
}
main(){
    string linea,palabra;
    int spaces,ant,nodo_num,q;
    int valor;
  while(true){
    getline(cin,linea);
    if(linea.size()<2)break;
    q=0;
    valor=0;
    while(linea[q]!=' '){
      valor=valor*10+linea[q]-'0';
      q++;
    }
    q++;
    N=valor;
    valor=0;
    while(q<linea.size()){
      valor=valor*10+linea[q]-'0';
      q++;
    }
    M=valor;
    nodo_num=0;
    memset(numeros,0,sizeof numeros);
    memset(posiciones,0,sizeof posiciones);
    memset(marcados,0,sizeof marcados);
    memset(memo,-1,sizeof memo);
    mapa.clear();
    noditos.clear();
    for(int i=0;i<201;i++){
      inp[i].clear();
      adj[i].clear();
    }
    for(int i=0;i<N;i++){
      sp.clear();
      getline(cin,linea);
    //  cout<<linea<<endl;
      spaces=0;
      for(int j=0;j<linea.size();j++){
        if(linea[j]==' '){
          spaces++;
          sp.push_back(j);
        }
      }
      ant=0;
      for(int j=0;j<sp.size();j++){
        palabra="";
        for(int h=ant;h<sp[j];h++){
          palabra+=linea[h];
        }
        inp[i].push_back(palabra);
        ant=sp[j]+1;
      }
      palabra="";
      for(int j=ant;j<linea.size();j++)
        palabra+=linea[j];
      inp[i].push_back(palabra);
    }
    for(int i=0;i<N;i++){
      mapa.insert(make_pair(inp[i][0],nodo_num++));
    }
    for(int i=0;i<N;i++){
      if(inp[i].size()>2){
        for(int j=2;j<inp[i].size();j++){
          adj[mapa[inp[i][0]]].push_back(mapa[inp[i][j]]);
        }
      }
    }
    node var;
    for(int i=0;i<N;i++){
      var.pos=i;
      total=-1;
      valor=0;
      for(int j=0;j<inp[i][1].size();j++)
        valor=valor*10+inp[i][1][j]-'0';
      var.costo=valor;
      contarHijos(i);
      var.hijos=total;
      noditos.push_back(var);
    }
    sort(noditos.begin(),noditos.end());
    reverse(noditos.begin(),noditos.end());
    contador=0;
    for(int i=0;i<noditos.size();i++){
      posiciones[noditos[i].pos]=i;
    }
    for(int i=0;i<noditos.size();i++){
      if(!marcados[noditos[i].pos]){
        dfs(noditos[i].pos);
      }
    }
    printf("%d\n",dp(0,0));

  }



}
