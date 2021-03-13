#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j;
	int est=1,resp=0;;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++){
		if(arr[i]==1){
			break;
		}
	}
	for(j=n-1;j>=0;j--){
		if(arr[j]==1){
			break;
		}
	}
	for(i;i<=j;i++){
		if(est){
			if(arr[i]==1){
				resp++;
			}
			else{
				if(arr[i+1]==0){
					est=0;
					continue;
				}
				resp++;
			}
		}
		else{
			if(arr[i]==1){
				resp++;
				est=1;
			}
		}
	}
	printf("%d\n",resp);
}