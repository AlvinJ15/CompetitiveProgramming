#include <bits/stdc++.h>
using namespace std;
main(){
  int N,a,b,cases=1;
  bool flag;
  vector<int> R;
  int T;
  cin>>T;
  while(T--){
	scanf("%d",&N);
    if(cases!=1)
      printf("\n");
    R.clear();
    cases++;
    while(N--){
      scanf("%d%d",&a,&b);
      R.push_back(abs(a-b)+1);
    }
    flag=1;
    for(int i=1;i<R.size();i++)
      if(R[i]!=R[0])
        flag=false;
    printf(flag?"yes\n":"no\n");
  }


}
