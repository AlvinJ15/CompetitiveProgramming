#include <bits/stdc++.h>
using namespace std;
bool marcados[5000];
main(){
	int numeros[12];
  int sumita,sum,N;
  vector<string> respuestas;
  while(scanf("%d%d",&sum,&N),sum|N){
    respuestas.clear();
    memset(marcados,1,sizeof marcados);
    for(int i=0;i<N;i++){
      scanf("%d",&numeros[i]);
    }
    for(int i=0;i<(1<<N);i++){
      sumita=0;
      for(int j=0;j<N;j++){
        if(i&(1<<j)){
          sumita+=numeros[j];
        }
      }
      if(sumita==sum){
        string aux="";
        int a=0;
        for(int j=0;j<N;j++){
          if(i&(1<<j)){
            
            if(a==0){
              aux+=to_string(numeros[j]);
              a++;
            }
            else{
              aux+="+"+to_string(numeros[j]);
            }
          }
        }
        respuestas.push_back(aux);
      }
    }
    sort(respuestas.begin(),respuestas.begin()+respuestas.size());
    reverse(respuestas.begin(),respuestas.end());
    for(int i=0;i<respuestas.size();i++){
      for(int j=i+1;j<respuestas.size();j++){
        if(marcados[j]){
          if(respuestas[i].compare(respuestas[j])==0){
            marcados[j]=0;
          }
        }
      }
    }
    printf("Sums of %d:\n",sum);
    bool flag=0;
    for(int i=0;i<respuestas.size();i++){
      if(marcados[i]){
        flag=1;
        printf("%s\n",respuestas[i].c_str());
      }
    }
    if(!flag)
      printf("NONE\n");
  }
}
