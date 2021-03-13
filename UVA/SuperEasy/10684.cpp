#include <bits/stdc++.h>
using namespace std;
main(){
	int n;
	int sum,ans,num;
	while(scanf("%d",&n),n){
		sum =0,ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&num);
			sum+=num;

			ans=max(ans,sum);
			if(sum<0)sum=0;
		}

		printf(ans>0?"The maximum winning streak is %d.\n":"Losing streak.\n",ans);
	}

}