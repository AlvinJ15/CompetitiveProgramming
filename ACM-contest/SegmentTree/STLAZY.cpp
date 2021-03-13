#include <bits/stdc++.h>
using namespace std;
int ST[100];
int lazy[100]:
int numeros[100];
int N;
void build(int index,int L,int R){
  if(L==R)
    ST[index]=numeros[L];
  else{
    build(index*2+1,L,(L+R)/2);
    build(index*2+2,(L+R)/2+1,R);
    ST[index]=ST[index*2+1]+ST[index*2+2];
  }
}
int consulta(int index,int L,int R,int i,int j){
  if(L>=i && R<=j)
    return ST[index];
  if(R<i || L>j)
    return 0;
  return consulta(index*2+1,L,(L+R)/2,i,j)+consulta(index*2+2,(L+R)/2+1,R,i,j);
}
void actualizar(int index,int L,int R,int i,int j,int valor){
  if(L==R)
    

}
main(){

  cin>>N;
  for(int i=0;i<N;i++)
    cin>>numeros[i];
  build(0,0,N-1);
  cout<<consulta(0,0,N-1,2,4)<<endl;
	


}
