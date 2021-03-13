#include <bits/stdc++.h>
using namespace std;
int N;
pair<int,int> numeros[30005];
int arr[30005];
pair<int,int> ST[300000];
pair<int,int> ope(pair<int,int> a,pair<int,int> b){
  int ab = min(a.first,b.second);
  return make_pair(a.first-ab+b.first,a.second+b.second-ab);
}
void construir(int index,int L,int R){
  if(L==R){
    ST[index]=numeros[L];
    arr[L]=index;
  }
  else{
    construir(index*2+1,L,(L+R)/2);
    construir(index*2+2,(R+L)/2+1,R);
    ST[index]=ope(ST[index*2+1],ST[index*2+2]);
  }
}
void actualizar(int index){
  ST[index].first=!ST[index].first;
  ST[index].second=!ST[index].second;
  if(!index)return;
  int var;
  while(index){
    var=(index-1)/2;
    ST[var]=ope(ST[var*2+1],ST[var*2+2]);
    index=var;
  }
  ST[index]=ope(ST[index*2+1],ST[index*2+2]);
}
main(){
  int var=1;
  while(scanf("%d",&N)!=EOF){
  scanf("\n");
  char c;
  int Q,opcion;
  for(int i=0;i<N;i++){
    scanf("%c",&c);
    c-='(';
    if(!c)
      numeros[i]=make_pair(1,0);
    else
      numeros[i]=make_pair(0,1);
  }
  construir(0,0,N-1);
  scanf("%d",&Q);
  printf("Test %d:\n",var++);
  while(Q--){
    scanf("%d",&opcion);
    if(opcion){
      actualizar(arr[opcion-1]);
    }
    else{
      if((ST[0].first+ST[0].second)!=0)
        printf("NO\n");
      else
        printf("YES\n");
    }
  }
  }


}
