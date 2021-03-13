#include <cstring>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
main(){
	int N,R,i=0,a,b,h=0,r=0,j;
	bool reco[1000001];
	int pos[1000001];
	
	char c;
	scanf("%d%d",&N,&R);
	int especies[N+1];
	int tam[N+1];
	memset(&reco,0,sizeof(bool) * 1000001);
	memset(&pos,0,sizeof(int) * 1000001);
	memset(&tam,0,sizeof(int)*(N+1));
	for(i=1;i<=N;i++){
		scanf("%d",&especies[i]);
		
		if(reco[especies[i]]){
			tam[i]=i-tam[pos[especies[i]]];

			pos[especies[i]]=i;
			
		}
		else{
			tam[i]=1+tam[i-1];
			pos[especies[i]]=i;
			reco[especies[i]]=1;
		}
		
	
	}
	
	while((c=getchar())!=EOF){
		if(c=='\n' || c==' ')continue;
			if(c=='C'){
				scanf("%d",&a);
				scanf("%d",&especies[a]);
				memset(&reco,a,sizeof(bool) * 1000001);
				memset(&pos,a,sizeof(int) * 1000001);
				memset(&tam,a,sizeof(int)*(N+1));
				for(i=a;i<=N;i++){
		
		
					if(reco[especies[i]]){
						tam[i]=i-tam[pos[especies[i]]];

						pos[especies[i]]=i;
						
					}
					else{
						tam[i]=1+tam[i-1];
						pos[especies[i]]=i;
						reco[especies[i]]=1;
					}
		
	
				}

			}
			if(c=='E'){
				j++;
				scanf("%d",&i);
			
				
			
				printf("%d\n",tam[i]);
			}
		if(j==R)break;
	}


}