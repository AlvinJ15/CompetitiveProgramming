#include <cstring>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
main(){


	int N,S,J,D,i=0,A=0,B=0,rA=0,rB=0;

	scanf("%d%d%d%d",&N,&S,&J,&D);
	
	char arr[N];
	char c;

	while((c=getchar())!=EOF){
		if(c=='\n')continue;
		arr[i]=c;
		i++;
	}
	i=0;
	for(i=0;i<N;i++){
		
		arr[i]=='A'?A++:B++;
		
		if(abs(A-B)>=D){
			if(A>B){
				if(A>=J){rA++;
					A=0;
					B=0;
				};
			}
			if(B>A){
				if(B>=J){
					rB++;
					A=0;
					B=0;
				}
			}

		}
	}
	printf("%d %d\n",rA,rB);





}