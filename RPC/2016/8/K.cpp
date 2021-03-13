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
		extendedEuclid(a,b);
		int divisor=gcd(a,b);
		int multiplicar=r/divisor;
		x*=multiplicar;
		y*=multiplicar;
		vector<int> respuestas;
    bool r1,r2;
    r1=r2=true;
    double rango1= (1-(double)x)/(double(b)/double(d));
    double rango2= ((double)y-1)/((double)a/double(d));
		int inicio,fin;
    if(b*d<0){
      r1=false;
    }
    if(a*d<0){
      r2=false;
    }

    if(r1^r2){
      if(r1){
        inicio=ceil(max(rango1,rango2));
      }
      else{
        inicio=floor(min(rango1,rango2));
      }
    }
    else{
      double temp = rango1;
      rango1=min(rango1,rango2);
      rango2=max(rango2,temp);
      inicio=ceil(rango1);
    }
	//	double rango1=min(-(double)x/((double)b/(double)d),(double)y/((double)a/(double)d));
	//	double rango2=max((double)-x/((double)b/(double)d),(double)y/((double)a/(double)d));
		/*iniciaaaaaaaao=(long long)ceil(rango1);
		fin=(long long)floor(rango2);*/
	//	for(int inicio=rango1;inicio>=rango2;inicio--){
			p=x+(b/d)*inicio;
			q=y-(a/d)*inicio;
			cout<<p<<" "<<q<<endl;
	//	}
		/*int m;
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

			}*/

	}
main(){
  int test;
  cin>>test;
  int R,S,Q;
  while(test--){
    scanf("%d%d%d",&R,&S,&Q);
    diophantic(R,S,Q);
  }
}
