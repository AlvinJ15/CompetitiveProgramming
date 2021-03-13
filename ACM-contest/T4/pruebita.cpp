#include <bits/stdc++.h>
using namespace std;
main(){
  int N,var;
	cin>>N;
  var=N;
  printf("%d\n",N);
  while(N--){
    printf("%d ",(int)random()%2000-1000);
  }
  N=var;
  printf("%d\n",N);
  while(N--){
    printf("%d ",(int)random()%2000-50);
  }
  N=var;
  printf("%d\n",N);
  while(N--){
    printf("%d ",(int)random()%2000-50);
  }
  printf("0");

}
