	#include <bits/stdc++.h>
	using namespace std;
	int n,m;
	char habitacion[20][20];
	bool area[20][20];
	
	char girar(char c){
		if(c=='U'){
			return 'R';
		}
		if(c=='D'){
			return 'L';
		}
		if(c=='R'){
			return 'D';
		}
		if(c=='L'){
			return 'U';
		}
	}
	void imprimir(){
		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++){
				printf("%c ",habitacion[i][j]);
			}
			printf("\n");
		}
	}
	void run(int posi,int posj,char c,int max){
		area[posi][posj]=1;
		if(max<=0)return;
		//printf("%d %d %d %c\n",max ,posi,posj,c);
		if(c=='U'){
			while(habitacion[posi-1][posj]!='*'){
				max--;
				area[posi][posj]=1;
				posi--;
				
			}
			run(posi,posj,girar(c),max-1);
		}
		if(c=='D'){
			while(habitacion[posi+1][posj]!='*'){
				max--;
				area[posi][posj]=1;
				posi++;
				
			}
			run(posi,posj,girar(c),max-1);
		}
		if(c=='R'){
		
			while(habitacion[posi][posj+1]!='*'){
				max--;
				area[posi][posj]=1;
				posj++;
				
			}
			run(posi,posj,girar(c),max-1);
		}
		if(c=='L'){
			while(habitacion[posi][posj-1]!='*'){
				max--;
				area[posi][posj]=1;
				posj--;
				
			}
			run(posi,posj,girar(c),max-1);
			
		}
	}
	

	main(){
		scanf("%d%d",&n,&m);
		
		char d,c;
		memset(&area,0,sizeof(bool)*20*20);
		
		for(int i=0;i<m+2;i++){
			habitacion[0][i]='*';
			habitacion[n+1][i]='*';
		}
		for(int i=0;i<n+2;i++){
			habitacion[i][0]='*';
			habitacion[i][m+1]='*';
		}
		int posi,posj;
		for(int i=1;i<n+1;i++){
			for(int j=1;j<m+1;j++){
				c=getchar();
				if(c=='\n'||c==' '){
					j--;
					continue; 
				}
				else{
					if(c!='.'&&c!='*'){
						posi=i;
						posj=j;
						d=c;
					}
					habitacion[i][j]=c;
				}
			}
		}

		//imprimir();
		int var=20000;
		run(posi,posj,d,var);
	
		int resp=0;
		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++){
				area[i][j]?resp++:resp;
			}
		}
		printf("%d\n",resp);
	}
	