#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000 
#define INF 500000000
bool isP[MAX_N+10] ;
long np, L, R;
vector<int> prime;

void Sieve(){
  memset ( isP , true , sizeof isP) ;
  long long i, j ;
  isP[0] = isP[1] = false ;
  for ( i  = 2 ; i <= MAX_N ; i++)
    if (isP[i]){
       prime.push_back(i); //cout<<i <<" ";
       for ( j = i*i ; j <= MAX_N ; j += i)
       isP[j] = false ;
    }
  np = prime.size();
}
bool isPrime(int n) {
    if (n<MAX_N) return isP[n];
    for (int i=0, lm=(int)sqrt(n); i<np && prime[i]<=lm; i++)
        if (n%prime[i]==0) return false;
    return true;
}

int nextPrime(long long u) {
    for (++u; u<=R; u++)
        if (isPrime(u)) return (int)u;
    return -1;
}

main() {
//    FileIn("test"); FileOut("test");
    Sieve();
    while (scanf("%ld %ld", &L, &R)!=EOF) {
        int maxim = 0, minim = INF, ax, ay, bx, by;
        int last = nextPrime(L-1), next;
        if (last!=-1) while (1) {
            next = nextPrime(last);
            if (next==-1) break;
            if (next-last > maxim) {
                maxim = next - last;
                ax = last; ay = next;
            }
            if (next-last < minim) {
                minim = next - last;
                bx = last; by = next;
            }
            last = next;
        }
        if (maxim==0) puts("There are no adjacent primes.");
        else printf("%d,%d are closest, %d,%d are most distant.\n", bx, by, ax, ay);
    }
}