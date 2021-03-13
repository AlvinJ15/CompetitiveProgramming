#include <cstring>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
main(){
	int a,b,c,d;
	scanf("%d%d",&a,&b);
	d=abs(a-b)/2;
	printf("%d %d\n",std::min(a,b),d);
}