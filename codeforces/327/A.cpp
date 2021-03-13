	#include <bits/stdc++.h>
	using namespace std;

	main(){
		int tam,p,q;
		double resp;
		scanf("%d%d%d",&tam,&p,&q);
		resp= (double)tam/(p+q);
		resp*=p;

		printf("%.4f\n",resp);

	}