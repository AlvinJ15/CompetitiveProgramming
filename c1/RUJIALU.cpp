#include <bits/stdc++.h>
using namespace std;
vector<int> elem[1000001];
main(){
	int N,M,val,a,b;
  while(scanf("%d%d",&N,&M)!=EOF){
    for(int i=0;i<1000001;i++)
      elem[i].clear();
  for(int i=0;i<N;i++){
    scanf("%d",&val);
    elem[val].push_back(i+1);
  }
  while(M--){
    scanf("%d%d",&a,&b);
    if(elem[b].size()<a)
      printf("%d\n",0);
    else{
      printf("%d\n",elem[b][a-1]);
    }
  }
  }
}
