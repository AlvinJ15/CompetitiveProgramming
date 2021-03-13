	#include <bits/stdc++.h>
	using namespace std;
	string rarity[8];
	bool si(int i,int j,char c){
		

		if(c=='W'){
			i--;
			while(i>=0){
				if(rarity[i][j]=='.'){
					i--;
				}
				else break;
			}
			if(i==-1)return true;
		}
		else{
			i++;
			while(i<8){
				if(rarity[i][j]=='.'){
					i++;
				}
				else break;
			}
			if(i==8)return true;
		}
		return false;
	}
	main(){
		int fluttershy,pinkiePie;
		for(int i=0;i<8;i++)
			cin>>rarity[i];

		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++){
				if(rarity[i][j]=='W'){
					
					if(si(i,j,'W')){
						
						fluttershy=i;
						i=8;
						break;
					}
				}
		}
		for(int i=7;i>=0;i--)
			for(int j=0;j<8;j++){
				if(rarity[i][j]=='B'){
					if(si(i,j,'B')){
						pinkiePie=i;
						i=-1;
						break;
					}
				}
		}
		if(fluttershy==7-pinkiePie)
			printf("A\n");
		else{
			printf(fluttershy<7-pinkiePie?"A\n":"B\n");
		}
		
	}