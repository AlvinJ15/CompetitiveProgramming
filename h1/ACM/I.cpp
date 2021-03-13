	#include <bits/stdc++.h>
	using namespace std;
	int n,b;
	main(){

		int arr[107];
		int arr2[107];

		scanf("%d%d",&n,&b);

		int bolas[n];
		int num=n/b;
		int resp=0;
		memset(&arr,0,sizeof(int)*107);
		memset(&arr2,0,sizeof(int)*107);
		for(int i=0;i<n;i++){
			scanf("%d",&bolas[i]);
			arr[bolas[i]]++;
		}
		
		int j=0,a=0;
		sort(arr,arr+sizeof(arr)/sizeof(int));
		sort(arr2,arr2+sizeof(arr2)/sizeof(int));
		
		for(int i=106;i>=0;i--){
			if(arr[i]==0)continue;
			else{
				if(arr[i]>num){
					a+=arr[i]-num;
					resp+=arr[i]-num;
					arr[i]-=arr[i]-num;
				}
				if(arr[i]<num){
					while(a>0 && arr[i]<num){
						arr[i]++;
						a--;
					}
				}
			}
		}


		for(int i=0;i<107&& arr[i]<num ;i++){
			if(arr[i]==0)continue;
			a=arr[i];
			resp+=a;
			arr[i]=0;
			for(int j=106;j>=0 && a>0;j--){
				if(arr[j]==num)continue;
				while(a>0 && arr[j]<num){
					arr[j]++;
					a--;
				}
			}
		}
		

		printf("%d\n",resp);



	}