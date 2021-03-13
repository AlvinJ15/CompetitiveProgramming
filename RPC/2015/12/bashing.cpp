#include <bits/stdc++.h>
using namespace std;
int n;
int botones[30];
int memo[3605][3605];
main(){
	
	scanf("%d",&n);
	int presionar,tiempo;
	int a,min,max;
	while(n--){
		scanf("%d%d",&presionar,&tiempo);
		 memset(memo,0,sizeof(int)*3605*3605);
		for(int i=0;i<presionar;i++){
			scanf("%d",&botones[i]);
		}
		if(tiempo==0){
			printf("%d %d\n",0,0);
			continue;
		}
		for(int i=0;i<presionar;i++){
			a=botones[i];
			if(a<0)a=0;
			if(a>3600)a=3600;

			memo[0][a]=1;
		}
		for(int i=0;i<3601;i++){
			for(int j=0;j<3601;j++){

				if(memo[i][j]){
					for(int k=0;k<presionar;k++){
						a=j+botones[k];
						if(a>3600)a=3600;
						if(a<0)a=0;
						memo[i+1][a]=1;
						if(a==tiempo){
							j=8000;
							i=8000;
							break;
						}
					}
				}
			}
		}

		int i;
		for(i=tiempo;i<3601;i++){
			
			for(int j=0;j<3601;j++){
				if(i==tiempo && memo[j][i]){
					printf("%d %d\n",j+1,0);
					j=8000;
					i=8000;
					break;
				}
				if(memo[j][i]){
					printf("%d %d\n",j+1,i-tiempo);
					j=8000;
					i=8000;
					break;
				}
			}

		}
		if(i==3601){
			printf("%d %d\n",0,0);
		}
	}
}
