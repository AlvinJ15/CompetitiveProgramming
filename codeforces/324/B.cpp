#include <stdio.h>                                                                                                                                             
#include <cstring>                                                                                                                                             
#include <cmath>                                                                                                                                               
#include <stdlib.h>                                                                                                                                            
#include <algorithm>                                                                                                                                           
#include <math.h>    
#include <vector> 

main(){
	int n,t,i;
	scanf("%d%d",&n,&t);
	if(n==1 && t==10){
		printf("%d\n",-1);
	}
	else{
		if(t!=10){
			printf("%d",t);
			for(i=0;i<n-1;i++){
				printf("0");
			}
			printf("\n");
		}
		else{
			printf("%d",1);
			for(i=0;i<n-1;i++){
				printf("0");
			}
			printf("\n");

		}
	}
	

	
}