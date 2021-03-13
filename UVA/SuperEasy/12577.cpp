#include <bits/stdc++.h>
using namespace std;
main(){
	char p[50];
  int cases=1;
  while(true){
    scanf("%50s",p);
    if(p[0]=='*')break;
    printf("Case %d: Hajj-e-",cases++);
    if(p[0]=='H')
      printf("Akbar\n");
    else
      printf("Asghar\n");
  }


}
