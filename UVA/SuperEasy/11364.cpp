#include <bits/stdc++.h>
using namespace std;
main(){
  int T,v,N;
  vector<int> elem;
  scanf("%d",&T);
  while(T--){
    elem.clear();
    scanf("%d",&N);
    for(int i=0;i<N;i++){
      scanf("%d",&v);
      elem.push_back(v);
    }
    sort(elem.begin(),elem.end());
    int A=elem[N-1]-elem[0];
    int dis = A/2;
    int minimo=elem[N-1]-dis+dis-elem[0];
    printf("%d\n",minimo*2);

  }


}
