#include <bits/stdc++.h>
using namespace std;
int a[100],b[100];
int n;
int dist[100];
int sumar(int k){
	int sum=0,j,i;
	
		for(j=0;j<k;j++){
			sum+=a[j];

		}
		for(j=k;j<n-1;j++){
			sum+=b[j];
			//printf("%d ",b[j]);
		}
		sum+=dist[k];
	return sum;
}
main(){
	int i,j;
	int est=1,resp=0;;
	scanf("%d",&n);
	
	for(i=0;i<n-1;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		scanf("%d",&b[i]);
	}
	int sumA=1<<30,sumB=1<<30;

	for(i=0;i<n;i++){
		scanf("%d",&dist[i]);
	}
	for(i=0;i<n;i++){
		//printf("%d\n",sumar(i));
		if(sumA>sumar(i)){
			j=i;
			sumA=sumar(i);
		}
	}
	dist[j]=1<<30;
	for(i=0;i<n;i++){

		if(sumB>sumar(i)){
			j=i;
			sumB=sumar(i);
		}
	}
	printf("%d\n",sumA+sumB);
}
