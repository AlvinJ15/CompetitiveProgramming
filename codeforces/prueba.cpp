#include <bits/stdc++.h>
using namespace std;
int memo[1005][1005];
int arr[1005];

int vacas(int suma,int i,int j){

		if(memo[i][j]!=0)return memo[i][j];

		if(i==j)return suma;
		if(i+1==j){
			memo[i][j]=suma+max(arr[i], arr[j]);
			return memo[i][j];
		}

		int a;
		int c;
		if(arr[i+1]>=arr[j]){
			a=arr[i]+vacas(suma,i+2,j);
		}
		else{
			a=arr[i]+vacas(suma,i+1,j-1);
		}

		if(arr[i]>=arr[j-1]){

			c=arr[j]+vacas(suma,i+1,j-1);
		}
		else{
			c=arr[j]+vacas(suma,i,j-2);
		}
		memo[i][j]=max(a,c);
		return memo[i][j];

}
main(){
	int total =1,n,suma;
	while(scanf("%d",&n),n){

		suma=0;
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
			suma+=arr[i];
		}

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				memo[i][j]=0;
		int resp=vacas(0,0,n-1);
		/*for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%d ",memo[i][j]);
			printf("\n");}
		printf("%d %d\n",n,resp);*/

		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",total++,resp-(suma-resp));
		}

	}




