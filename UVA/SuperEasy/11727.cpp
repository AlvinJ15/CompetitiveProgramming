#include <bits/stdc++.h>
using namespace std;
main(){
  int T,v,cases=1;
  vector<int> a;
  scanf("%d",&T);
  while(T--){
    a.clear();
    scanf("%d",&v);
    a.push_back(v);
    scanf("%d",&v);
    a.push_back(v);
    scanf("%d",&v);
    a.push_back(v);
    sort(a.begin(),a.end());
    printf("Case %d: %d\n",cases++,a[1]);
  }


}
