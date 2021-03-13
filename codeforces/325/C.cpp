#include <bits/stdc++.h>
using namespace std;
int n;
int child[4005][3];
vector<int> att;
vector<int> ex;
bool m[4005];
bool m2[4005];

void imprimir(vector<int> a){
	for(int i=0;i<a.size();i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
void imprimirC(){
	for(int i=0;i<n;i++){
		printf("%d %d %d\n",child[i][0],child[i][1],child[i][2]);
	}
	printf("\n");
}
main(){

	int i,a,b,j;
	
	cin>>n;
	memset(&m,1,sizeof(bool)*n);
	memset(&m2,1,sizeof(bool)*n);
	for(i=0;i<n;i++)
		cin>>child[i][0]>>child[i][1]>>child[i][2];
	for(i=0;i<n;i++){
		if(m[i]){
				ex.clear();
				if(child[i][2]<0 &&m2[i]){
					ex.push_back(i);
					m2[i]=0;
				}
				else{
					att.push_back(i);
					b=child[i][0];

					for(j=i+1;b>0 && j<n;j++,b--){
						if(child[j][2]<0){
							b++;
							continue;
						}
						child[j][2]-=b;
					
						if(child[j][2]<0 &&m2[j]){
							ex.push_back(j);
							m2[j]=0;
							m[j]=0;
						}
					}
				}

				while(ex.size()){
					a=ex[0];
					ex.erase(ex.begin());
					for(j=a+1;j<n;j++){
						child[j][2]-=child[a][1];
						if(child[j][2]<0 && m2[j]){
							ex.push_back(j);
							m2[j]=0;
							m[j]=0;
						}

					}
				}
				
		}
	
		
		

	}
	printf("%d\n",att.size());
	for(i=0;i<att.size();i++){
		printf("%d ",att[i]+1);
	}
	printf("\n");
}

