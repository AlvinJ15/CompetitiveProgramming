#include <bits/stdc++.h>
using namespace std;
	int fibo[45];
	long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
	int lcm(int a,int b){return a*(b/gcd(a,b));}
	long long x,y,d,respuestaX=3,respuestaY=1,p,q;
	void extendedEuclid(int a,int b){
		if(!b){x=1;y=0;d=a;return;}
		extendedEuclid(b,a%b);
		long long x1=y;
		long long y1=x-(a/b)*y;
		x=x1;
		y=y1;
	}
	//ecuacion aX+aY=r
	void diophantic(int a,int b,int r){
		//respuestas X y Y
		respuestaX=-90;
		respuestaY=-900;
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
		//valores de n redondeados a entero
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
					respuestaX=p;
					respuestaY=q;
				}

			}
			
		
		
	}
main(){
	diophantic(377,610,1573655);
	printf("%lld %lld\n",var1,var2);
	
}
