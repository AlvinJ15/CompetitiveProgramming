#include <stdio.h>                                                                                                                                             
#include <cstring>                                                                                                                                             
#include <cmath>                                                                                                                                               
#include <stdlib.h>                                                                                                                                            
#include <algorithm>                                                                                                                                           
#include <math.h>    
#include <vector> 
long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}

main(){
	int cas=1;
	long long v1,d1,v2,d2;
	long long a,b,c;
	while(scanf("%lld%lld%lld%lld",&v1,&d1,&v2,&d2),(v1||d1||v2||d2)){
		if(d1*v2<d2*v1){
			printf("Case #%d: You owe me a beer!\n",cas++);
			
		}
		else{
			printf("Case #%d: No beer for the captain.\n",cas++);
			
		}
		a=d1*v2 + d2*v1;
		b=v1*v2*2;
		c=gcd(a,b);
		a/=c;
		b/=c;
		if(b==1){
				printf("Avg. arrival time: %lld\n",a);
		}
		else{

			printf("Avg. arrival time: %lld/%lld\n",a,b);
		}



	}



}
