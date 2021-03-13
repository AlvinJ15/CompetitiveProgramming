#include <bits/stdc++.h>
using namespace std;
main(){
  int N,M,gift,cases=1;
  map<string,int> mapa;
  map<string,int> ini;
  vector<string> personas;
  string p,o;
  vector<string> R;
  while(scanf("%d",&N)!=EOF){
    if(cases!=1)printf("\n");
    cases++;
    mapa.clear();ini.clear();R.clear();
    for(int i=0;i<N;i++){
      cin>>p;
      R.push_back(p);
      mapa.insert(make_pair(p,0));
      ini.insert(make_pair(p,0));
    }
    for(int i=0;i<N;i++){
      cin>>p;
      scanf("%d",&M);
      ini[p]=M;
      scanf("%d",&gift);
      if(gift==0)continue;
      int cantidad=M/gift;
      mapa[p]-=cantidad*gift;
      for(int i=0;i<gift;i++){
        cin>>o;
        mapa[o]+=cantidad;
      }
    }
    for(int i=0;i<N;i++){
      cout<<R[i]<<" "<<mapa[R[i]]<<endl;
    }

  }


}
