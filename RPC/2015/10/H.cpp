#include <cstring>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
main(){

	int N,M=0,a,i=0,d=0,j=0,h;
	
	scanf("%d",&N);

	int nums[10];
	while(N!=0){
		a=N;
		M=0;
		j=0;
		memset(&nums,0,sizeof(int)*10);
		while(a!=0){
			d=a%10;
			nums[j++]=d;
			
			a/=10;
			
		}
		
		std::sort(nums, nums+sizeof(nums)/sizeof(int));
		for(h=0;h<10;h++){
			M=M*10+nums[h];
		}

		N-=M;
		i++;
	}
	printf("%d\n",i);




}