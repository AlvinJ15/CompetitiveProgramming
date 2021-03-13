#include <bits/stdc++.h>
using namespace std;
main(){
	int a,b;
  while(scanf("%d%d",&a,&b),a!=-1){
    printf("%d\n",min((a-b+100)%100,(b-a+100)%100));
  }


}
