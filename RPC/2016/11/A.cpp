#include <bits/stdc++.h>
using namespace std;
main(){
  int A,B,C;
  while(scanf("%d%d%d",&A,&B,&C)!=EOF){
    if(A==B || B==C || A==C){
      printf("S\n");continue;
    }
    if(A==B+C || B==A+C || C==A+B){
      printf("S\n");continue;
    }
    printf("N\n");
  }


}
