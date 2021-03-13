	#include <bits/stdc++.h>
	using namespace std;

	main(){
		int rarity,aplejack;
		string palabra;
		scanf("%d%d",&rarity,&aplejack);
		cin>>palabra;
		char fluttershy[26];
		char pinkiePie='a',twilight;
		for(int i=0;i<26;i++){
			fluttershy[i]=pinkiePie++;
		}
		for(int i=0;i<aplejack;i++){
			scanf(" %c %c",&pinkiePie,&twilight);
			for(int j=0;j<26;j++){
				if(fluttershy[j]==pinkiePie){						
					fluttershy[j]=twilight;
					continue;
				}
				if(fluttershy[j]==twilight){
					fluttershy[j]=pinkiePie;					
				}
			}

		}		
		for(int i=0;i<rarity;i++){
			printf("%c",fluttershy[palabra[i]-'a']);
		}
		printf("\n");


	}