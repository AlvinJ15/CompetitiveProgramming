#include <bits/stdc++.h>
using namespace std;
main(){
	int T;
  cin>>T;
  int a;
  char hash[2000];
  for(int i=0;i<2000;i++)
    hash[i]='.';
  hash[0]='R';
  hash[1]='D';
  hash[2]='Z';
  while(T--){
    int N=random()%20000+1;
    cout<<N+2<<endl;
    printf("D");
    for(int i=0;i<N;i++){
      a=random()%2000;
      printf("%c",hash[a]);
    }
    printf("R\n");
  }
  printf("0");
}
