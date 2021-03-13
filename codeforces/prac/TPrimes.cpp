#include <bits/stdc++.h>
using namespace std;
long long size;
bitset<10000010> bs;
vector<int> primes;
void a(long long u){
	size = u+1;
	bs.set();
	bs[0]=bs[1]=0;
	for(long long i=2;i<=size;i++)if(bs[i]){
		for(long long j=i*i;j<=size ;j+=i)
			bs[j]=0;
		primes.push_back((int)i);
	}
}
bool isPrime(long long N){
	if(N<=size)return bs[N];
	for(int i=0;i<(int)primes.size();i++)
		if(!(N%primes[i]))return false;
	return true;
}

main(){
	int n,i;
	a(1000000);
	long long num;
	scanf("%d",&n);
	
		for(i=0;i<n;i++){
			cin>>num;

			if((long long)sqrt(num)*(long long)sqrt(num)==num && num!=1){
				printf(isPrime((long long)sqrt(num))?"YES\n":"NO\n");
				continue;
			}
			printf("NO\n");
		}
	

}
