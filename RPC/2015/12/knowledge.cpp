#include <bits/stdc++.h>
using namespace std;
int n;
long long arr[13];
map<pair<vector<long long>,int>,int> mymap;

int alumnos;
long long bit;
long long ceros=0;
long long fin,ini;
long long has[30];
long long resp;
long long r;
long long resp2;
vector<char> respuesta;
long long rasp(int total,int num){
	if(total==num)return 1;
	int alt=1;
	int asd=1;
	for(int i=total;i>num;i--){
		alt*=i;
	}
	for(int i=total-num;i>1;i--)
		asd*=i;
	return alt/asd;

}
long long toInt(const string &s)
{
    long long n = 0;

    for (long long i = 0; i < s.size(); i++) {
        n <<= 1;
        n |= s[i] - '0';
    }

    return n;
}
long long pop(long long x)
{

    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x = x + (x >> 8);
    x = x + (x >> 16);

    return x & 0x0000003F;
}

long long recur(long long p[],int tam,char letra){


	/*vector<long long> pr;
	for(int i=0;i<alumnos;i++)
		pr.push_back(p[i]);
	if(mymap[make_pair(pr,tam)]){
		printf("asdas\n");
		return mymap[make_pair(pr,tam)];
	}*/
	//else{
	if(tam==0)return 0;
	/*for(long long i=0;i<alumnos;i++){
		prlong longf("%lld ",p[i]);
	}
	prlong longf("\n");*/
	
	
	int k;

	for(int i=0;i<alumnos;i++){
		
		if(p[i]==tam){
			fin=arr[i];
			
			for(k=0;k<alumnos;k++){
				
				//if(fin==arr[k])continue;
				
				if(pop((~(fin)&has[tam-1])^(arr[k]&has[tam-1]))!=p[k])
					return 0;
			}
			if(k==alumnos){

				resp2=(fin)&has[tam-1];

				return 1;
			}

		}
		if(p[i]==0){
			ini=arr[i];

			for(k=0;k<alumnos;k++){
				
				//if(ini==arr[k])continue;
				//prlong longf("%lld\n",ini);
				//prlong longf("%lld ",pop((ini)&has[tam-1]^(arr[k]&has[tam-1])));
				if(pop((ini)&has[tam-1]^(arr[k]&has[tam-1]))!=p[k])
					return 0;
			}

			if(k==alumnos){

				resp2=(~ini)&has[tam-1];

				return 1;
			}
		}
	}
	
	long long p2[alumnos];
	bit=1<<tam-1;
	for(int i=0;i<alumnos;i++)
		p2[i]=p[i];
	for(int i=0;i<alumnos;i++){

		if(!(arr[i]&bit)){
			p[i]--;
		}
	}

	
	
	
	for(int i=0;i<alumnos;i++){
		if(arr[i]&bit){
			p2[i]--;
		}
	}
	respuesta.push_back(letra);

	resp=recur(p,tam-1,'0')+recur(p2,tam-1,'1');
	if(resp==0)
		respuesta.pop_back();
	//mymap.insert(make_pair(make_pair(pr,tam),resp));
	return resp;

	//}

}


main(){
	int preguntas;
	scanf("%d",&n);
	for(int i=1;i<31;i++){
		has[i-1]=(1<<i)-1;
	}

	char * ptr;
  	long long num;
  	int abc=0;
  	int rarity;
	while(n--){
		abc=0;
		scanf("%d%d",&alumnos,&preguntas);
		long long p[30];
		string line;

		respuesta.clear();
		for(int i=0;i<alumnos;i++){
			cin>>line;


			scanf("%lld",&p[i]);
			for(rarity=0;rarity<i;rarity++){
				if(arr[rarity]==toInt(line)){
					break;
				}
			}
			if(rarity==i)
				arr[abc++]=toInt(line);
		}
		alumnos=abc;
		if(alumnos==1){
			r=rasp(preguntas,p[0]);
			if(r==1){
				if(p[0]==preguntas){
					int par=arr[0];
					for(int l=0;l<preguntas;l++){
						if(par&1){
							respuesta.push_back('1');
						}
						else
							respuesta.push_back('0');
						par>>=1;
					}
				}
				if(p[0]==0){
					int par=~arr[0];
					for(int l=0;l<preguntas;l++){
						if(par&1){
							respuesta.push_back('1');
						}
						else
							respuesta.push_back('0');
						par>>=1;
					}
				}
				reverse(respuesta.begin(),respuesta.end());
				for(long long i=0;i<respuesta.size();i++)
    			printf("%c",respuesta[i]);
				printf("\n");
			}
			else
				printf("%lld solutions\n",r);
			continue;
		}

		r=recur(p,preguntas,'0');

		if(r==1){
			vector<char> respaldo;
			
			while (resp2) {
  				if (resp2 & 1)
    	   			respaldo.push_back('1');
   				else
    		    	respaldo.push_back('0');

    				resp2 >>= 1;
			}
		
			if(respuesta.size()>0)
				respuesta.erase(respuesta.begin()+0);
			
			reverse(respaldo.begin(),respaldo.end());
			reverse(respuesta.begin(),respuesta.end());

    		long long b=preguntas-(respuesta.size()+respaldo.size());

    		for(long long i=0;i<respuesta.size();i++)
    			printf("%c",respuesta[i]);
    		for(long long i=0;i<b;i++)
    			printf("%c",'0');
    		for(long long i=0;i<respaldo.size();i++)
    			printf("%c",respaldo[i]);
    		printf("\n");
		}
		else{
			printf("%lld solutions\n",r);
		}
	}
}
