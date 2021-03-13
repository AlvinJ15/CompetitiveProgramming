#include <cstring>
#include <cstdio>
#include <cmath>
#include <stdlib.h>

main(){
  int a,b,c,d,R;
  while(scanf("%d%d%d%d",&a,&b,&c,&d),a|b|c|d){
    R=0;
    R+=(a-b+40)%40;
    R+=(c-b+40)%40;
    R+=(c-d+40)%40;
    R*=9;
    printf("%d\n",R+1080);
  }

}
