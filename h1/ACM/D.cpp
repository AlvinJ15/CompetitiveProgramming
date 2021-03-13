	#include <bits/stdc++.h>
	using namespace std;
	int arr[1007][4];
	int t1,s1,f1,t2,s2,f2,d1,d2;
	int encuentro(int i,int j){

		int tiempo;
		t1=arr[i][0];
		s1=arr[i][1];
		f1=arr[i][2];
		d1=arr[i][3];
		t2=arr[j][0];
		s2=arr[j][1];
		f2=arr[j][2];
		d2=arr[j][3];
		int fluttershy;
		int rarity;
		tiempo=abs(t1-t2);
		if(tiempo){
			if(t1<t2){
			
				if(d1==0){
					s1+=tiempo;
					if(s1>f1)
						return 0;
				}
				else{
					s1-=tiempo;
					if(s1<f1)
						return 0;
				}
			}else{
				if(d2==0){
					s2+=tiempo;
					if(s2>f2)
						return 0;
				}
				else{
					s2-=tiempo;
					if(s2<f2)
						return 0;
				}
			}

		}
		
			if(s1==s2)return 1;
			if(d1==d2)return 0;
			if(s1<s2 && d1==1 && d2==0)return 0;
			if(s1>s2 && d1==0 && d2 ==1)return 0;
		
			if(s1<s2){
				if(f1 < f2)return 0;
			} 
			if(s2<s1){
				if(f2<f1)return 0;
			}
			//printf("%d %d\n",fluttershy,rarity);
			fluttershy = abs(f1-s1);
			rarity = abs(f2-s2);
				if(fluttershy==rarity)
					return 1;

			int var =min(fluttershy,rarity);
			int pinkie,twilight;
			if(s1<s2){
				if(fluttershy>rarity){
					pinkie=s1+var;
					if(pinkie<f2){
						return 0;
					}
					else return 1;
				}
				else{
					pinkie=s2-var;
					if(pinkie>f1)
						return 0;
					else 				return 1;
				}
			}
			if(s1>s2){
				if(fluttershy>rarity){
					pinkie=s1-var;
					if(pinkie>f2){
						return 0;
					}
					else return 1;
				}
				else{
					pinkie=s2+var;
					if(pinkie<f1)
						return 0;
					else return 1;

				}
			}
		
		
			return 1;
	}
	main(){

		int n;
		int resp;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
			arr[i][3]=(arr[i][1]<arr[i][2]?0:1);
		}
		for(int i=0;i<n;i++){
			resp=0;
			for(int j=0;j<n;j++){
				if(i==j)continue;
				if(encuentro(i,j))
					resp++;
				/*if(encuentro(i,j)){
					printf("Si chocan %d %d\n",i,j);
				}
				else
					printf("No chocan %d %d\n",i,j);*/
			}
			printf("%d ",resp);
		}

	}
	