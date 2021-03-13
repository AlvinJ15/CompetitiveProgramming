#include <bits/stdc++.h>
using namespace std;
int N;
int arr[201][3];
map < pair <int, vector<bool> > , int> mapa;
 //unordered_map<pair<int,bitset<200>>,int> mapa;

bool hayCamino(int i ,int j){
	double x =hypot(arr[i][0]-arr[j][0],arr[i][1]-arr[j][1]);

	if(x>arr[i][2]+arr[j][2])
		return true;
	else return false;
}
int recur(int indice,vector<bool> mask){
	if(indice==N)return 1;

	if(mapa[make_pair(indice,mask)])
		return mapa[make_pair(indice,mask)];

	for(int i=0;i<200;i++){
		if(mask[i])
			for(int j=i+1;j<200;j++){
				if(mask[j])
					if(hayCamino(i,j))
						continue;
					else{
						return -indice;
					}
			}
	}
	bitset<200> var (mask);
	bitset<200> var2 (mask);
	var2[indice]=0;
	var[indice]=1;
	return 1+max(recur(indice+1,var2),recur(indice+1,var));
	

}


int main(){

	scanf("%d",&N);
	for(int i=0;i< N ;i++){
		scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
	}
	bitset<200> mask;
	
	printf("%d\n",recur(0,mask));



}