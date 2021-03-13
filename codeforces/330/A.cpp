#include <bits/stdc++.h>
using namespace std;
int N;


int main(){

	int n, m;
	scanf("%d%d",&n,&m);
	int a,b;
	int resp=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d%d",&a,&b);
			if(a||b)
				resp++;

		}
	}
	printf("%d\n",resp);


}