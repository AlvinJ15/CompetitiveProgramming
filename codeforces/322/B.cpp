#include <cstring>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
main(){
	int n,max;
	scanf("%d",&n);
	int arr[n];
	int arr2[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	arr2[n-1]=0;
	max=arr[n-1];
	for(int i=n-2;i>=0;i--){
		
		arr[i]<=max?arr2[i]=max-arr[i]+1:arr2[i]=0;
		max<arr[i]?max=arr[i]:max=max;
	}
	for(int i=0;i<n;i++){
		printf("%d ",arr2[i]);
	}


}