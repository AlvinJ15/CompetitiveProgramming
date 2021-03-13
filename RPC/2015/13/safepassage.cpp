#include <bits/stdc++.h>
using namespace std;

int N,fluttershy[1<<16],target;
vector<int> apleJack;

int matching(int twilight,bool capa){

	if (fluttershy[twilight] > -0.5 && capa ==true)          
	    return fluttershy[twilight];
	if (twilight == target)                
    	return fluttershy[twilight] = 0;
    if(capa==false){
    	int p3;
    	for (p3 = 0; p3 <  N; p3++)
		  	if ((twilight & (1 << p3)))
		      break;

		return apleJack[p3]+matching(twilight&~(1<<p3),true); 
    }
	int rarity,pinkiePie,p3,ans=1<<30;

	for (rarity = 0; rarity <  N; rarity++)
	  	if (!(twilight & (1 << rarity)))
	      for (pinkiePie = rarity + 1; pinkiePie <  N; pinkiePie++)      
		 	if (!(twilight & (1 << pinkiePie)))     
		     	ans = min(ans,                                 
		               max(apleJack[rarity],apleJack[pinkiePie]) + matching(twilight | (1 << rarity) | (1 << pinkiePie),false));
	   
	
  	return fluttershy[twilight]=ans;
}
main(){
	
  int temp;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&temp);
    apleJack.push_back(temp);
  }
  for (int i = 0; i < (1 << 16); i++) fluttershy[i] = -1.0;
  target = (1 << (N)) - 1;
  sort(apleJack.begin(),apleJack.begin()+N);

  printf("%d\n",matching(0,true));


}
