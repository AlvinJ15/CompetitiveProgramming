	#include <bits/stdc++.h>
	using namespace std;

	main(){
		int n,min=1<<30;
		int resp=0;
		scanf("%d",&n);
		int arr[n][2];
		for(int i=0;i<n;i++){
			scanf("%d%d",&arr[i][0],&arr[i][1]);
			min=min<arr[i][1]?min:arr[i][1];
			resp+=min*arr[i][0];
		}
		printf("%d\n",resp);

	}