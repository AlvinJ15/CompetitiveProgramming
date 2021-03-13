#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000
#define II *2+1
#define DD *2+2
int ST[2000000];
int lazy[2000000];
struct node{
  int x,y,T,v;
  
  bool operator < (node var)const{
    if(x==var.x){
      if(T==var.T){
        return y>var.y;
      }
      else return T<var.T;
    }
    else return x<var.x;
  }
};
vector<node> puntos;
vector<int> alturas;
int posi;
void push(int index,int L,int R){
  lazy[index II]+=lazy[index];
  lazy[index DD]+=lazy[index];
  ST[index II]+=((R+L)/2-L+1)*lazy[index];
  ST[index DD]+=(R-((R+L)/2+1)+1)*lazy[index];
  lazy[index]=0;
}
int consulta(int index,int L,int R,int i,int j){
  if(alturas[L]>=i && alturas[R]<=j){
    posi=L;
    return ST[index];
  
  }
  if(alturas[R]<i || alturas[L]>j)return 0;
  push(index,L,R);
  return consulta(index II,L,(R+L)/2,i,j)+consulta(index DD,(R+L)/2+1,R,i,j);
}
int aumentar(int index,int L,int R,int i,int j){
  if(alturas[L]>=i && alturas[R]<=j){
    lazy[index]++;
    return ST[index]+=R-L+1;
  }
  if(alturas[R]<i || alturas[L]>j)
    return ST[index];
  push(index,L,R);
  return ST[index]=aumentar(index II,L,(R+L)/2,i,j)+aumentar(index DD,(R+L)/2+1,R,i,j);
}
int marcados[300000];
int aux[300000];
main(){
  vector<int>::iterator it;
	int P,V,x,y,A,B,a,b;
  long long resultado;
  node var;
  while(scanf("%d%d",&P,&V)!=EOF){
    puntos.clear();
    alturas.clear();
    for(int i=0;i<P;i++){
      scanf("%d%d",&x,&y);
      var.x=x;
      var.y=y+MAX;
      alturas.push_back(var.y);
      var.T=1;
      var.v=i+1;
      puntos.push_back(var);
    }
    for(int i=0;i<V;i++){
      scanf("%d%d",&x,&y);
      var.x=x;
      var.y=y+MAX;
      alturas.push_back(var.y);
      var.T=0;
      var.v=0;
      puntos.push_back(var);
    }
    memset(aux,0,sizeof aux);
    memset(marcados,0,sizeof marcados);
    sort(puntos.begin(),puntos.begin()+P+V);
    sort(alturas.begin(),alturas.end());
    alturas.erase(unique(alturas.begin(),alturas.end()),alturas.end());
    memset(lazy,0,sizeof lazy);
    memset(ST,0,sizeof ST);
    resultado=0;
    for(int i=0;i<puntos.size();i++){
      var=puntos[i];
      if(var.T){
        if(!((consulta(0,0,alturas.size()-1,var.y,var.y)+aux[posi])%2)){
          resultado+=var.v;
        }
      }
      else{
        A=var.y;
        B=puntos[i+1].y;
        i++;
        a=consulta(0,0,alturas.size()-1,A,A);
        a=posi;
        b=consulta(0,0,alturas.size()-1,B,B);
        b=posi;
        if(marcados[a]==2){aux[a]=!aux[a];marcados[a]=0;}
          else {
            if(marcados[a]==1)
              marcados[a]=0;
            else
              marcados[a]=1;
          }
        if(marcados[b]==1){aux[b]=!aux[b];marcados[b]=0;}
          else {
            if(marcados[b]==2)
              marcados[b]=0;
            else
              marcados[b]=2;
          
          }
        aumentar(0,0,alturas.size()-1,B,A);
      }
    }
    printf("%lld\n",resultado);
  }

}
