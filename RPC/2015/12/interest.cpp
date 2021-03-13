#include <bits/stdc++.h>
using namespace std;
	int fibo[45];
	long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
	int lcm(int a,int b){return a*(b/gcd(a,b));}
	long long x,y,d,fluttershy=3,twilight=1,p,q;
	void extendedEuclid(int a,int b){
		if(!b){x=1;y=0;d=a;return;}
		extendedEuclid(b,a%b);
		long long x1=y;
		long long y1=x-(a/b)*y;
		x=x1;
		y=y1;
	}
	void diophantic(int a,int b,int r){
		fluttershy=-90;
		twilight=-900;
		if(a+b>r)
			return;
		extendedEuclid(a,b);

		int divisor=gcd(a,b);
		int multiplicar=r/divisor;
		x*=multiplicar;
		y*=multiplicar;
		vector<int> respuestas;
		double rango1=min(-(double)x/((double)b/(double)d),(double)y/((double)a/(double)d));
		double rango2=max((double)-x/((double)b/(double)d),(double)y/((double)a/(double)d));
		int n;

		int inicio,fin;
		int m;
			inicio=(long long)ceil(rango1);
			fin=(long long)floor(rango2);
			while(inicio<=fin){
				m=(inicio+fin)/2;
				p=x+(b/d)*m;
				q=y-(a/d)*m;
				if(p>q){
					fin=m-1;
				}
				else{
					inicio=m+1;
					fluttershy=p;
					twilight=q;
				}

			}

	}

		void fibon(int n){
			int arr[n+1];
			fibo[0]=1;
			fibo[1]=1;
			for(int i=2;i<=n;i++){
				fibo[i]=fibo[i-1]+fibo[i-2];
			}
			
				
		}
		int main(){
			
			
			int n,numero ;
			scanf("%d",&n);
			
			int var,final;
			fibon(44);
			int a=100000000,b=100000000;
			for(int o=0;o<n;o++){
				a=100000000,b=100000000;
				scanf("%d",&numero);
				for(int i=0;i<44;i++){
					diophantic(fibo[i],fibo[i+1],numero);
					if(fluttershy<=twilight&&twilight<b && fluttershy>0&&twilight>0){
						b=twilight;
						a=fluttershy;
					}
					if(fluttershy<=twilight&&twilight==b&&fluttershy>0&&twilight>0){
						if(fluttershy<a)
							a=fluttershy;
					}
				}
	
				printf("%d %d\n",a,b);
				
			}
		
		}

			
	
		
		
	



