#include <stdio.h>                                                                                                                                             
#include <cstring>                                                                                                                                             
#include <cmath>                                                                                                                                               
#include <stdlib.h>                                                                                                                                            
#include <algorithm>                                                                                                                                           
#include <math.h>    
#include <vector> 
int arr[100][100];
int ant=0;
std::vector<int> myVector;
void recursion(int n,int m);
int r2(int i,int m){
	int count=0;
	while(myVector.size()){		
		recursion(myVector[0],m);
		count ++;
	}
	return count;
}
int choque2(int i,int m){
	int k=0,j,a;
	
	while(k<myVector.size()&&myVector.size()!=0){
		a=myVector[k];
		
		for(j=0;j<m;j++){
			if(arr[i][j]&arr[a][j]){
				//myVector.erase(std::remove(myVector.begin(), myVector.end(), a), myVector.end());
				k--;
				return 1;
			}
		}
		k++;
		
	}
	return 0;

	
}  

void imprimir(){
	int i=0;
	printf("arr: ");
	for(i=0;i<myVector.size();i++){
		printf("%d ",myVector[i]);
	}
	printf("\n");
}
void imprimir2(){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}
}

void choque(int i,int m){
	int k=0,j,a;
	//printf("choque %d\n",i);
	//imprimir();
	//printf("condicion: %d\n",choque2(i,m));
	while( choque2(i,m)&&k<myVector.size()&&myVector.size()!=0){
		a=myVector[k];
		
		for(j=0;j<m;j++){
			if(arr[i][j]&arr[a][j]){
				//myVector.erase(std::remove(myVector.begin(), myVector.end(), a), myVector.end());
				k--;
				//printf("%d %d\n",i,a);
				
				recursion(a,m);
				break;
				
				
				
			}
		}
		k++;
	}
	
	return;
}  
void recursion(int a,int m){
	if(myVector.size()!=0){
		//printf("eliminado r: %d\n",a);
		myVector.erase(std::remove(myVector.begin(), myVector.end(), a), myVector.end());		
		choque(a,m);
	}

}
                                                                                                                                
                      
main(){
	int n,m;
	int a,i,minimo=0,l,j,inter=0;
	
	scanf("%d%d",&n,&m);
	
	memset(&arr,0,sizeof(arr[0][0])*10000);
	
	for(i=0;i<n;i++){
		scanf("%d",&l);
		
		if(l==0){

			minimo++;
			
		}
		else{
			myVector.push_back(i);
		}
		for(j=0;j<l;j++){
			scanf("%d",&a);
			
			arr[i][a-1]=1;

		}
		
	}
	if(myVector.size()){
		//imprimir2();
		//imprimir();

	inter=r2(myVector[0],m);

	
	}
	if(inter!=0){
		inter=inter-1;
	}
	printf("%d\n",minimo+inter);
}
