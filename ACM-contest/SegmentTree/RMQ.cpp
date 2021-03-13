#include <bits/stdc++.h>
using namespace std;
int ST[100];
int elementos[100];
int N;
void build(int index,int L,int R){
  if(L==R)
    ST[index]=elementos[L];
  else{
    build(index*2+1,L,(L+R)/2);
    build(index*2+2,(L+R)/2+1,R);
    ST[index]=ST[index*2+1]+ST[index*2+2];
  }
}
int consulta(int index,int L,int R,int i, int j){
  if(L>=i && R<=j)
    return ST[index];
  if(R<i || j<L)
    return 0;
  return consulta(index*2+1,L,(R+L)/2,i,j)+consulta(index*2+2,(L+R)/2+1,R,i,j);
}

main(){
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>elementos[i];
  }
  build(0,0,N-1);
  for(int i=0;i<3*N;i++)
    cout<<ST[i]<<" ";
  cout<<endl;
	cout<<consulta(0,0,N-1,0,5)<<endl;


}
