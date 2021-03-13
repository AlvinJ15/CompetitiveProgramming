#include <bits/stdc++.h>
using namespace std;
main(){
	char rarity [4000];
	char c;
	bool a=true,b=true;
	int i=0;
	while((c=getchar())!=EOF){
		if(c=='"'){
			if(a){
				rarity[i++]='`';
				rarity[i++]='`';
				a=false;
			}
			else{
				rarity[i++]='\'';
				rarity[i++]='\'';
				a=true;
			}
		}
		else{
			rarity[i++]=c;
		}
	}
	printf("%s",rarity);
}
