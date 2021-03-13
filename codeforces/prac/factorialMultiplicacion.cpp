	#include <bits/stdc++.h>
	using namespace std;
	map<long long,int> mapa;
	vector<long long> factoriales;
	bool esFactor(long long numero){

		bool var=false;
		//printf("%d\n",mapa[numero]);
		if(!mapa[numero]){
			if(numero==1){
				mapa[numero]=1;
				return true;
			}
			if(numero%2!=0){
				mapa[numero]=-1;
				return false;
			}
			
			for(int i=0;i<factoriales.size() && !var && factoriales[i]<=numero;i++){
				if(numero%factoriales[i]==0){
					var=var||esFactor(numero/factoriales[i]);
				}
				
			}
			if(var){
				mapa[numero]=1;
			}
			else
				mapa[numero]=-1;

			return var;
		}
		else{
			 if(mapa[numero]==1)
				return true;
			else 
				return false;
		}
		
	}
	main(){
		int n;
		int resp=0;
		long long numero;
		factoriales.push_back(2);
		for(int i=3;i<20;i++){
			factoriales.push_back(factoriales[i-3]*i);
		}
		for(int i=0;i<factoriales.size();i++)
			printf("%lld\n",factoriales[i]);
		scanf("%d",&n);
		while(n--){
			scanf("%lld",&numero);
			//mapa.clear();
			printf(esFactor(numero)?"YES\n":"NO\n");
		}
		long long a = pow(2,62);
		printf("%lld",a);
		

	}