#include <bits/stdc++.h>
using namespace std;
int numero[20];
int hash[10];
int N;
void imprimir(){
  cout<<"asdas"<<endl;
}
void llenarHash(int index){
  memset(hash,0,sizeof hash);
  for(int i=0;i<index;i++)
    hash[numero[i]]++;
}
void llenarNumero(int index){
  for(int i=index+1;i<N;i++)
    for(int j=9;j>=0;j--)
      if(hash[j]<2){
        hash[j]++;
        numero[i]=j;
        break;
      }
}
void restar(int index){
  llenarHash(index);
  int var=numero[index]-1;
  int i;
  for(i=var;i>=0;i--){
    if(hash[i]<2){
      numero[index]=i;
      hash[i]++;
      llenarNumero(index);
      return;
    }
  }
  if(i=-1){
    return restar(index-1);
  }

}
main(){
	
  string palabra;

  while((cin>>palabra)){
  N=palabra.size();
  for(int i=0;i<palabra.size();i++)
    numero[i]=palabra[i]-'0';
  memset(hash,0,sizeof hash);
  for(int i =0;i<palabra.size();i++){
    if(hash[numero[i]]<2){
      hash[numero[i]]++;
    }
    else{
      restar(i);
      break;
    }
  }
  bool flag=true;
  for(int i=0;i<N;i++){
    if(i==0 &&numero[0]==0)
      continue;
    cout<<numero[i];
  }
  cout<<endl;
  }
}
