#include <bits/stdc++.h>
    using namespace std;

    int main(){
    	vector<int> votos;
  		int n,oso,vote,max,resp=0;
  		scanf("%d",&n);
  		scanf("%d",&oso);
  		for(int i=1;i<n;i++){
  			scanf("%d",&vote);
  			if(vote>=oso)
  				votos.push_back(vote);
  		}
  		if(votos.size()==0){
  			printf("%d\n",0);
  			return 0;
  		}
  		max=0;
  		while(true){
  			
	  		for(int i=0;i<votos.size();i++){
	  			if(votos[i]>votos[max])
	  				max=i;
	  		}
	  		if(oso>votos[max])break;
	  		oso++;
  			resp++;
  			votos[max]--;
  		}
  		printf("%d\n",resp);
    }
      