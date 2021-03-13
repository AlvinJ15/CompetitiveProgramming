#include <bits/stdc++.h>
using namespace std;
int ninos[100];
int jugar(int k){
 // cout<<"entro"<<endl;
  bool sentido=1;
  for(int i=0;i<100;i++)ninos[i]=1;
  int actual=0;
  int restan;
  for(int i=100;i>1;i--){
    //cout<<i<<endl;
    restan=k%i;
    if(restan==0){
      ninos[actual]=0;
      while(ninos[actual]==0&&sentido)
        actual=(actual+1)%100;
      while(ninos[actual]==0&&!sentido)
        actual=(actual-1+100)%100;
      sentido=!sentido;
      continue;
    }
    //cout<<"restan:"<<restan<<endl;
    while(restan!=0&&sentido){
    //  cout<<"a";
      actual=(actual+100)%100;
      if(ninos[actual]==1){
        actual=(actual+1)%100;
        while(ninos[actual]!=1)actual=(actual+1)%100;
        restan--;
      }
      else{
        actual=(actual+1)%100;}
    }
    while(restan!=0 && !sentido){
      actual=(actual+100)%100;
      if(ninos[actual]==1){
        actual=(actual-1+100)%100;
        while(ninos[actual]!=1)actual=(actual-1+100)%100;
        restan--;
      }
      else
        actual=(actual-1+100)%100;
    }
    ninos[(actual+100)%100]=0;
   // cout<<"NIÑO eliminado: "<<actual<<" "<<sentido<<endl;
   // cout<<"actual:"<<actual;
    while(ninos[actual]==0&&sentido){
      actual=(actual+1)%100;
  //    cout<<i<<k;
    }
    while(ninos[actual]==0&&!sentido){
      actual=(actual-1+100)%100;
    }
   // cout<<"NUEVO ACTUAL; "<<actual<<endl;
    sentido=!sentido;
   // cout<<"fin"<<endl;
  }
 // cout<<"return:"<<actual+1<<endl;
  return actual+1;
}
main(){
  int K,N,cases=1;
  while(scanf("%d",&N),N){
    for(int i=1;i<=1000;i++){
   //   cout<<"Valor de K:"<<i<<"en Test"<<N<<endl;
     // cout<<"Juego "<<i<<" : "<<jugar(i)<<endl;
      if(jugar(i)==N){
        printf("%d\n",i+1);
        break;
      }
    }
  }


}
