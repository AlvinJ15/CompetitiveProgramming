#include <bits/stdc++.h>
using namespace std;
int ST[1000000];
int arr[1000000];
int numeros[100005];
int N;
int alvin[100005][2];
int gcd(int a,int b){
  return b==0?a:gcd(b,a%b);
}
void construir(int index,int L,int R){
  if(L==R){
    ST[index]=numeros[L];
    arr[L]=index;
  }
  else{
    construir(index*2+1,L,(L+R)/2);
    construir(index*2+2,(L+R)/2+1,R);
    ST[index]=gcd(ST[index*2+1],ST[index*2+2]);
  }
  
}
void actualizar(int index,int valor){
  int indice=index;
  int var;
  ST[indice]=valor;
  while(indice!=0){
    var=(indice-1)/2;
    ST[var]=__gcd(ST[var*2+1],ST[var*2+2]);
    indice=var;
  }
  ST[indice]=__gcd(ST[indice*2+1],ST[indice*2+2]);
}

main(){
map<int,int> tmapa;
	scanf("%d",&N);
  int a=N;
  char c;
  int val;
  int i=0;
  int abc=1;
  int var;
  memset(numeros,0,sizeof numeros);
  construir(0,0,N-1);
  tmapa.clear();
  while(N--){
    scanf("\n");
    scanf("%c",&c);
    scanf("%d",&val);
    if(a==1){printf("%d\n",val);
      continue;
    }
    if(tmapa.find(val)==tmapa.end())
      var=0;
    else
      var=tmapa[val];
    if(c=='+'){
      if(!var){
        tmapa.insert(make_pair(val,abc));
        alvin[abc][0]=1;
        actualizar(arr[i],val);
        alvin[abc][1]=arr[i++];
        abc++;
      }
      else{
        if(alvin[var][0]==0)
          actualizar(alvin[var][1],val);
        alvin[var][0]++;
      }
      printf("%d\n",ST[0]);
    }
    if(c=='-'){
      if(alvin[var][0]==1)
        actualizar(alvin[var][1],0);
      alvin[var][0]--;
      printf("%d\n",(ST[0]==0)?1:ST[0]);
    }
  
  /*  for(int d=0;d<7;d++){
      cout<<alvin[d][0]<<" "<<alvin[d][1]<<endl;
    }*/
  }


}
