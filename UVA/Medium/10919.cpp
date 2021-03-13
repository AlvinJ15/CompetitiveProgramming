#include <bits/stdc++.h>
using namespace std;
main(){
	
  string palabra;
  map<string,int> mapa;
  map<string,int>::iterator it;
  int K,M,N,minimo,contador;
  bool flag;
  while(scanf("%d%d",&K,&M),K){
    mapa.clear();
    for(int i=0;i<K;i++){
      cin>>palabra;
      mapa.insert(make_pair(palabra,0));
    }
    flag=1;
    for(int i=0;i<M;i++){
      scanf("%d%d",&N,&minimo);
      contador=0;
      for(int i=0;i<N;i++){
        cin>>palabra;
        it=mapa.find(palabra);
        if(it!=mapa.end())
          contador++;
      }
      if(contador<minimo)
        flag=0;
    }
    printf(flag?"yes\n":"no\n");
  }

}
